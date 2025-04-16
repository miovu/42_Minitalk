/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:39:28 by miovu             #+#    #+#             */
/*   Updated: 2024/11/18 19:38:59 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	size_t			len;

	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* #include <stdio.h>
#include <ctype.h>
char	to_upper_lower_case(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (char)toupper((unsigned char)c);
	else
		return (char)tolower((unsigned char)c);
}

int main()
{
	char	*str = "hello world!";
	
	char	*dup = ft_strmapi(str, to_upper_lower_case);
	if (dup)
	{
		printf("Modified string: %s\n", dup);
		free(dup);
	}
	else
		printf("Memory allocation failed.\n");
	return 0;
} */