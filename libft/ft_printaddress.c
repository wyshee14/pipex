/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:49:18 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:08:51 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//use unsigned long to handle 64bits ptr 0xFFFFFFFFFFFFFFFF
static int	ft_hexadec(unsigned long address)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	if (address < 16)
	{
		write(1, &hex[address], 1);
		return (1);
	}
	else
	{
		count = ft_hexadec(address / 16);
		count += ft_hexadec(address % 16);
	}
	return (count);
}

int	ft_printaddress(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	count += write(1, "0x", 2);
	count += ft_hexadec((unsigned long)ptr);
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int n = 42;
// 	int count = ft_printaddress(&n);
// 	printf("\n%d\n", count);
// }
