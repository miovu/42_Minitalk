/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:42:12 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 18:45:35 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (little[h] == '\0')
		return ((char *)big);
	while (big[h])
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < len)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return ((char *) big + h);
			n++;
		}
		if (little[n] == '\0')
			return ((char *) big + h);
		h++;
	}
	return (0);
}

/* #include <stdio.h>
int	main()
{
	const char	*b = "Hello World!";
	const char	*l = "World!";
	size_t		s = 20;
	char		*i;
	
	i = ft_strnstr(b, l, s);
	printf("Found at %s\n", i);
	return (0);
} */