//
// Created by bruce on 18-11-5.
//

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int i;
    pid_t  pid;
    printf("xxxxxxxxxxxxx\n");
    for(i = 0;i<5;i++)
    {
        pid = fork();
        if(pid == -1)
        {
            perror("fork error");
            exit(1);
        }
        else if(pid ==0)
            break;
        {
            printf("i create the child id is %d\n",pid);
        }
    }
    sleep(i);
    if(i < 5)
    {
//        sleep(i);
        printf("i am the %d child %d, parent is %d\n",i,getpid(),getppid());
    }
    else
    {
//        sleep(i);
        printf("i am parent %d\n",getpid());

    }

    return 0;
}