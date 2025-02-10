/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:14:19 by wshee             #+#    #+#             */
/*   Updated: 2025/02/10 21:16:00 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex_bonus.h"
# include <errno.h>

void error_and_exit(char *message)
{
	// printf("Exiting program...\n");
	perror(message);
	exit(1);
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
	char *temp;

	i = 0;
	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (env_path[i])
    {
		cmd_path = ft_strjoin("/", cmd);
		if (!cmd_path)
			return(NULL);
		temp = cmd_path;
        cmd_path = ft_strjoin(env_path[i], temp);
		free(temp);
		if (!cmd_path)
			return(NULL);
		//printf("cmd_path: %s\n", cmd_path);
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
	//write(2, cmd, ft_strlen(cmd));
    free_2d((void **)env_path);
    return(path);
}

void execute_command(char *cmd, char **env)
{
    char **args;
    char *path;

	// write(2, cmd, ft_strlen(cmd));
	// write(2, "\n", 1);
    args = ft_split(cmd, ' ');
	// for(int i = 0; args[i] != NULL; i++)
	// {
	// 	printf("args[%d]: %s\n", i, args[i]);
	// 	// write(2, cmd, ft_strlen(args[i]));
	// 	// write(2, "\n", 1);
	// }
    path = fetch_path(args[0], env);
    //printf("%s\n", path);
	// write(2, path, ft_strlen(path));
	// write(2, "\n", 1);
    if (!path)
    {
        free_2d((void **)args);
        error_and_exit("Command not found.");
    }
    if ((execve(path, args, env)) == -1)
	{
        free(path);
		free_2d((void **)args);
		error_and_exit("Execve error.\n");
	}
	if(errno == ENOENT)
	{
		printf("Error command xxx\n");
		exit(127);
	}
	else
	{
		perror("execve");
		exit(126);
	}
}
