/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:29:16 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 11:26:52 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, unsigned int n)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)s;
	i = 0;
	while (n > 0)
	{
		p[i] = 0;
		n--;
		i++;
	}
}

//Type cast p to unsigned char (to access memory block one by one only one byte,
//avoid sign issues)
// #include <stdio.h>
// int main()
// {
//     char str[] = "I am apple";
//     ft_bzero(str + 5, 5);
//     printf("%s\n", str);
// }
