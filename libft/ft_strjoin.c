/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:26:56 by wshee             #+#    #+#             */
/*   Updated: 2025/01/09 13:36:29 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (s1 == (NULL) || s2 == (NULL))
		return (NULL);
	strjoin = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (strjoin == (NULL))
		return (NULL);
	ft_strlcpy(strjoin, s1, len1 + 1);
	ft_strlcat(strjoin, s2, len1 + len2 + 1);
	return (strjoin);
}

// int main (void)
// {
// 	char *s1 = "Hello";
// 	char *s2 = " World";
// 	char *res = ft_strjoin(s1, s2);
// 	printf("%s\n", res);
// 	free(res);
// }
