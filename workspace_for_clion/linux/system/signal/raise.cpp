//
// Created by bruce on 18-5-19.
//

#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>

int main ()
{
    pid_t pid = fork();
    if(pid >0)
    {
        int s;
        pid_t wpid = wait(&s);
        printf("child died pid = %d\n,wpid");
        if(WIFSIGNALED(s)){
            printf("died by signal:%d\n",WTERMSIG(s));
        }
    }
    else if(pid ==0)
    {
//        raise(SIGINT);
        while(1)
        {
            abort();
        }
    }
    return 0;
}