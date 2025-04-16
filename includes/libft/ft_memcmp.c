/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:13:58 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 16:39:10 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	*str1 = "Hello World";
	char	*str2 = "HeLlo World";
	char	*str3 = "Hello World";
	char	*str4 = "HeLlo World";
	size_t	n = 10;
	int		i;
	int		j;
	
	i = ft_memcmp(str1, str2, n);
	j = memcmp(str3, str4, n);

	if (i && j)
		printf("Memcmp was successfull!\n");
		else
			printf("Memcmp wasn't successfull!");
	return (0);
} */