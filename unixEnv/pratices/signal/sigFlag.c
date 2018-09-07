#include <stdio.h>
#include "../tool/apue.h"

int fig_flag = 0;
int main()
{
    void sig_func(int sig);
    signal(SIGQUIT,sig_func);
    for(int i=0;i<100;i++);
    while(fig_flag==0)
    {
        signal(SIGQUIT,sig_func);
        printf("pause...\n");
        pause();
    }
    printf("wake up\n");
    return 0;
}

void sig_func(int sig)
{
    printf("sig_funcion \n");
    fig_flag = 1;
}

