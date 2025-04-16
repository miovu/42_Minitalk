/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:03:42 by miovu             #+#    #+#             */
/*   Updated: 2024/11/16 16:54:01 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numb_len(int nb)
{
	int	len;

	len = 1;
	while (nb / 10 != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	fill_str(char *str, int nb, int len)
{
	str[len] = '\0';
	while (--len >= 0)
	{
		str[len] = '0' + (nb % 10);
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_negative;

	is_negative = (n < 0);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numb_len(n) + is_negative;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (is_negative)
	{
		str[0] = '-';
		n = -n;
	}
	fill_str(str + is_negative, n, len - is_negative);
	return (str);
}

/* #include <stdio.h>
int	main()
{
	int	nbr = 57;

	printf("Itoa: %s", ft_itoa(nbr));
	return (0);
} */