/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:37:54 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 18:51:01 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}

/* #include <stdio.h>
int	main()
{
	const char	*str = "Hello World!";
	int			c = 'o';
	const char	*str1 = "Hello World!";
	int			d = 'o';
	
	char	*result= ft_strrchr(str, c);
	char	*result1= ft_strrchr(str1, d);
	
	if (result == result1)
		printf("Char %c, was found in %s\n.", c, str);
		else
			printf("Char was not found..");
	return (0);
} */