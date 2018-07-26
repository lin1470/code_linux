//
// Created by bruce on 18-5-19.
//
#include <unistd.h>
#include <cstdio>
#include <signal.h>
#include <sys/wait.h>
#include <cstdlib>
int main()
{
    int num=0;
    alarm(1);
    while(1)
        printf("%d\n",num++);
    return 0;
}