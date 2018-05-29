//
// Created by bruce on 18-5-18.
//
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <sys/wait.h>

//
// Created by bruce on 18-5-18.
//
int main()
{
    int fd[2];
    int ret = pipe(fd);
    if(ret == -1){
        perror("pipe error");
        exit(1);
    }
//    pid_t pid = fork();
    int i =0;
    pid_t pid;
    for(i =0;i<2;i++)
    {
        pid = fork();
        if(pid == 0)
            break;
    }
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    //子进程1
    if(i==0)
    {
        //父进程
        // 关闭读端
        close(fd[0]);
        //文件描述符重定向
        // stdout_fileno 管道的写端
        dup2(fd[1],STDOUT_FILENO);
        //执行ps_aux
        execlp("ps","ps","aux",NULL);
        perror("execlp");
        exit(1);
    }
    else if(i==1)
    {
        //子进程2
        // 进程读,关闭写
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("grep","grep","--color=auto","zsh",NULL);
        perror("execlp");
        exit(1);
        // 写管道的操作
    }
    else if(i==2)
    {
        close(fd[0]);
        close(fd[1]);
        pid_t wpid;
        while((wpid = waitpid(-1,NULL,WNOHANG))!= -1)
        {
            //当返回值是-1的时候,就是出错了,这时候所有的子进程都被回收了
            if(wpid ==0)
                continue;
            printf("the died child is %d\n",wpid);
        }
    }
//    printf("pipe[0] =  %d\n",fd[0]);
//    printf("pipe[1]= %d\n",fd[1]);
//    close(fd[0]);
//    close(fd[1]);
    return 0;
}

