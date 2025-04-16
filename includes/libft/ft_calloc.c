/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:41:51 by miovu             #+#    #+#             */
/*   Updated: 2024/11/21 14:31:44 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	result;

	result = nmemb * size;
	if (!result)
		return (malloc(0));
	if (result / size != nmemb)
		return (NULL);
	ptr = malloc(result);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, result);
	return (ptr);
}

/* #include <stdio.h>
int main()
{
	char *i = ft_calloc(4, 5);
	char *a = calloc(4, 5);
	printf("%p\n", i);
	printf("%p\n", a);
	free(i);
	free(a);
} */