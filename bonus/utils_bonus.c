/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:14:19 by wshee             #+#    #+#             */
/*   Updated: 2025/02/05 17:16:17 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/pipex.h"

void error_and_exit(char *message)
{
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

char *access_path(char **env_path, char *add_path)
{
    int i;
    char *cmd_path;

    i = 0;
    while (env_path[i])
    {
        cmd_path = ft_strjoin(env_path[i], add_path);
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
    char **env_path = NULL;
    char *add_path;
    char *path;

    i = 0;
    while (env[i])
    {
        if (ft_strncmp(env[i], "PATH=", 5) == 0)
        {
            env_path = ft_split(env[i] + 5, ':');
            break ;
        }
        i++;
    }
    if (env_path == NULL)
        return (NULL);
    add_path = ft_strjoin("/", cmd);
    path = access_path(env_path, add_path);
    free_2d((void **)env_path);
    free(add_path);
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
