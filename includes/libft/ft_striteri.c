/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:20:42 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 19:26:13 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* #include <stdio.h>
#include <ctype.h>
void	to_uppe_lower_rcase(unsigned int index, char *c)
{
	if (index % 2 == 0)
		*c = (char)toupper((unsigned char)*c);
	else
		*c = (char)tolower((unsigned char)*c);
}

int main()
{
	char str[] = "hello world!";
	
	ft_striteri(str, to_uppe_lower_rcase);
	printf("Modified string: %s\n", str);
	return 0;
} */