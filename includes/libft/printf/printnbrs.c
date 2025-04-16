/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:51:45 by miovu             #+#    #+#             */
/*   Updated: 2025/01/27 12:59:13 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr, int fd)
{
	int	counter;

	counter = 0;
	if (nbr == -2147483648)
		counter += ft_putstr("-2147483648", fd);
	else
	{
		if (nbr < 0)
		{
			counter += ft_putchar('-', fd);
			nbr = nbr * -1;
		}
		if (nbr > 9)
			counter += ft_putnbr(nbr / 10, fd);
		counter += (ft_putchar((nbr % 10) + '0', fd));
	}
	return (counter);
}

int	ft_putnbr_un(unsigned int nbr, int fd)
{
	int	counter;

	counter = 0;
	if (nbr > 9)
		counter += ft_putnbr_un(nbr / 10, fd);
	counter += ft_putchar((nbr % 10) + '0', fd);
	return (counter);
}
