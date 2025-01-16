/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshee <wshee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:55:45 by wshee             #+#    #+#             */
/*   Updated: 2024/11/25 17:51:03 by wshee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = (void *)malloc (nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

//nmemb = number of elements in array
//size = size of each element in bytes
//if nmemb or size = 0, it returns a valid ptr that can be safely freed
//line26 cehck for overflow
//size_t-1 bytes is maximum value of size_t
// int main(void)
// {
// 	char *ptr;
// 	ptr = ft_calloc(0, 0);
// 	// if (ptr == NULL)
// 	// {
// 	// 	printf("Failed! %zu\n", (size_t)-1);
// 	// }
// 	// else
// 	// {
// 	// 	printf("Successful\n");
// 	// 	free(ptr);
// 	// }
// }
