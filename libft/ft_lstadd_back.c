/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:09:09 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:46:48 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

//line19 check if there is no list at all or check if is a null pointer
//line21 if head of lst id null, assign the list to new
//line26 if the lst is not empty, then find the last node
//line27 address the last to new
// int main(void)
// {
// 	t_list *list = NULL;
// 	t_list *node1 = ft_lstnew("Node1");
// 	t_list *node2 = ft_lstnew("Node2");
// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);
// 	while(list)
// 	{
// 		printf("%s -> ", (char *)list -> content);
// 		list = list-> next;
// 	}
// 	free(node2);
// 	free(node1);
// }
