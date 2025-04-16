/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:17:12 by chillhoneyy       #+#    #+#             */
/*   Updated: 2025/03/03 14:22:32 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (str1 == NULL || str2 == NULL || n <= 0)
		return (0);
	while (*str1 == *str2 && n > 0 && *str1 != '\0')
	{
		++str1;
		++str2;
		--n;
	}
	return (*str1 - *str2);
}

/* #include <stdio.h>
int	main()
{
	const char	*str1 = "Hello";
	const char	*str2 = "HeLlo";
	size_t		i = 5;
	int			j;
	
	j = ft_strncmp(str1, str2, i);
	printf("Result: %d\n", j);
	return (0);
} */