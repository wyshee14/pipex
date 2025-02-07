/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:14:19 by wshee             #+#    #+#             */
/*   Updated: 2025/02/07 15:59:57 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void error_and_exit(char *message)
{
	printf("Exiting program\n");
	perror(message);
	exit(EXIT_FAILURE);
}

void free_2d(void **arr)
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

// access, flag F_OK used to check for the existence of a file
// if error (returns -1), access (returns 0)
char *access_path(char **env_path, char *cmd)
{
	int i;
	char *cmd_path;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (env_path[i])
	{
		cmd_path = ft_strjoin("/", cmd);
		cmd_path = ft_strjoin(env_path[i], cmd_path);
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
    char *path;

    i = 0;
	env_path = NULL;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            env_path = ft_split(env[i] + 5, ':');
			if (env_path == NULL)
				free_2d((void **)env_path);
			break ;
        }
        i++;
    }
    path = access_path(env_path, cmd);
    free_2d((void **)env_path);
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
        free_2d((void **)args);
        error_and_exit("Command not found.\n");
    }
    if ((execve(path, args, env)) == -1)
        error_and_exit("Execve error.\n");
}
