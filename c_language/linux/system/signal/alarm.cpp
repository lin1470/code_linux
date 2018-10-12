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
    int ret =alarm(5);
    printf("ret = %d\n",ret);

    sleep(2);
    ret = alarm(6); // 闹钟重置了
    printf("ret = %d\n",ret);

    while(1)
    {
        printf("hello,world\n");
        sleep(2);
    }
    return 0;
}