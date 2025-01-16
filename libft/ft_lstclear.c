/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:01:16 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:47:27 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		del(temp->content);
		free(temp);
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// temp is created to
// delete and free the entire  node
// int main(void)
// {
// 	char str[] = "Hello";
// 	char *content = ft_strdup(str);
// 	if (content == NULL)
// 		return (1);
// 	t_list *node = ft_lstnew(content);
// 	if (node == NULL)
// 		return(1);
// 	printf("%s\n", (char *)node->content);
// 	ft_lstclear(&node, del);
// 	node = NULL;
// 	//the node points to freed (deallocated) memory,
// 	//avoid dereferencing after the node is deleted
// 	if (node == NULL)
// 		printf("Successful!\n");
// 	else
// 		printf("Failed!\n");
// 	return (0);
// }
