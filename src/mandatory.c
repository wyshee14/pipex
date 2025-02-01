# include "../include/pipex.h"

void error_and_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void free_2d(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char *access_path(char **env_path, char *add_path)
{
    int i;
    char *cmd_path;

    i = 0;
    while (env_path[i])
    {
        cmd_path = ft_strjoin(env_path[i], add_path);
        if (access(cmd_path, F_OK) == 0)
            break ;
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }
    return (cmd_path);  
}

char *fetch_path(char *cmd, char ** env)
{
    int i;
    char **env_path;
    char *add_path;
    char *path;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            env_path = ft_split(env[i] + 5, ':');
            break ;
        }
        i++;
    }
    if (env_path == NULL)
        return (NULL);
    add_path = ft_strjoin("/", cmd);
    path = access_path(env_path, add_path);
    free_2d(env_path);
    free(add_path);
    return(path);
}

void execute_command(char *cmd, char **env)
{
    char **args;
    char *path;

    args = ft_split(cmd, ' ');
    path = fetch_path(args[0], env);
    // printf("%s\n", path);
    if (!path)
    {
        free_2d(args);
        error_and_exit("Command not found.\n");
    }
    if ((execve(path, args, env)) == -1)
        error_and_exit("Execve error.\n");
}

void child_process1(char **av, char **env, int *fd)
{
    int infile;
    pid_t pid1;
    int status;

    pid1 = fork();
    if (pid1 < 0)
        error_and_exit ("Fork 1 error!\n");
    if (pid1 == 0)
    {
        close (fd[0]);
        infile = open(av[1], O_RDONLY);
        if (infile == -1)
            error_and_exit("Failed to open infile.\n");
        dup2(infile, STDIN_FILENO);
        close(infile);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execute_command(av[2], env);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close (fd[1]);
        waitpid(pid1, &status, 0);
    }
}

void child_process2(char **av, char **env, int *fd)
{
    int outfile;
    pid_t pid2;
    int status;

    pid2 = fork();
    if (pid2 < 0)
        error_and_exit("Fork 2 error! \n");
    if (pid2 == 0)
    {
        close(fd[1]);
        outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
        if (outfile == -1)
            error_and_exit("Failed to open outfile.\n");
        dup2(outfile, STDOUT_FILENO);
        close(outfile);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execute_command(av[3], env);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close (fd[0]);
        waitpid(pid2, &status, 0);
    }
}

int main (int ac, char **av, char **env)
{
    int fd[2];

    if(ac != 5)
        error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2\n");
    if (pipe(fd) == -1)
        error_and_exit("Pipe error\n");
    child_process1(av, env, fd);
    child_process2(av, env, fd);
    exit(EXIT_SUCCESS);
}

// Input Redirection with dup2(infile, STDIN_FILENO)
// Output Redirection with dup2(pipefd[1], STDOUT_FILENO)
// anything cmd1 writes to standard output will go into the pipe.