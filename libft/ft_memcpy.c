/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:30:11 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 20:51:41 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t numBytes)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < numBytes)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// int main()
// {
//     char str1[] = "";
//     char str2[] = "World";
//     printf("Before memcpy: %s\n", str1);
//     memcpy(NULL, NULL, 0);
//     printf("After memcpy: %s\n", str1);
// }
