//
// Created by bruce on 18-11-5.
//

#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>


int var =100;
int main()
{
    pid_t  pid;
    pid = fork();
    if(pid == -1)
    {
        perror("fork error!");
        exit(1);
    }
    if(pid == 0)
    {
        // child
        var = 10;
        printf("i am the child %d, the var is %d\n",getpid(),var);
    }
    else
    {
        sleep(1);
        printf("i am the parent %d,the var is %d\n",getpid(),var);
    }
    return 0;
}