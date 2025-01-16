/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:37:05 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:34:15 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

//if lst is NULL means it is the last list and return NULL
// int main(void)
// {
// 	t_list *node1 = ft_lstnew("Node1");
// 	t_list *node2 = ft_lstnew("Node2");
// 	t_list *node3 = ft_lstnew("Node3");

// 	node1->next = node2;
// 	node2->next = node3;

// 	t_list *last = ft_lstlast(node1);
// 	printf("%s\n",(char *)last->content);

// 	free(node1);
// 	free(node2);
// 	free(node3);
// }
