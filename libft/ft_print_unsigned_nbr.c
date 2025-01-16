/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_nbr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:32:38 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:08:45 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_unsigned_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 10)
		count += ft_printchar(n + '0');
	else
	{
		count += ft_print_unsigned_nbr(n / 10);
		count += ft_print_unsigned_nbr(n % 10);
	}
	return (count);
}

// #include <stdio.h>
// int main(void)
// {
// 	int n = -5;
// 	printf("\n%u\n", ft_print_unsigned_nbr(n));
// 	printf("%u\n", -5);
// }
