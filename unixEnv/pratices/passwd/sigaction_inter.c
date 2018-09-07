#include <stdio.h>
#include "../tool/apue.h"
#include <signal.h>

typedef void Sigfunc(int);
Sigfunc *mysignal(int signo,Sigfunc *func)
{
    struct sigaction act,oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
//    if(signo == SIGALRM)
//    {
//#ifdef SA_INTERRUPT
//        act.sa_flags |= SA_INTERRUPT;
//        printf("the flags include the interruption\n");
//#endif
//    }
//    else
//    {
//
//    }
#ifdef SA_INTERRUPT 
    act.sa_flags |= SA_INTERRUPT;
    printf("the flags include the interruption\n");
#endif
    if(sigaction(signo,&act,&oact)<0)
        return(SIG_ERR);
    return oact.sa_handler;
}
void signalfunc(int signo)
{
    printf("hello signalfunc, the signal is %d\n",signo);
}
int main()
{
    if((mysignal(SIGQUIT, signalfunc)) == SIG_ERR)
    {
        err_sys("mysignal wrong");
    }

    while(1);
    printf("Hello world\n");
    return 0;
}

