/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:48:58 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:09:09 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa(unsigned int n, char print)
{
	char	*hex;
	int		count;

	if (print == 'x')
		hex = "0123456789abcdef";
	if (print == 'X')
		hex = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
	{
		write(1, &hex[n], 1);
		return (1);
	}
	else
	{
		count = ft_printhexa(n / 16, print);
		count += ft_printhexa(n % 16, print);
	}
	return (count);
}

//printf handles for unsigned int only
// #include <stdio.h>
// int main (void)
// {
// 	int count = ft_printhexa(-42, 'x');
// 	printf("\n%d\n", count);
// 	printf("%x\n", -42);
// }
