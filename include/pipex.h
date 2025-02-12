/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:18:05 by wshee             #+#    #+#             */
/*   Updated: 2025/02/12 17:45:07 by wshee            ###   ########.fr       */
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

void	error_and_exit(char *message, int exit_code);
void	free_2d(void **arr);
char	*access_path(char **env_path, char *add_path);
char	*fetch_path(char *cmd, char **env);
void	execute_command(char *cmd, char **env);

#endif
