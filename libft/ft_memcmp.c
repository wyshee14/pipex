/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:45:38 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:35:06 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

//memcmp the memory of n bytes, null terminator is also considered
// int main (void)
// {
// 	char str1[20] = "";
// 	char str2[20] = "Hello24";
// 	//char str3[20] = "Hello 42";

// 	int result1 = ft_memcmp(str1, str2, 10);
// 	printf("Result: %d\n", result1);

// 	int result2 = memcmp(str1, str2, 10);
// 	printf("Result: %d\n", result2);
// }
