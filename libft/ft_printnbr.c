/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:44:38 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:09:14 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_printchar('-');
		count += ft_printchar('2');
		n = 147483648;
		count += ft_printnbr(n);
	}
	else if (n < 0)
	{
		count += ft_printchar('-');
		n = -n;
		count += ft_printnbr(n);
	}
	else if (n < 10)
		count += ft_printchar(n + '0');
	else
	{
		count += ft_printnbr(n / 10);
		count += ft_printnbr(n % 10);
	}
	return (count);
}

//#include <stdio.h>
// int main(void)
// {
// 	int n1 = 12345;
// 	int n2 = -42;
// 	int n3 = -2147483648;
// 	printf("\n%d\n", ft_printnbr(n1));
// 	printf("\n%d\n", ft_printnbr(n2));
// 	printf("\n%d\n", ft_printnbr(n3));
// }
