/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:42:47 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 14:34:06 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

//line18 check for null pointer and del function
//line20 delete the content in the list
// delete a node
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
// 	ft_lstdelone(node, del);
// 	node = NULL;
// 	//the node points to freed (deallocated) memory,
//	//avoid dereferencing after the node is deleted
// 	if (node == NULL)
// 		printf("Successful!\n");
// 	else
// 		printf("Failed!\n");
// 	return (0);
// }
