#include <stdio.h>
#include "../tool/apue.h"
#include <pwd.h>

int main()
{   
    struct passwd * pwd = NULL;
    pwd = getpwnam("bruce");
    printf("the information if bruce is :name%s,uid:%d,gid:%d,pass:%s\n",pwd->pw_name,\
           pwd->pw_uid,pwd->pw_gid,pwd->pw_passwd);
    printf("Hello world\n");
    return 0;
}
