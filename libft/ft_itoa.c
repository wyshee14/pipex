/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:32:39 by wshee             #+#    #+#             */
/*   Updated: 2024/11/25 18:29:31 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter += 1;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void	put_digit(char *result, int n, int size)
{
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		result = (char *)malloc(2);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	size = digit_count(n);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == (NULL))
		return (NULL);
	result[size] = '\0';
	put_digit(result, n, size - 1);
	return (result);
}

// assign n to (long) to handle negative min int, prevent overflow
// int can store 32-bits can store values between -2147483648 and 2147483647
// long int can store 64 bits
// int main(void)
// {
// 	int n = 0;
// 	int n1 = -123;
// 	int n2 = 123;
// 	int n3 = -2147483648;

// 	char *res = ft_itoa(n);
// 	printf("%s\n", res);
// 	free(res);

// 	res = ft_itoa(n1);
// 	printf("%s\n", res);
// 	free(res);

// 	res = ft_itoa(n2);
// 	printf("%s\n", res);
// 	free(res);

// 	res = ft_itoa(n3);
// 	printf("%s\n", res);
// 	free(res);
// }
