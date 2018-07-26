#include <unistd.h>
#include <cstdio>
#include <cstdlib>

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
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    if(pid >0)
    {
        // 进程写操作
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execlp("grep","grep","--color=auto","zsh",NULL);
        perror("execlp");
        exit(1);
    }
    else if(pid ==0)
    {
        // 写管道的操作
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
//    printf("pipe[0] =  %d\n",fd[0]);
//    printf("pipe[1]= %d\n",fd[1]);
    close(fd[0]);
    close(fd[1]);
    return 0;
}
