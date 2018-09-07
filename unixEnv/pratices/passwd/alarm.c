#include <stdio.h>
#include <pwd.h>
#include "../tool/apue.h"

int count =0;
void my_alarm(int signo)
{
    count++;
    printf("my_alarm signale is %d\n",signo);
    printf("reviece the alarm signal\n");
    if(count % 10 ==0)
        printf("the count is %d",count);
    alarm(1);
}
int main()
{
    if(signal(SIGALRM,my_alarm)==SIG_ERR)
        err_sys("signal function");
    alarm(1);
    for(;;)
    {
    }
    
    printf("Hello world\n");
    return 0;
}

