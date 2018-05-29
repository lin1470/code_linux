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

    //自定义信号集合
    sigset_t myset;
    //清空集合
    sigemptyset(&myset);
    //添加阻塞的信号
    sigaddset(&myset,SIGINT); //crtl+c
    sigaddset(&myset,SIGQUIT); // ctrl+反斜杠
    sigaddset(&myset,SIGKILL);
    sigprocmask(SIG_BLOCK,&myset,NULL);

    //每1s赌一次内存的未决信号集
    while(1)
    {
        sigset_t pendset;
        sigpending(&pendset);
        //1~31
        for(int i=1;i<=31;i++){
            if(sigismember(&pendset,i))
                printf("1");
            else printf("0");
        }
        printf("\n");
        sleep(1);
    }
    return 0;
}