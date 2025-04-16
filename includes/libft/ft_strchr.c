/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:20:55 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 17:05:25 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	const char	*str = "Hello";
	int			i = 'o';

	char	*result = ft_strchr(str, i);
	char	*result1 = strchr(str, i);

	if (result && result1)
		printf("Found char - %c - in %s\n", i , str);
		else
			printf("Char not found");
	return (0);
} */