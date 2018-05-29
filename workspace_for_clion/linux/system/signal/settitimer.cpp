//
// Created by bruce on 18-5-19.
//
#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
#include <sys/time.h>

int main()
{
    struct itimerval new_val;
    new_val.it_value.tv_sec = 2;
    new_val.it_value.tv_usec = 0;
    new_val.it_interval.tv_usec = 0;
    new_val.it_interval.tv_sec = 1;
    setitimer(ITIMER_REAL,&new_val,NULL);

    while(1)
    {
        printf("hello world \n");
        sleep(1);
    }
    return 0;
}
