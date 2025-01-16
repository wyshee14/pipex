/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:58:50 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 14:13:23 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit (nptr[i]))
	{
		result = result * 10;
		result = result + nptr[i] - '0';
		i++;
	}
	result *= sign;
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// int main(void)
// {
// 	char str1[] = "++123";
// 	char str2[] = "+-45";
// 	char str3[] = "-+98";
// 	char str4[] = "-67";
// 	char str5[] = "\n\n\n  -46\b9 \n5d6";
// 	char str6[] = "\e475";
// 	char str7[] = "\n\n\n  -46\b9 \n5d6";
// 	char str8[] = "\e475";
// 	printf("%d\n", ft_atoi(str1));
// 	printf("%d\n", ft_atoi(str2));
// 	printf("%d\n", ft_atoi(str3));
// 	printf("%d\n", ft_atoi(str4));
// 	printf("%d\n", ft_atoi(str5));
// 	printf("%d\n", ft_atoi(str6));
// 	printf("%d\n", atoi(str7));
// 	printf("%d\n", atoi(str8));
// }
