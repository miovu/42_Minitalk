#include "minitalk.h"

void    send_char(pid_t pid, char c)
{
    int bit;

    bit = 7;
    while (bit >= 0)
    {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(100);
        bit--;
    }
}

int main(int ac, char **av)
{
    int i = 0;
    char *message;
    pid_t server;

    if (ac == 3)
    {
        server = (pid_t)atoi(av[1]);
        message = av[2];
        while (message[i])
        {
            send_char(server, message[i]);
            i++;
        }
    }
    send_char(server, '\0');
    return (0);
}