/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:29:41 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:32:33 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) == 1) || (ft_isdigit(c) == 1))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;
// 	int		a;

// 	c = '&';
// 	a = ft_isalnum(c);
// 	printf("%d\n", a);
// }
