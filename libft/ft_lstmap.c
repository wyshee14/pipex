/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:38:33 by wshee             #+#    #+#             */
/*   Updated: 2024/11/18 21:08:52 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !del || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void *f(void *content)
// {
//     char *str = (char *)content;
//     char *new_str = ft_strdup(str); // Duplicate the string
//     if (!new_str)
//         return (NULL); // Return NULL if allocation fails

//     // Convert all characters to uppercase
//     for (int i = 0; new_str[i]; i++)
//         new_str[i] = ft_toupper(new_str[i]);

//     return (new_str);
// }

// // Delete function: Frees the memory allocated for a node's content
// void del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     // Create the original list
//     t_list *list = ft_lstnew(ft_strdup("hello"));
//     t_list *node2 = ft_lstnew(ft_strdup("world"));
//     t_list *node3 = ft_lstnew(ft_strdup("libft"));

//     // Link nodes
//     ft_lstadd_back(&list, node2);
//     ft_lstadd_back(&list, node3);

//     // Display the original list
//     printf("Original list:\n");
//     t_list *temp = list;
//     while (temp)
//     {
//         printf("%s\n", (char *)temp->content);
//         temp = temp->next;
//     }

//     // Apply `ft_lstmap` to create a mapped list
//     t_list *mapped_list = ft_lstmap(list, f, del);
//     if (!mapped_list)
//     {
//         printf("Error: ft_lstmap failed\n");
//         ft_lstclear(&list, del); // Clean up original list
//         return (1);
//     }

//     // Display the mapped list
//     printf("\nMapped list:\n");
//     temp = mapped_list;
//     while (temp)
//     {
//         printf("%s\n", (char *)temp->content);
//         temp = temp->next;
//     }

//     // Clean up memory
//     ft_lstclear(&list, del);        // Free the original list
//     ft_lstclear(&mapped_list, del); // Free the mapped list

//     return 0;
// }
