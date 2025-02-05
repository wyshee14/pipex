/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:18:05 by wshee             #+#    #+#             */
/*   Updated: 2025/02/05 17:10:43 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int infile;
	int outfile;
	int is_heredoc;
	int cmd_index;
	int cmd_count;
	int pipe_count;
	//int **pipefd;
}				t_pipex;

//Utils
void error_and_exit(char *message);
void free_2d(void **arr);
char *access_path(char **env_path, char *add_path);
char *fetch_path(char *cmd, char ** env);
void execute_command(char *cmd, char **env);

#endif
