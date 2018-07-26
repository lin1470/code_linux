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
    if(ret == -1)
    {
        perror("pipe error:");
        exit(1);
    }
    long size = fpathconf(fd[0],_PC_PIPE_BUF);
    printf("size = %ld\n",size);
    close(fd[0]);
    close(fd[1]);
    return 0;
}
