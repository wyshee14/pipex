/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:32:52 by wshee             #+#    #+#             */
/*   Updated: 2024/11/19 14:04:18 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == (NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0' || little == big)
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)big + i);
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

//The function finds the small string inside a big string
// Return pointer to the first occurence of little in the string
//line23 if little is not found in big the big string is returned
// int main(void)
// {
// 	char str1[] = "Hello World";
// 	char tofind[] = "W";
// 	char *res = ft_strnstr(str1, tofind, 10);
// 	printf("%s\n", res);
// }
