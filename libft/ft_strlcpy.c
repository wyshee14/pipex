/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:56:40 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:36:20 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	src_len(const char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		count++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		return (src_len(src));
	}
	i = 0;
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len(src));
}

// int main (void)
// {
// 	char str1[] = "Hello World";
// 	char str2[100];
// 	ft_strlcpy(str2, str1, sizeof(str1));
// 	printf("%s\n", str2);
// 	return (0);
// }
