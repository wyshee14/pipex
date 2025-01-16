/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:23:08 by wshee             #+#    #+#             */
/*   Updated: 2024/11/25 18:11:39 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*ptr;
	int				i;

	ptr = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		ptr[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (ptr);
}

//fills first n bytes of memory area pointed to s with c
//return a pointer to the memory area s
// #include <stdio.h>
// int main()
// {
// 	char s[] = "Hello my name is Bello.";
// 	ft_memset((s + 17), 'X', 5);
// 	printf("%s\n", s);
// }
