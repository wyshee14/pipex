/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:18:05 by wshee             #+#    #+#             */
/*   Updated: 2025/02/11 15:46:15 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int infile;
	int infile_error;
	int outfile;
	int is_heredoc;
	int cmd_index;
	int cmd_count;
	int pipe_count;
	int **pipefd;
	//pid_t pid;
}				t_pipex;

//Utils1
void error_and_exit(char *message, t_pipex *data);
void free_2d(void **arr);
char *access_path(char **env_path, char *add_path);
char *fetch_path(char *cmd, char ** env);
void execute_command(char *cmd, char **env, t_pipex *data);

//Utils2
void dup2_input(t_pipex *data, int **pipefd, int i);
void dup2_output(t_pipex *data, int **pipefd, int i);
void	open_files(t_pipex *data, int ac, char **av);
int **init_pipes(t_pipex *data);
void init_data(t_pipex *data);

#endif
