//
// Created by bruce on 18-11-5.
//

#include <wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int f1,f2;
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0)
    {
        // child
        char word[] = "helle world";
        mode_t mode = 0777;
        f1 = open("file.txt",O_CREAT|O_WRONLY,mode);
        if(f1<0)
        {
            perror("open error");
            exit(1);
        }
        int n = write(f1,word,strlen(word));
        if(n != strlen(word))
        {
            perror("write error");
            exit(1);
        }
        printf("the child wrote completely!\n");
        exit(0);
    }
    else {
        //parent
        sleep(1); //保证子进程已经写完的了
        char word[100];
        f1= open("file.txt",O_RDONLY);
        int n = read(f1,word,100);
        if(n < 0)
        {
            perror("read error");
            exit(1);
        }
        printf("read byte is %d\n",n);
        printf("i am child,the content is %s\n",word);


    }

}