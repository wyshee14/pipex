/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:30:25 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:36:29 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != 0)
	{
		counter++;
	}
	return (counter);
}

// //int	main(void)
// {
// 	char	*s = "abcdefg";
// 	printf("%zu\n", ft_strlen(s));
// }
