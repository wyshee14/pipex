/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:14:27 by wshee             #+#    #+#             */
/*   Updated: 2024/12/23 22:09:02 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(const char print, va_list args)
{
	int	i;

	i = 0;
	if (print == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (print == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (print == 'p')
		i += ft_printaddress(va_arg(args, void *));
	else if (print == 'd' || print == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (print == 'u')
		i += ft_print_unsigned_nbr(va_arg(args, unsigned int));
	else if (print == 'x' || print == 'X')
		i += ft_printhexa(va_arg(args, int), print);
	else if (print == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, fmt);
	i = 0;
	count = 0;
	if (fmt == NULL)
		return (0);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			count += print_format(fmt[i], args);
		}
		else
			count += write(1, &fmt[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

//char literal in C is already an int, promotion type
//#include <stdio.h>
//int main(void)
//{
	/*
	char	c = 'A';
	char	*str = " Hello World";
	int		nbr = 123456;
	int		dec = 1.23;
	unsigned int	us_nbr = 4294967295;
	void	*ptr = &nbr;
	int		count1;
	int		count2;

	count1 = ft_printf("%c %s %p %i %d %u %x %X %%", \
	//c, str, ptr, nbr, dec, us_nbr, nbr, nbr, '%');
	ft_printf("\nCount: %d\n", count1);
	count2 = printf("%c %s %p %i %d %u %x %X %%", \
	//c, str, ptr, nbr, dec, us_nbr, nbr, nbr, '%');
	printf("\nCount: %d\n", count2);
	*/

	/*
	int i;
	int j;
	char *str = NULL;

	i = ft_printf("%s\n", str);
	ft_printf("Count: %d\n", i);
	j = printf("%s\n", str);
	printf("Count: %d\n", j);
	*/
//}
