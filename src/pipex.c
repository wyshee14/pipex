/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:26:04 by wshee             #+#    #+#             */
/*   Updated: 2025/01/24 20:02:06 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void error_and_exit(char *message)
{
		perror(message);
		exit(EXIT_FAILURE);
}

// void	execute_command()
// {

// }

// Initialize pipes based on how many commands -1
// The array pipe_fd stores file descriptors for multiple pipes.
// pipe_index * 2 adjusts the pointer to one write end and one read end
// pipe(pipe_fd + 0 * 2) → Sets pipe_fd[0] and pipe_fd[1] and so on
int	*init_pipes(int *cmd_count)
{
	int *pipefd;
	int i;

	printf("Initializing Pipe\n");
	pipefd = (int *)malloc((*cmd_count - 1) * 2 * sizeof(int));
	if (!pipefd)
		 error_and_exit("Pipe error\n");
	i = 0;
	while (i < *cmd_count - 1)
	{
		if(pipe(pipefd + i * 2) == -1)
			error_and_exit("Pipe error\n");
		i++;
	}
	return(pipefd);
}

void	test_pipes(int *pipefd, int *cmd_count)
{
	const char *message[] = {"Pipe1", "Pipe2", "Pipe3"};
	char buffer[128];
	int i = 0;

	printf("Testing Pipes\n");
	printf("cmd_count: %d\n", *cmd_count);
	//child process
	while (i < *cmd_count - 1)
	{
		printf("Writing to pipe %d\n", i);
		printf("len: %zu\n", ft_strlen(message[i]));
		if (write(pipefd[i * 2 + 1], message[i], ft_strlen(message[i] + 1)) == -1)
			error_and_exit("write error");
		printf("Written to pipe %d: %s\n", i, message[i]);
		//close(pipefd[i * 2 + 1]); //write end
		//close(pipefd[i * 2]); //read end
		i++;
	}
	//parent process
	i = 0;
	while (i < *cmd_count - 1)
	{
		printf("Reading from pipe %d\n", i);
		ssize_t bytes_read = read(pipefd[i * 2], buffer, sizeof(buffer) - 1);
		if (bytes_read == -1)
			error_and_exit("read error");
		buffer[bytes_read] = '\0';
		printf("Pipe %d: %s\n", i, buffer);
		close(pipefd[i * 2]); //read end
		// close(pipefd[i * 2 + 1]); //write end
		i++;
	}
}

//dup2 makes a new copy of fd
// void child_process(int infile, int outfile, int *pipefd, int i, int has_doc, int cmd_count)
// {
// 	if (i == 0)
// 	{
// 		close(pipefd[0]); //read end
// 		dup2(infile, STDIN_FILENO);
// 		close(infile);
// 		dup2(pipefd[1], STDOUT_FILENO);
// 		close(pipefd[1]); //write end
// 	}
// 	else if (i == cmd_count - 1)
// 	{
// 		close(pipefd[1]);
// 		dup2(outfile, 1);
// 		close(outfile);
// 		dup2(pipefd[0], STDIN_FILENO);
// 		close(pipefd[0]);
// 	}
// 	else
// 	{
// 		close
// 	}
// }

// void parent_process(int *pipefd)
// {
// 	close(pipefd[1]);
// }

int	open_input_files(const char *infile, int *is_heredoc)
{
	int infile_fd;

	if (is_heredoc)
		infile_fd = open(".tmp", O_RDONLY);
	else
		infile_fd = open(infile, O_RDONLY);
	return(infile_fd);
}

// Fork function create child process
// fork runs two process (parent and 2 child process) in one single program
// if success, pid of child returned to parent, 0 returned in child
// if error, (-1) is returned in parent, no child process is created
// child process writes to the pipe
void	ft_pipex(int ac, char **av, int *is_heredoc, int *cmd_count)
{
	int infile;
	int outfile;
	int *pipefd;
	pid_t	pid;
	int i;

	infile = open_input_files(av[1], is_heredoc);
	outfile = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (infile < 0 || outfile < 0)
		error_and_exit("No such file ordirectory\n");
	pipefd = init_pipes(cmd_count);
	i = 0;
	while (i < *cmd_count)
	{
		pid = fork();
		if (pid == -1)
			error_and_exit("Fork error\n");
		else if (pid == 0) //child
		{
			close(pipefd[i * 2]);
			char message[128];
			snprintf(message, sizeof(message), "Message from child %d", i + 1);
			if (write(pipefd[i * 2 + 1], message, ft_strlen(&message[i])) == -1)
				error_and_exit("write error");
			//dup2(infile, STDIN_FILENO);
			// close (infile);
			// dup2(pipefd[i * 2 + 1], 1);
			close (pipefd[i * 2 + 1]);
			exit(0);
			//execute_command(av);
		}
		else //parent
			close (pipefd[i * 2]);
		i++;
	}
	i = 0;
	while (i < *cmd_count)
	{
		char buffer[128];
		ssize_t bytes_read = read(pipefd[i * 2], buffer, sizeof(buffer) - 1);
		if (bytes_read == -1)
			error_and_exit("read error");
		buffer[bytes_read] = '\0';
		printf("Parents received from pipe %d: %s\n", i + 1, buffer);
		close(pipefd[i * 2]); //read end
		// close(pipefd[i * 2 + 1]); //write end
		i++;
	}
	free(pipefd);
}

// get next line will extract the line and
// appended via write function to pipe write end
// until limiter is found
void ft_here_doc(int ac, char *limiter)
{
	int infile;
	char *input;
	(void)ac;

	infile = open(".tmp", O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (infile == -1)
		error_and_exit("No such file or directory\n");
	while (1)
	{
		ft_putstr_fd("heredoc > ", 1);
		input = get_next_line(STDIN_FILENO);
		if (ft_strncmp(input, limiter, ft_strlen(limiter)) == 0)
		{
			free(input);
			break ;
		}
		write(infile, input, ft_strlen(input));
		free(input);
	}
	close(infile);
}

void	handle_input(int ac, char **av, int *cmd_count, int *is_heredoc)
{
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			error_and_exit("Usage: ./pipex here_doc LIMITER cmd1 cmd2 outfile\n");
		*is_heredoc = 1;
		*cmd_count = ac - 4;
		if (!av[2] || av[2][0] == '\0')
			error_and_exit("Error: No delimiter is found\n");
		ft_here_doc(ac, av[2]);
	}
	else
	{
		*cmd_count = ac - 3;
	}
}


int main(int ac, char **av)
{
	int cmd_count;
	int is_heredoc;

	cmd_count = 0;
	is_heredoc = 0;
	if (ac < 5)
		error_and_exit("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	handle_input(ac, av, &cmd_count, &is_heredoc);
	printf("cmd_count: %d\n", cmd_count);
	// if (cmd_count > 0)
	// {
	// 	pipefd = init_pipes(&cmd_count);
	// 	printf("Pipe Initialized\n");
	// 	test_pipes(pipefd, &cmd_count);
	// 	printf("Test pipes executed\n");
	// }
	// else
	// 	error_and_exit("Invalid execution");
	ft_pipex(ac, av, &is_heredoc, &cmd_count);
	// check_commands
	// waitpid(pid);
}

//pid_t data type is signed int representing process ID (PID)
//read from infile, execute cmd1 with infile as input
//send output to cmd2, write to outfile
//pipe send output of the first execve as input to the second execve
//pipefd[0] is read end, pipefd[1] is write end
//success will return (0), error will return (-1)
//dup2 swap file with stdin and stdout
//waitpid is wait for the child process to finish
