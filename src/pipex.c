/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:26:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/16 18:45:10 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void error_and_exit(char *message)
{
		perror(message);
		exit(EXIT_FAILURE);
}

void	pipex(int fds1, int fds2)
{

}

//dup2 makes a new copy of fd
void child_process()
{
	dup2(pipefd[1], 1);
	close()
}

void parent_process()
{

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
	int pipefd[2];
	pid_t	pid;

	if (ac != 5)
		error_and_exit("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(pipefd) == -1)
		error_and_exit("Pipe error\n");
	if (open(argv[1]))
	pid = fork();
	if (pid == -1)
		error_and_exit("Fork error\n");
	if (pid == 0)
		child_process(pipefd[1]);
	else
		parent_process();
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid);
}
