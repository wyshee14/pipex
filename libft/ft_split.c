/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:05:23 by wshee             #+#    #+#             */
/*   Updated: 2024/11/15 14:50:11 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **res, int i)
{
	while (i > 0)
	{
		i--;
		free (res[i]);
	}
	free(res);
	return (NULL);
}

static int	count_word(char const *s, char c)
{
	int	counter;
	int	i;
	int	in_word;

	counter = 0;
	i = 0;
	in_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && in_word == 0)
		{
			counter++;
			in_word = 1;
		}
		if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (counter);
}

static int	count_word_len(const char *s, char c, int start)
{
	int	word_len;

	word_len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		word_len++;
		start++;
	}
	return (word_len);
}

static char	*ft_put_word(char const *s, char c, int *start)
{
	char	*word;
	int		word_len;
	int		j;

	j = 0;
	word_len = count_word_len(s, c,*start);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (word == NULL)
		return (NULL);
	while (j < word_len)
	{
		word[j] = s[*start];
		j++;
		(*start)++;
	}
	word[j] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	int		i;
	char	**res;

	i = 0;
	word = 0;
	if (s == NULL)
		return (NULL);
	res = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			res[word] = ft_put_word(s, c, &i);
			if (res[word] == NULL)
				return (free_array (res, word));
			word++;
		}
	}
	res[word] = 0;
	return (res);
}

// int main(void)
// {
// 	char *str = "Welcome to 42KL";
// 	char c = ' ';
// 	char **res = ft_split(str, ' ');
// 	int num_words = count_word(str, c);
// 	int i = 0;
// 	while (i < num_words)
// 	{
// 		printf("Word[%d]: %s\n", i, res[i]);
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// }
