/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:22:05 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:35:01 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		ch;
	size_t				i;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

//scans the memory area until the occurence of c, returns pointer
// #include <string.h>
// int main (void)
// {
// 	char str1[20] = "Hello 42";
// 	char *result1 = ft_memchr(str1, 'z', 5);
// 	printf("Result: %s\n", result1);

// 	char str2[20] = "Hello 42";
// 	char *result2 = memchr(str2, 'z', 5);
// 	printf("Result: %s\n", result2);
// }
