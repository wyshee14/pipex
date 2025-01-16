/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:26:36 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 14:14:51 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	i = 0;
	if (s == (NULL) || f == (NULL))
		return (NULL);
	len = ft_strlen(s);
	result = ((char *)malloc(sizeof(char) * (len + 1)));
	if (result == (NULL))
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	f(unsigned int i, char c)
// {
// 	char	ch;

// 	ch = c - 32;
// 	return (ch);
// }

// int main(void)
// {
// 	const char *str = "hello"; // Put const to avoid modify string data
// 	char *res = ft_strmapi(str, f);
// 	if (res)
// 	{
// 		printf("%s\n", res);
// 		free(res);
// 	}
// 	else
// 		printf("Memory allocation failed\n");
// }
