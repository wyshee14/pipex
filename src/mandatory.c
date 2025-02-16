/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:35:28 by wshee             #+#    #+#             */
/*   Updated: 2025/02/16 13:31:14 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	open_infile(char **av, int *infile)
{
	*infile = open(av[1], O_RDONLY);
	if (*infile == -1)
	{
		perror("Failed to open infile");
		*infile = open("/dev/null", O_RDONLY);
		if (*infile == -1)
			error_and_exit("Failed to open /dev/null", 1);
	}
}

// Fork function create child process
// fork runs two process (parent and 2 child process) in one single program
// if success, pid of child returned to parent, 0 returned in child
// if error, (-1) is returned in parent, no child process is created
// child process writes to the pipe
// input Redirection with dup2(infile, STDIN_FILENO)
// output Redirection with dup2(pipefd[1], STDOUT_FILENO)
// anything cmd1 writes to standard output will go into the pipe.
// exit success (returns 0), exit failure (returns != 0)
void	child_process1(char **av, char **env, int *fd)
{
	int		infile;
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
		error_and_exit ("Fork 1 error!", 1);
	if (pid1 == 0)
	{
		close (fd[0]);
		open_infile(av, &infile);
		dup2(infile, STDIN_FILENO);
		close(infile);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute_command(av[2], env);
		exit(EXIT_FAILURE);
	}
	else
	{
		close (fd[1]);
		wait(NULL);
	}
}

void	child_process2(char **av, char **env, int *fd)
{
	int		outfile;
	pid_t	pid2;
	int		status;

	pid2 = fork();
	if (pid2 < 0)
		error_and_exit("Fork 2 error!", 1);
	if (pid2 == 0)
	{
		close(fd[1]);
		outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
		if (outfile == -1)
			error_and_exit("Failed to open outfile", 1);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execute_command(av[3], env);
		exit(EXIT_SUCCESS);
	}
	close (fd[0]);
	waitpid(pid2, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];

	if (ac != 5)
		error_and_exit("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	if (pipe(fd) == -1)
		error_and_exit("Pipe error", 1);
	child_process1(av, env, fd);
	child_process2(av, env, fd);
	exit(EXIT_SUCCESS);
}

// pid_t data type is signed int representing process ID (PID)
// read from infile, execute cmd1 with infile as input
// send output to cmd2, write to outfile
// pipe send output of the first execve as input to the second execve
// pipefd[0] is read end, pipefd[1] is write end
// success will return (0), error will return (-1)
// dup2 swap file with stdin and stdout
// waitpid is wait for the child process to finish
