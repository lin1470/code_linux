#include <stdio.h>
#include <signal.h>
#include "../tool/apue.h"
#include <stdlib.h>
void signal_quit(int signo)
{
    printf("caught the SIGQUIT signal\n");
    return;
}

int main()
{
    /* register the function to SIGQUIT */
    if(signal(SIGQUIT,signal_quit)==SIG_ERR)
    {
        err_quit("signal funcion wrong");
    }
    
    sigset_t newSet,oldSet;
    sigemptyset(&newSet);
    sigemptyset(&oldSet);
    sigaddset(&newSet,SIGQUIT);
    if(sigprocmask(SIG_BLOCK,&newSet,&oldSet)<0)
        err_sys("sigprocmask error");
    printf("sleep for 5 secends\n");
    sleep(5);
    
    if(sigpending(&newSet)<0)
        err_sys("sigpending error");
    if(sigismember(&newSet,SIGQUIT))
        printf("pending signal is %d",SIGQUIT);

    printf("ublock the signal %d",SIGQUIT);
    if(sigprocmask(SIG_SETMASK,&oldSet,NULL)<0)
        err_sys("ublock the signal error");
    printf("sleep for 10 secends\n");
    sleep(10);
    printf("Hello world\n");
    return 0;
}

