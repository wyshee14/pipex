/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:22 by wshee             #+#    #+#             */
/*   Updated: 2025/02/11 16:58:17 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex_bonus.h"

void create_child_process(char *cmd, char **env, t_pipex *data, int i)
{
    //pid_t pid;
	int i;

    pid = fork();
    if (pid < 0)
        error_and_exit("Fork error! \n", data);
    if (pid == 0)
    {
        dup2_input(data, data->pipefd, i);
        dup2_output(data, data->pipefd, i);
		for (int j = 0; j < data->cmd_count - 1; j++)
        {
            close(data->pipefd[j][0]);
            close(data->pipefd[j][1]);
        }
		execute_command(cmd, env, data);
        exit(EXIT_FAILURE);
    }
    else //parent process
    {
        if (i > 0)
			close(data->pipefd[i - 1][0]);
		if (i < data->cmd_count - 1)
        	close(data->pipefd[i][1]);
	}
}

void wait_for_child(t_pipex *data, int *exit_code)
{
	int	status;
	pid_t pid;
	//int exit_code;
	int i;

	i = 0;
	while (i < data->cmd_count)
	{
		pid = wait(&status);
		printf("status %d\n", status);
		if (pid == -1)
			error_and_exit("wait error\n", data);
		if (WIFEXITED(status))
			*exit_code = WEXITSTATUS(status);
			// exit_code = status;
		else if (WIFSIGNALED(status))
			*exit_code = 128 + WTERMSIG(status);
		i++;
	}
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
		error_and_exit("No such file or directory\n", data);
	while (1)
	{
		ft_putstr_fd("heredoc > ", 1);
		input = get_next_line(STDIN_FILENO);
		//printf("strncmp: %d\n", ft_strncmp(input, limiter, ft_strlen(limiter)));
		if (ft_strncmp(input, limiter, ft_strlen(limiter)) == 0 && input[ft_strlen(limiter) + 1] == '\0')
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
			error_and_exit("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n", data);
		data->is_heredoc = 1;
        data->cmd_index = 3;
		data->cmd_count = ac - 4;
		if (!av[2] || av[2][0] == '\0')
			error_and_exit("Error: No delimiter is found\n", data);
		ft_here_doc(ac, av[2], data);
	}
	else
	{
		data->cmd_index = 2;
        data->cmd_count = ac - 3;
	}
}

int main (int ac, char **av, char **env)
{
	t_pipex data;
	//int **pipefd;
	int i;
	int exit_code;

	//pipefd = NULL;
	if(ac < 5)
		error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2\n", &data);
	init_data(&data);
	handle_input(ac, av, &data);
	open_files(&data, ac, av);
	data.pipefd = init_pipes(&data);
	//printf("Pipe Initialized done\n");
    //child_process1(av, env, fd, &data);
	i = 0;
	while (i < data.cmd_count)
	{
        //printf("i:%d, cmd_index:%d, cmd_count: %d\n", i, data.cmd_index, data.cmd_count);
		create_child_process(av[data.cmd_index], env, &data, i);
		i++;
		data.cmd_index++;
	}
	// wait(NULL);
	wait_for_child(&data, &exit_code);
	unlink(".tmp");
	free_2d((void **)data.pipefd);
	exit(exit_code);
}
