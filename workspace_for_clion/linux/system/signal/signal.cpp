//
// Created by bruce on 18-5-19.
//

#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
#include <sys/time.h>

void myfunc(int no)
{
    printf("cath your signal : %d\n",no);
}

int main()
{
    signal(SIGINT,myfunc);
    while(1)
    {
        sleep(1);
        printf("hello \n");
    }
    return 0;
}