/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:29:27 by wshee             #+#    #+#             */
/*   Updated: 2024/11/15 18:14:11 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *content)
// {
// 	char	*str = (char *)content;
// 	while (*str)
// 	{
// 		*str -= 32;
// 		str++;
// 	}
// }

// int main(void)
// {
// 	t_list *node = ft_lstnew(ft_strdup("hello"));
// 	if (node == NULL)
// 		return(1);
// 	ft_lstiter(node,f);
// 	printf("%s\n", (char *)node->content);
// 	free(node->content);
// 	free(node);
// }
