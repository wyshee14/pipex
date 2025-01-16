/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:10:27 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:33:56 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

//**lst double pointer holds the address of pointer pointing to the list */
//line21 dereference lst to new as the fist element
// int main(void)
// {
// 	t_list *ptr = NULL;
// 	t_list *node1 = ft_lstnew("Node1");
// 	t_list *node2 = ft_lstnew("Node2");
// 	ft_lstadd_front(&ptr, node1);
// 	ft_lstadd_front(&ptr, node2);
// 	while(ptr)
// 	{
// 		printf("%s -> ", (char *)ptr -> content);
// 		ptr = ptr-> next;
// 	}
// 	free(node2);
// 	free(node1);
// }
