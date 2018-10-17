//
// Created by bruce on 18-10-17.
//
#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>
#include <signal.h>
#include <sys/wait.h>

void sigcld(int signo)
{
    printf("received the sigal no %d",signo);
    //if(signal(SIGCLD,sigcld)==SIG_ERR)
     //   exit(1);
    pid_t pid;
    int status;
    if((pid = wait(&status))<0)
        exit(1);
    printf("recevied the signo from %d(pid)",pid);
}
int main()
{
    pid_t pid;
    if(signal(SIGABRT,sigcld)==SIG_ERR)
    {
        exit(1);
    }
    if((pid = fork())<0)
        exit(1);
    if(pid >0)
    {
        // parent
        while(1); //父进程不断执行,这样子就会产生僵尸进程,无法处理
    }
    else if(pid == 0)
    {
        printf("i am the child \n");
        abort();
    }
    return 0;

}
