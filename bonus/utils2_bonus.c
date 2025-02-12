/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:52 by wshee             #+#    #+#             */
/*   Updated: 2025/02/12 16:33:17 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	dup2_input(t_pipex *data, int **pipefd, int i)
{
	if (i == 0)
	{
		dup2(data->infile, STDIN_FILENO);
		close(data->infile);
	}
	else
	{
		dup2(pipefd[i - 1][0], STDIN_FILENO);
		close(pipefd[i - 1][0]);
	}
}

void	dup2_output(t_pipex *data, int **pipefd, int i)
{
	if (i == data->cmd_count - 1)
	{
		if (data->outfile_error == 1)
		{
			perror("Failed to open outfile.\n");
			exit(1);
		}
		dup2(data->outfile, STDOUT_FILENO);
		close(data->outfile);
	}
	else
	{
		dup2(pipefd[i][1], STDOUT_FILENO);
		close(pipefd[i][1]);
	}
}

void	open_files(t_pipex *data, int ac, char **av)
{
	if (data->is_heredoc == 1)
	{
		data->infile = open(".tmp", O_RDONLY);
		data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	}
	else if (data->is_heredoc == 0)
	{
		data->infile = open(av[1], O_RDONLY);
		data->outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	}
	if (data->infile == -1)
	{
		data->infile_error = 1;
		perror("Failed to open infile.\n");
		data->infile = open("/dev/null", O_RDONLY);
		if (data->infile == -1)
			error_and_exit("Failed to open /dev/null", data);
	}
	if (data->outfile == -1)
		data->outfile_error = 1;
}

// Initialize pipes based on how many commands -1
// The array pipe_fd stores file descriptors for multiple pipes.
int	**init_pipes(t_pipex *data)
{
	int	i;

	data->pipefd = (int **)malloc((data->cmd_count) * sizeof(int *));
	if (!data->pipefd)
		error_and_exit("Pipe error\n", data);
	i = 0;
	while (i < data->cmd_count - 1)
	{
		data->pipefd[i] = (int *)malloc(2 * sizeof(int));
		if (pipe(data->pipefd[i]) == -1)
			error_and_exit("Pipe error\n", data);
		i++;
	}
	data->pipefd[i] = NULL;
	return (data->pipefd);
}

void	init_data(t_pipex *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_pipex));
	handle_input(ac, av, data);
	open_files(data, ac, av);
	data->pipefd = init_pipes(data);
}
