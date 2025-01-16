/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:28:33 by wshee             #+#    #+#             */
/*   Updated: 2025/01/13 16:45:02 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//get the line inside buffer after the new line
//Free old buffer, remove the content before \n
//allocate memory for the remaining character after \n is found
//Return remaining content
char	*next_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (line == NULL)
		return (NULL);
	free (buffer);
	return (line);
}

//extracts the first line including \n from the buffer
//go through buffer to find \n or \0
//allocate memory for line
//(i + 1) to include the new line
//copy line content into new string
char	*make_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_substr(buffer, 0, i + 1);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

//join the content of buffer into a new string
//free the old buffer to prevent overwrite buffer
char	*ft_join(char *oldbuffer, char *tempbuf)
{
	char	*new;

	new = ft_strjoin(oldbuffer, tempbuf);
	free(oldbuffer);
	return (new);
}

//initialize buffer as an empty string
//initialize bytes to run below function, contain garbage data if uninitialized
//read fd of buffer size until newline or \0 is found
//byte_read -1 happens when the file is close or error(-1) or
//read return the number of bytes read
//join two buffer using join
//stop reading if a newline is found
char	*read_file(int fd, char *buffer)
{
	char	*tempbuf;
	ssize_t	byte_read;

	if (buffer == NULL)
	{
		buffer = ft_calloc(1, 1);
	}
	tempbuf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tempbuf == NULL)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read > 0)
	{
		byte_read = read(fd, tempbuf, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(tempbuf);
			free(buffer);
			return (NULL);
		}
		tempbuf[byte_read] = '\0';
		buffer = ft_join(buffer, tempbuf);
	}
	free(tempbuf);
	return (buffer);
}

/**
 * @brief check fd is valid, handle errors
 * read and update buffer,
 * free buffer after line is read,
 * extract the line end with new line,
 * remove processed line, keep unread content
 * @param fd
 * @return extracted line
 */
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = make_line(buffer);
	buffer = next_line(buffer);
	return (line);
}

//buffer is a section of memory that temperarily stores data
//that is being transferred from one place to another.
//static char acts as a persistent storage for unread data from the fd
//allow to resume reading from where it left off
//char is local variable with single call only, ends when the function call ends
//if there is no file, print error
//continue call get next line until the line reach NULL (EOF)
//must free line, prevent memory leak

// #include <stdio.h>
// # include <fcntl.h>

// int main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("%s",line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
