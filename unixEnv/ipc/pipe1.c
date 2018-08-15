#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
int main()
{
    int n;
    int fd[2];
    pid_t pid;
    char buf[100];
    if(pipe(fd)<0)
        perror("pipe error!\n");
    if((pid = fork())<0)
        perror("fork error\n");
    if(pid > 0)
    {
        //parent
        close(fd[0]);
        write(fd[1],"hello",5);
        close(fd[1]);

    }
    else if(pid == 0)
    {
        //chilren
        close(fd[1]);
        if(read(fd[0],buf,100)<0)
            perror("read error!\n");
        printf("%s\n",buf);
        close(fd[0]);
        exit(0);
    }

    return 0;
}

