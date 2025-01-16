/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:08:24 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:48:38 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == (NULL))
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// int main (void)
// {
// 	char *content = "Hello";
// 	t_list *node = ft_lstnew(content);
// 	if (node == NULL)
// 	{
// 		printf("Failed\n");
// 		return(1);
// 	}
// 	if (node->content != content)
// 	{
// 		printf("Failed\n");
// 		free(node);
// 		return(1);
// 	}
// 	if (node->next != NULL)
// 	{
// 		printf("Failed\n");
// 		free(node);
// 		return(1);
// 	}
// 	else
// 		printf("Successful!\n");
// 	free(node);
// }
