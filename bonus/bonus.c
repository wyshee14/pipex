/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:22 by wshee             #+#    #+#             */
/*   Updated: 2025/02/05 21:20:05 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void child_process1(char **av, char **env, int *fd, t_pipex *data)
{
    pid_t pid1;

    if (pipe(fd) == -1)
        error_and_exit("Pipe error\n");
    pid1 = fork();
    if (pid1 < 0)
        error_and_exit ("Fork 1 error!\n");
    if (pid1 == 0)
    {
        close (fd[0]);
        dup2(data->infile, STDIN_FILENO);
        close(data->infile);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execute_command(av[data->cmd_index], env);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close (fd[1]);
        wait(NULL);
    }
}

void dup2_input(t_pipex *data, int **pipefd, int i)
{
	if (i == 0)
	{
		printf("dup2 input\n");
		dup2(data->infile, STDIN_FILENO);
		close(data->infile);
	}
	else
	{
		dup2(pipefd[i - 1][0], STDIN_FILENO);
		close(pipefd[i - 1][0]);
	}
}

void dup2_output(t_pipex *data, int **pipefd, int i)
{
	if (i == data->cmd_count - 1)
	{
		printf("dup2 output\n");
		dup2(data->outfile, STDOUT_FILENO);
		close(data->outfile);
	}
	else
	{
		dup2(pipefd[i][1], STDOUT_FILENO);
		close(pipefd[i][1]);
	}
}

void create_child_process(char *cmd, char **env, t_pipex *data, int **pipefd, int i)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
        error_and_exit("Fork error! \n");
    if (pid == 0)
    {
        dup2_input(data, pipefd, i);
        dup2_output(data, pipefd, i);
		for (int j = 0; j < data->cmd_count - 1; j++)
        {
            close(pipefd[j][0]);
            close(pipefd[j][1]);
        }
		// close(pipefd[i][0]);
        // close(pipefd[i][1]);
        execute_command(cmd, env);
        exit(EXIT_SUCCESS);
    }
    else //parent process
    {
        if (i > 0)
			close(pipefd[i - 1][0]);
        close(pipefd[i][1]);
        wait(NULL);
    }
}

void child_process2(char *cmd, char **env, int *fd, t_pipex *data)
{
    pid_t pid2;

    pid2 = fork();
    if (pid2 < 0)
        error_and_exit("Fork 2 error! \n");
    if (pid2 == 0)
    {
        close(fd[1]);
        dup2(data->outfile, STDOUT_FILENO);
        close(data->outfile);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        execute_command(cmd, env);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close (fd[0]);
        wait(NULL);
    }
}

int **init_pipes(t_pipex *data, int **pipefd)
{
    int i;

	// Allocate memory for pipefd
    pipefd = (int **)malloc((data->cmd_count - 1) * sizeof(int *));
    if(!pipefd)
        error_and_exit("Pipe error\n");
    i = 0;
    printf("Initializing pipes\n");
    while (i < data->cmd_count - 1)
    {
        pipefd[i] = (int *)malloc(2 * sizeof(int));
        if(pipe(pipefd[i]) == -1)
            error_and_exit("Pipe error\n");
        i++;
    }
	return(pipefd);
}

void	open_files(t_pipex *data, int ac, char **av)
{
	if (data->is_heredoc == 1)
		data->infile = open(".tmp", O_RDONLY);
	else if (data->is_heredoc == 0)
		data->infile = open(av[1], O_RDONLY);
	//printf("infile fd: %d\n", data->infile);
    if (data->infile == -1)
        error_and_exit("Failed to open infile.\n");
    data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
    //printf("outfile fd: %d\n", data->outfile);
    if (data->outfile == -1)
        error_and_exit("Failed to open outfile.\n");
}

// get next line will extract the line and
// appended via write function to pipe write end
// until limiter is found
void ft_here_doc(int ac, char *limiter, t_pipex *data)
{
	char *input;
	(void)ac;

	data->infile = open(".tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->infile == -1)
		error_and_exit("No such file or directory\n");
	while (1)
	{
		ft_putstr_fd("heredoc > ", 1);
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(limiter)) == 0)
		{
			free(input);
			break ;
		}
		write(data->infile, input, ft_strlen(input));
		free(input);
	}
	close(data->infile);
}

void	handle_input(int ac, char **av, t_pipex *data)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			error_and_exit("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n");
		data->is_heredoc = 1;
        data->cmd_index = 3;
		data->cmd_count = ac - 4;
		if (!av[2] || av[2][0] == '\0')
			error_and_exit("Error: No delimiter is found\n");
		ft_here_doc(ac, av[2], data);
	}
	else
	{
		data->cmd_index = 2;
        data->cmd_count = ac - 3;
	}
}

void init_data(t_pipex *data)
{
    data->infile = 0;
    data->outfile = 0;
    data->is_heredoc = 0;
    data->cmd_index = 0;
    data->cmd_count = 0;
    data->pipe_count = 0;
}

int main (int ac, char **av, char **env)
{
    t_pipex data;
    int **pipefd = NULL;
    (void)env;
    int i;

    if(ac < 5)
        error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2\n");
    init_data(&data);
    handle_input(ac, av, &data);
    open_files(&data, ac, av);


    pipefd = init_pipes(&data, pipefd);
	printf("Pipe Initialized done\n");
    //child_process1(av, env, fd, &data);
    i = 0;
    while (i < data.cmd_count)
    {
        printf("i:%d, cmd_index:%d, cmd_count: %d\n", i, data.cmd_index, data.cmd_count);
		create_child_process(av[data.cmd_index], env, &data, pipefd, i);
        i++;
		data.cmd_index++;
    }
	free_2d((void **)pipefd);
    //child_process2(av[ac-2], env, pipefd, &data);
    unlink(".tmp");
    exit(EXIT_SUCCESS);
}
