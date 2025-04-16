/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:59:52 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 18:10:54 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	n;
	unsigned int	dcount;

	i = 0;
	n = 0;
	dcount = 0;
	while (dest[i])
		i++;
	while (src[dcount])
		dcount++;
	if (size <= i)
		dcount += size;
	else
		dcount += i;
	while (src[n] && (i + 1) < size)
	{
		dest[i] = src[n];
		i++;
		n++;
	}
	dest[i] = '\0';
	return (dcount);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	const char	*source = NULL;
	char	destination[3];
	const char	*source1 = NULL;
	char	destination1[3];
	size_t		i = 1;
	unsigned int j;
	unsigned int k;

	j = ft_strlcat(destination, source, i);
	k = strlcat(destination1, source1, i);
	if (j == k)
		printf("Success!");
		else
			printf("Failed...");
	return (0);
} */