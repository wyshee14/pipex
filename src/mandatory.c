# include "../include/pipex.h"

void child_process1(char **av, char **env, int *fd)
{
    int infile;
    pid_t pid1;

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
        wait(NULL);
    }
}

void child_process2(char **av, char **env, int *fd)
{
    int outfile;
    pid_t pid2;

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
        wait(NULL);
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
// exit success (returns 0), exit failure (returns != 0)
