/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:33:27 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 13:44:43 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int main (void)
// {
// 	char *str = "abcd";
// 	int i = 0;
// 	int n = 0;
// 	while (str[n] != '\0')
// 		n++;
// 	while (i < n)
// 	{
// 		char c = str[i];
// 		c = ft_toupper(c);
// 		printf("%c", c);
// 		i++;
// 	}
// 	printf("\n");
// }
