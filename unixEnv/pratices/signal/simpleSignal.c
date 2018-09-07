#include <stdio.h>
#include "../tool/apue.h"

void sigFunc(int);

int main()
{
    if(signal(SIGQUIT,sigFunc) == SIG_ERR)
    {
        err_sys("signal function error");
    }
    if(signal(SIGTERM,sigFunc) == SIG_ERR)
    {
        err_sys("signal function error");
    }
    kill(getpid(),SIGTERM);
    kill(getpid(),SIGQUIT);
    for(;;)
        pause();
    return 0;
}

void sigFunc(int sig)
{
    if(sig == SIGQUIT)
    {
        printf("recevie the sigquit signal\n");
    }
    else if(sig == SIGTERM)
    {
        printf("recevie the sigterm signal\n");
    }
}

