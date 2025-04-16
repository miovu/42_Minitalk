/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:14:21 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 16:51:00 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	if (!s && !d)
		return (NULL);
	i = 0;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	*src = "Hello";
	char	*dest[50];
	char	*src1 = "Hello";
	char	*dest1[50];
	size_t	t = 7;
	
	const void	*result = ft_memmove(dest, src, t);
	const void	*result1 = memmove(dest1, src1, t);
	
	if (result && result1)
		printf("Memmove was successfull!");
		else
			printf("Memmove wasn't successfull!");
	return (0);
} */