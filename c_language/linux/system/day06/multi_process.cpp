//
// Created by bruce on 18-5-17.
//
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int num = 3;
    int i =0;
    pid_t pid;

    for(i =0;i<num;i++)
    {
        pid = fork();
        if(pid ==0)
            break;
    }
    if(i ==0)
    {
        execlp("ps","ps","aux",NULL);
        perror("execlp ps");
        exit(1);
    }
    else if(i ==1)
    {
        execl("./hello","hello",NULL);
        perror("execl error");
        exit(1);
    }
    else if(i ==2)
    {
        execl("./error","error",NULL);
        perror("execl error");
        exit(1);
    }
    else if(i == num)
    {
        int status;
        pid_t wpid;
        while((wpid = waitpid(-1,&status,WNOHANG))!= -1)//不会等待
        {
            if(wpid ==0)
                continue; //如果是返回值是0,意味着当前没有可回收子进程
            printf("-------child died pid = %d\n",wpid);
            if(WIFEXITED(status))//判断是否是return退出的
            {
                printf("return value %d\n",WEXITSTATUS(status));
            }
            else if(WIFSIGNALED(status))//判断是否是exit退出的.
            {
                printf("died by signal: %d \n",WTERMSIG(status));
            }
        }
    }
}
