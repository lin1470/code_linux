#include "../tool/apue.h"
int forkk()
{
    pid_t child;
    if((child = fork())<0)
    {
        err_sys("error fork!");
    }
    else if(child == 0)
    {
        execl("sdhfhsjdfhsdf","shdfhsdf",NULL);
        return -1;
    }
    else{
        /*parent*/
        return 0;
        }
}
int main()
{
    int ret = forkk();
    printf("the return is %d\n",ret);
    printf("thwjskldfjklsdf\n");
    return 0;
}
