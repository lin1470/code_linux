//
// Created by bruce on 18-5-19.
//

#include <signal.h>
#include <unistd.h>
#include <cstdlib>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid >0)
    {
        exit(1);
    }
    else if(pid ==0)
    {
        setsid();
        while(1);
    }
    return 0;
}