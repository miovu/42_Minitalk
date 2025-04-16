/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:54:52 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 18:29:01 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char *src, size_t size)
{
	size_t	count;
	size_t	src_len;

	src_len = ft_strlen(src);
	count = 0;
	if (size == 0)
		return (src_len);
	while (src[count] && count < (size - 1))
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (src_len);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	const char	*source = "Hello";
	char	destination[3];
	const char	*source1 = "Hello";
	char	destination1[3];
	size_t		i = 1;
	size_t j;
	size_t k;

	j = ft_strlcpy(destination, source, i);
	printf("%zu\n", j);
	k = strlcpy(destination1, source1, i);
	printf("%zu", k);
	if (j == k)
		printf("Success!");
		else
			printf("Failed...");
	return (0);
} */