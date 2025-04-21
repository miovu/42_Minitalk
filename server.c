#include "minitalk.h"

void    handle_bit(int signal)
{
    static unsigned char c = 0;
    static unsigned int count = 0;

    c <<= 1;
    if (signal == SIGUSR2)
        c |= 1;
    count++;
    if (count == 8)
    {
        if (c == 0)
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        c = 0;
        count = 0;
    }
}

int main()
{
    pid_t   pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    signal(SIGUSR1, handle_bit);
    signal(SIGUSR2, handle_bit);
    while (1)
        usleep(100);
    return (0);

}
