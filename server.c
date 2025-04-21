#include "minitalk.h"

void    handle_bit(int signal, siginfo_t *info, void *context)
{
    static unsigned char c = 0;
    static unsigned int count = 0;

	(void)context;
    c <<= 1;
    if (signal == SIGUSR2)
        c |= 1;
    count++;
    if (count == 8)
    {
        if (c == 0)
        {
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
        else
            write(1, &c, 1);
        c = 0;
        count = 0;
    }
	kill(info->si_pid, SIGUSR2);
}

int main()
{
	struct	sigaction sa;

	sa.sa_sigaction = handle_bit;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
