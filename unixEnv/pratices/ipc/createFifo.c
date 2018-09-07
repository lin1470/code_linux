#include "../tool/apue.h"
#include <sys/stat.h>

int main(int argc,char *argv[])
{
    if(mkfifo( "./hhh",FILE_MODE ) == -1)
    {
        err_sys("mkfifo error");
    }
    return 0;

}
