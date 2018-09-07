#include "../tool/apue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    char line[MAXLINE];
    if(argc!=2)
        err_sys("useage: %s file\n",argv[0]);
    FILE *fin,*fout;
    if((fin = fopen(argv[1],"r")) == NULL)
       err_sys("fopen error");
    if((fout = popen("less","w")) == NULL)
        err_sys("popen error");
    while(fgets(line,MAXLINE,fin) != NULL)
    {
        fputs(line,fout);
    }
    if(ferror(fin))
        err_sys("fgets error");
    if(pclose(fout) == -1)
    err_sys("pclose error");
    exit(0);
}
