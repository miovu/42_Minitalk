/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:55:38 by chillhoneyy       #+#    #+#             */
/*   Updated: 2024/11/18 19:41:20 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/* #include <stdio.h>
int	main(void)
{
	char c = 'A';
	printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

	c = '1';
	printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

	c = '!';
	printf("Is '%c' alphanumeric? %d\n", c, ft_isalnum(c));

	return 0;
} */