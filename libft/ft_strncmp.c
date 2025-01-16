/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:39:20 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 14:12:55 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// #include <string.h>
// int main (void)
// {
// 	char str1[20] = "Hello\200";
// 	char str2[20] = "Hello\0";
// 	//char str3[20] = "Hello 42";

// 	int result1 = ft_strncmp(str1, str2, 10);
// 	printf("Result: %d\n", result1);

// 	int result2 = strncmp(str1, str2, 10);
// 	printf("Result: %d\n", result2);
// }
