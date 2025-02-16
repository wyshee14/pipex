/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:24:22 by wshee             #+#    #+#             */
/*   Updated: 2025/02/16 13:32:00 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	create_child_process(char *cmd, char **env, t_pipex *data, int i)
{
	int	j;

	j = -1;
	data->pid = fork();
	if (data->pid < 0)
		error_and_exit("Fork error! \n", data);
	if (data->pid == 0)
	{
		dup2_input(data, data->pipefd, i);
		dup2_output(data, data->pipefd, i);
		while (++j < data->cmd_count - 1)
		{
			close(data->pipefd[j][0]);
			close(data->pipefd[j][1]);
		}
		execute_command(cmd, env, data);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (i > 0)
			close(data->pipefd[i - 1][0]);
		if (i < data->cmd_count - 1)
			close(data->pipefd[i][1]);
	}
}

// WIFEXITED(status)
// Checks if the child terminated normally (i.e., via exit() or return in main).
// If true, WEXITSTATUS(status) retrieves the exit code.
// WIFSIGNALED(status)
// Checks if the child was terminated by a signal (e.g., SIGKILL, SIGSEGV).
// If true, WTERMSIG(status) gets the signal number that caused termination.
// The exit code is then set to 128 + signal_number, following convention.
void	wait_for_child(t_pipex *data, int *exit_code)
{
	int	status;

	waitpid(data->pid, &status, 0);
	if (data->pid == -1)
		error_and_exit("wait error\n", data);
	if (data->outfile_error == 1)
	{
		if (data->pipefd)
			free_2d((void **)(data->pipefd));
		exit(1);
	}
	if (WIFEXITED(status))
		*exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		*exit_code = 128 + WTERMSIG(status);
}

// get next line will extract the line and
// appended via write function to pipe write end
// until limiter is found
void	ft_here_doc(char *limiter, t_pipex *data)
{
	char	*input;

	data->infile = open(".tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (data->infile == -1)
		error_and_exit("No such file or directory\n", data);
	while (1)
	{
		ft_putstr_fd("heredoc > ", 1);
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(limiter)) == 0
			&& input[ft_strlen(limiter) + 1] == '\0')
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
		{
			perror("Usage: \n"
				"./pipex here_doc LIMITER cmd1 cmd2 outfile\n");
			exit(1);
		}
		data->is_heredoc = 1;
		data->cmd_index = 3;
		data->cmd_count = ac - 4;
		if (!av[2] || av[2][0] == '\0')
			error_and_exit("Error: No delimiter is found\n", data);
		ft_here_doc(av[2], data);
	}
	else
	{
		data->cmd_index = 2;
		data->cmd_count = ac - 3;
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	data;
	int		i;
	int		exit_code;

	if (ac < 5)
	{
		perror("Usage: ./pipex file1 cmd1 ... cmdn file2\n");
		exit(1);
	}
	init_data(&data, ac, av);
	i = 0;
	while (i < data.cmd_count)
	{
		create_child_process(av[data.cmd_index], env, &data, i);
		i++;
		data.cmd_index++;
	}
	wait_for_child(&data, &exit_code);
	while (wait(NULL) != -1)
		;
	unlink(".tmp");
	free_2d((void **)data.pipefd);
	exit(exit_code);
}

// fork all the number of child required based on the number of commands
// after that finally wait the child to kill
// (wait_for_child function)
// wait for the last child to get the exit code of last command
// wait(NULL) != -1 is wait for every child is killed before exits the program
// unlink is to remove the temperary file created
// lastly free the pipefd to avoid memory leaks
