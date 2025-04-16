/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:59:41 by miovu             #+#    #+#             */
/*   Updated: 2025/01/29 14:55:21 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long long nbr, char c, int fd)
{
	char	*hex;
	int		counter;

	counter = 0;
	hex = LC_HEX;
	if (c == 'X')
		hex = UP_HEX;
	if (nbr > 15)
		counter += ft_putnbr_hex(nbr / 16, c, fd);
	counter += ft_putchar(hex[nbr % 16], fd);
	return (counter);
}

int	ft_putptr(void *ptr, int fd)
{
	unsigned long long	nbr;
	int					counter;

	counter = 0;
	nbr = (unsigned long long)ptr;
	if (ptr == NULL)
		counter += write(fd, "(nil)", 5);
	else
	{
		counter += write(fd, "0x", 2);
		counter += ft_putnbr_hex(nbr, 'x', fd);
	}
	return (counter);
}
