/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:45:17 by wshee             #+#    #+#             */
/*   Updated: 2024/11/13 14:07:37 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t numBytes)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	if (d <= s)
	{
		while (i < numBytes)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (numBytes > 0)
		{
			d[numBytes - 1] = s[numBytes - 1];
			numBytes--;
		}
	}
	return (dest);
}

//memmove handles overlapping by copy into temp array
// #include <string.h>
// int main()
// {
// 	char str1[] = "Hello World";
// 	char str2[] = "Hello World";
// 	char str3[] = "Hello World";

// 	printf("Original string: %s\n", str1);

// 	char *res1 = ft_memmove(str1 + 5, str1, 5);
// 	printf("ft_memmove: %s\n", res1);

// 	char *res2 = ft_memmove(str2, str2 + 5, 5);
// 	printf("ft_memmove: %s\n", res2);

// 	char *res3 = memcpy(str3 + 5, str3, 5);
// 	printf("memcpy: %s\n", res3);
// }
