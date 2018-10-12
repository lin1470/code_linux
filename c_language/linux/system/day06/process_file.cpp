//
// Created by bruce on 18-5-17.
//
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
int main(int argc,const char* argv[])
{
    int fd = open("temp",O_CREAT|O_RDWR,0664);
    if(fd == -1)
    {
        perror("open error");
        exit(1);;
    }
    pid_t pid = fork();
    if(pid == -1)
    {
        perror("fork error:");
        exit(1);
    }
    if(pid >0)
    {
        const char *p = "whtat hh";
        write(fd,p,strlen(p)+1);
        close(fd);
    }
    else if(pid ==0)
    {
        //子进程,先睡眠保证父进程可以完全写进去
        sleep(1);
        char buf[1024];
        lseek(fd,0,SEEK_SET);
        int len = read(fd,buf,sizeof(buf));
        printf("%s\n",buf);
        close(fd);

    }
    return 0;
}