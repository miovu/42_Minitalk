/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:42:27 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 16:49:12 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int	main()
{
	char	*src = NULL;
	char	*dest = NULL;
	char	*src1 = NULL;
	char	*dest1 = NULL;
	size_t	t = 7;
	
	const void	*result = ft_memcpy(dest, src, t);
	const void	*result1 = memcpy(dest1, src1, t);
	
	if (result && result1)
		printf("Memcpy was successfull!");
		else
			printf("Memcpy wasn't successfull!");
	return (0);
} */