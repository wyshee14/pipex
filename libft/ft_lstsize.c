/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:28:56 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:48:20 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst-> next;
	}
	return (counter);
}

// int main(void)
// {
// 	t_list *node1 = ft_lstnew("Node1");
// 	t_list *node2 = ft_lstnew("Node2");
// 	t_list *node3 = ft_lstnew("Node3");

// 	node1->next = node2;
// 	node2->next = node3;

// 	int size = ft_lstsize(node1);
// 	printf("%d\n", size);

// 	free(node3);
// 	free(node2);
// 	free(node1);
// }
