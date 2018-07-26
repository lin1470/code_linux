//
// Created by bruce on 18-5-19.
//

#include <signal.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <cstring>
#include <sys/time.h>

void dowork(int no)
{
    //得到当前系统事假
    time_t curtime;
    time(&curtime);
    char* pt = ctime(&curtime);
    int fd  = open("./temp+++.txt",O_CREAT|O_WRONLY|O_APPEND,0664);
    write(fd,pt,strlen(pt)+1);
    close(fd);
}
int main()
{
    pid_t pid = fork();
    if(pid>0)
    {
        exit(1);
    }
    else if(pid==0)
    {
        setsid();
        //改变当前进程工作目录
        chdir("~");
        //重设文件掩码
        umask(0);
        //关闭文件描述符
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        //执行核心操作
        //注册信号捕捉
        struct sigaction act;
        act.sa_flags = 0;
        act.sa_handler = dowork;
        sigemptyset(&act.sa_mask);
        sigaction(SIGALRM,&act,NULL);
        //创建定时器
        struct itimerval val;
        val.it_value.tv_sec=2;
        val.it_value.tv_usec = 0;
        val.it_interval.tv_usec = 0;
        val.it_interval.tv_sec = 1;
        setitimer(ITIMER_REAL,&val,NULL);
        //保证一直处于运行状态
        while(1);
    }
    return 0;
}