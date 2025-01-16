/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:24:25 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 13:42:42 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int main (void)
// {
// 	char *str = "ABCDEF";
// 	int i = 0;
// 	int size = sizeof(str);
// 	while (i < size && str[i] != '\0')
// 	{
// 		char res = ft_tolower(str[i]);
// 		printf("%c", res);
// 		i++;
// 	}
// 	printf("\n");
// }
