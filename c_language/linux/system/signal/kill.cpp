

#include <unistd.h>
#include <cstdio>
#include <signal.h>

//
// Created by bruce on 18-5-19.
//
int main()
{
    pid_t pid = fork();
    if(pid >0)
    {
        while(1)
        {
            printf("parent process,%d\n",getpid());
            sleep(1);
        }
    }
    else if(pid ==0)
    {
        kill(getppid(),SIGKILL);
        sleep(2);
    }
    return 0;
}
