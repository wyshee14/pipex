/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:40:56 by wshee             #+#    #+#             */
/*   Updated: 2024/12/01 16:55:04 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
		ft_putnbr_fd(n, fd);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

// handle integer overflow,
//if we convert -2147483648 to positive will cause integer overflow
// hence manually printout the first two character
// int main(void)
// {
// 	ft_putnbr_fd(123, 2);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-2147483648, 2);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(-123, 2);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(0, 2);
// 	write(1, "\n", 1);
// }
