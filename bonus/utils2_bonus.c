/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:43:52 by wshee             #+#    #+#             */
/*   Updated: 2025/02/10 18:16:21 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex_bonus.h"

void dup2_input(t_pipex *data, int **pipefd, int i)
{
	if (i == 0)
	{
		//printf("dup2 input\n");
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
		//printf("dup2 output\n");
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
	//printf("infile fd: %d\n", data->infile);
    if (data->infile == -1)
	{
        data->infile_error++;
		perror("Failed to open infile.\n");
		data->infile = open("/dev/null", O_RDONLY);
		if(data->infile == -1)
			error_and_exit("Failed to open /dev/null");
	}
    //printf("outfile fd: %d\n", data->outfile);
    if (data->outfile == -1)
        error_and_exit("Failed to open outfile.\n");
}

void init_data(t_pipex *data)
{
    ft_memset(data, 0, sizeof(t_pipex));
	// data->infile = 0;
    // data->outfile = 0;
    // data->is_heredoc = 0;
    // data->cmd_index = 0;
    // data->cmd_count = 0;
    // data->pipe_count = 0;
}
