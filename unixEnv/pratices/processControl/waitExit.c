#include "../tool/apue.h"
#include <sys/wait.h>

int preExit(int status)
{
    printf("the status is %d\n",status);
    if(WIFEXITED(status))
    {
        printf("the procession is exited normally\n");
    }
    else if(WIFSIGNALED(status))
    {
        printf("the procession is stopped by signal %d\n",status);
    }
    else if(WIFSTOPPED(status))
    {
        printf("the procession is stopped, the status is %d\n",status);
    }
    else
    {
        printf("the status is wrong!\n");
        err_sys("the status is wrong");
    }
}
int main()
{
    pid_t pid;
    pid_t child_pid;
    int status;
    if((pid=fork())<0)
        err_sys("fork error");
    else if(pid == 0)
    {
        //child 
        printf("hello i am child!\n");
        exit(0);
    }
    else 
    {
        child_pid = wait(&status);
        preExit(status);
    }
 if((pid=fork())<0)
        err_sys("fork error");
    else if(pid == 0)
    {
        //child 
        printf("hello i am child2!\n");
        abort();
    }
    else 
    {
        child_pid = wait(&status);
        preExit(status);
    }
 
  if((pid=fork())<0)
        err_sys("fork error");
    else if(pid == 0)
    {
        //child 
        printf("hello i am child3!\n");
       status /= 0;
    }
    else 
    {
        child_pid = wait(&status);
        preExit(status);
    }
    
   if((pid=fork())<0)
        err_sys("fork error");
    else if(pid == 0)
    {
        //child 
        printf("hello i am child!4\n");
        exit(0);
    }
    else 
    {
        child_pid = wait(&status);
        preExit(status);
    }
   
}

