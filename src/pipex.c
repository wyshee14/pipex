/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:26:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/21 21:15:42 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void error_and_exit(char *message)
{
		perror(message);
		exit(EXIT_FAILURE);
}

void init_pipes(int *pipefd)
{
	if (pipe(pipefd) == -1)
		error_and_exit("Pipe error\n");
}

void	pipex(int fd1, int fd2, int ac, char **av)
{
	int pipefd[2];
	pid_t	pid;
	int cmd_count;
	int i;

	i = 0;
	cmd_count = ac - 3;
	while (i < cmd_count)
	{
		pid = fork();
		if (pid == -1)
			error_and_exit("Fork error\n");
		else if (pid == 0)
		{
			child_process(fd1, fd2, pipefd, i);
			execute_command(av);
		}
		else
			parent_process(pipefd);
		i++;
	}
}

//dup2 makes a new copy of fd
void child_process(int fd1, int fd2, int *pipefd, int i)
{
	if (i == 0)
	{
		close(pipefd[0]);
		dup2(fd1, STDIN_FILENO);
		close(fd1);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
	}
	else if ()
	{
		close(pipefd[1]);
		dup2(fd2, 1);
		close(fd2);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
}

void parent_process(int *pipefd)
{
	close(pipefd[1]);
}

//pid_t data type is signed int representing process ID (PID)
//read from infile, execute cmd1 with infile as input
//send output to cmd2, write to outfile
//pipe send output of the first execve as input to the second execve
//pipefd[0] is read end, pipefd[1] is write end
//success will return (0), error will return (-1)
//fork runs two process (parent and 2 child process) in one single program
//if success, pid of child returned to parent, 0 returned in child
//if error, (-1) is returned in parent, no child process is created
//dup2 swap file with stdin and stdout
//waitpid is wait for the child process to finish
int main(int ac, char **av)
{
	int fd1;
	int fd2;

	if (ac != 5)
		error_and_exit("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_CREAT | O_RDWR);
	if (fd1 < 0 || fd2 < 0)
		error_and_exit("File not exist");
	init_pipes
	check_commands
	pipex(fd1, fd2, av);
	// close(pipefd[0]);
	// close(pipefd[1]);
	waitpid(pid);
}
