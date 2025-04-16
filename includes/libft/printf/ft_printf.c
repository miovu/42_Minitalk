/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:27:16 by miovu             #+#    #+#             */
/*   Updated: 2025/01/29 14:55:14 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	skipspace(const char *s, int finder)
{
	int	i;

	i = finder;
	while (s[i] == ' ')
		i++;
	if (s[i] != '%')
		ft_putchar(' ', 1);
	return (i - finder);
}

int	ft_printf(const char *s, ...)
{
	int			finder;
	int			counter;
	va_list		args;

	va_start(args, s);
	finder = 0;
	counter = 0;
	if (!s)
		return (-1);
	while (s[finder])
	{
		if (s[finder] != '%')
			counter += ft_putchar(s[finder++], 1);
		else if (s[finder] == '%')
		{
			finder++;
			if (s[finder] == ' ')
				finder += skipspace(s, finder);
			counter += printf_format(&s[finder], args);
			if (s[finder])
				finder++;
		}
	}
	va_end(args);
	return (counter);
}

int	printf_format(const char *format, va_list args)
{
	int	print;

	print = 0;
	if (*format == 'c')
		print += ft_putchar(va_arg(args, int), 1);
	else if (*format == 's')
		print += ft_putstr(va_arg(args, char *), 1);
	else if (*format == 'p')
		print += ft_putptr(va_arg(args, void *), 1);
	if (*format == 'd' || *format == 'i')
		print += ft_putnbr(va_arg(args, int), 1);
	else if (*format == 'u')
		print += ft_putnbr_un(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		print += ft_putnbr_hex(va_arg(args, unsigned int), 'x', 1);
	else if (*format == 'X')
		print += ft_putnbr_hex(va_arg(args, unsigned int), 'X', 1);
	else if (*format == '%')
		print += ft_putchar('%', 1);
	return (print);
}

/* #include <stdio.h>
int main()
{
	char *ptr = "Margott";
	char *ptr1 = NULL;
	ft_printf("%   dOWN\n\n", 1);
	int	own = ft_printf("INT: %i\nUNS: %u\nDEC: %d\nhex: %x\nHEX: %X\n
	STR: %s\nCHR: %c\nPTR: %p\n %p\n %% % % % %\n", 1, 1, 1, 3000, 3000, 
	"asas", 'a', ptr, ptr1);
	ft_printf("\nCounter: %d\n\n\n", own);
	printf("%   dORIGINAL\n\n", 1);
	int	og = printf("INT: %i\nUNS: %u\nDEC: %d\nhex: %x\nHEX: %X\n
	STR: %s\nCHR: %c\nPTR: %p\n %p\n %% % % % %\n", 1, 1, 1, 3000, 3000, 
	"asas", 'a', ptr, ptr1);
	printf("\nCounter: %d\n\n\n", og);
	
	char *a = NULL; 
	ft_printf(" NULL %s NULL ", a);
	char *b = NULL;
	printf(" NULL %s NULL ", b);
	ft_printf("%")
	printf("%d\n", ft_printf("%"));
	printf("%d", printf("%"));
} */