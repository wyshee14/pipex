/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:34:02 by wshee             #+#    #+#             */
/*   Updated: 2024/11/17 12:35:13 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;

	length = ft_strlen(s);
	if (s == (NULL))
		return (NULL);
	while (length > 0 && s[length - 1] != '\0')
	{
		if (s[length] == (char) c)
			return ((char *)(s + length));
		length--;
	}
	if (s[length] == (char) c)
		return ((char *)(s + length));
	return (NULL);
}

// find first c from the end of string
//line28 check is c is null terminator
// #include <string.h>
// int main(void)
// {
// 	char* s = "hello";
// 	int n = 'e';
// 	char* result = strrchr(s, n);
// 	char* result2 = ft_strrchr(s, n);
// 	printf("r:%s\n", result);
// 	printf("r2:%s\n", result2);
// }
