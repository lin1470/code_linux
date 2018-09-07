#include "../tool/apue.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define maxlines 100

int main(int argc,char *argv[])
{
    pid_t pid;
    if(argc != 2)
    {
        err_quit("usage is %s file ",argv[0]);
    }
    int fd[2];
    if(pipe(fd)<0)
        err_sys("pipe error!");
    if((pid = fork())<0)
        err_quit("fork error!");
    else if(pid >0)
    {
        //parent
        close(fd[0]); // close the read end
        FILE *fp = fopen(argv[1],"r");//read only open a file
        char line[maxlines];
        while((fgets(line,maxlines,fp)) != NULL)
        {
            int n = strlen(line);
            char buf[MAXLINE];
            if (write(fd[1],buf,n) != n)
            {
                err_sys("write to pipe error!");
             }       
            printf("writelines done!\n");
        }
        close(fd[1]);// close the write end, if not, the pipe is busy
        if(waitpid(pid,NULL,0)<0)
            err_sys("waitpid error");
        printf("waitpid done\n");
        exit(0);

    }
    else
    {
        //children
        close(fd[1]); //close the write end
        if(fd[0] != STDIN_FILENO)
            if(dup2(fd[0],STDIN_FILENO) != STDIN_FILENO)
                err_sys("dup2 error");
        printf("fd[0] is %d\nthe STDIN_FILENO is %d\n",fd[0],STDIN_FILENO);
        if(execlp("less","less",(char*)0)<0)
            err_sys("execlp error");
        close(fd[0]);
        exit(0);
    }
}
