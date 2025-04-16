/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:58:28 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 16:32:13 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == chr)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	*str = "Hello world";
	int		c = 'o';
	size_t	j = 10;

	char	*result = ft_memchr(str, c, j);
	char	*result1 = memchr(str, c, j);

	if (result && result1)
		printf("Char %c was found in %s!\n", c, str);
		else
			printf("Char %c wasn't found in %s!\n", c, str);
	return (0);
} */