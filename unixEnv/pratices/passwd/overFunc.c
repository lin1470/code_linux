#include <stdio.h>
#include <pwd.h>
#include "../tool/apue.h"

void my_alarm(int signo)
{
    printf("my_alarm signale is %d\n",signo);
    struct passwd *rootptr = NULL;
    printf("reviece the alarm signal\n");
    if((rootptr = getpwnam("root"))==NULL)
        err_sys("getpwnam function wrong\n");
    printf("the root uid is %d",rootptr->pw_uid);
    alarm(1);
}
int main()
{
    struct passwd *bruceptr = NULL;
    if(signal(SIGALRM,my_alarm)==SIG_ERR)
        err_sys("signal function");
    alarm(1);
    for(;;)
    {
        if((bruceptr = getpwnam("bruce")) == NULL)
            err_sys("getpwnam function");
        printf("the name is %s\n",bruceptr->pw_name);
        if(strcmp(bruceptr->pw_name,"bruce")!=0)
        {
            printf("return value corrupted!,pw_name = %s\n",bruceptr->pw_name);
        }
    }
    printf("Hello world\n");
    return 0;
}

