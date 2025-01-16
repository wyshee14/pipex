/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:30:09 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 15:34:39 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

//const char variable and pointer is immutable(read-only), char is mutable
//line21 check for null string input
//line29 check if c is null terminator
//line30 return pointer to null terminator
// int main (void)
// {
// 	char* s = "hello kkshkjk";
// 	int n = 0;
// 	char* result = strchr(s, n);
// 	char* result2 = ft_strchr(s, n);
// 	printf("r:%s\n", result);
// 	printf("r2:%s\n", result2);
// }
