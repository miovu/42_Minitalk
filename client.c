/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miovu <miovu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:47:49 by miovu             #+#    #+#             */
/*   Updated: 2025/04/22 15:02:26 by miovu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack = 0;

void	handle_ack(int signal)
{
	if (signal == SIGUSR1)
		printf("\033[0;32m✅ Message received!\033[0m\n");
	if (signal == SIGUSR2)
		g_ack = 1;
}

void	ft_error(void)
{
	ft_printf("❌ \033[0;31mInvalid Arguments.\033[0m\nUsage:\n \
		./client [server_pid] [message]\n");
	exit(EXIT_SUCCESS);
}

void	send_char(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (g_ack == 0)
			usleep(50);
		g_ack = 0;
		bit--;
	}
}

int	main(int ac, char **av)
{
	int		i;
	char	*message;
	pid_t	server;

	i = 0;
	if (ac != 3)
	{
		ft_error();
		return (1);
	}
	server = (pid_t)ft_atoi(av[1]);
	message = av[2];
	signal(SIGUSR1, handle_ack);
	signal(SIGUSR2, handle_ack);
	while (message[i])
	{
		send_char(server, message[i]);
		i++;
	}
	send_char(server, '\0');
	return (0);
}
