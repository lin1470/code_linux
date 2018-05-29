//
// Created by bruce on 18-5-19.
//

#include<sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<sys/wait.h>

int main()
{
    // 打开一个文件
    int fd = open("english.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open error");
        exit(1);
    }
    int len = lseek(fd,0,SEEK_END);

    //创建内存映射区
    void *ptr = mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr == MAP_FAILED){
        perror("mmap error");
        exit(1);
    }
    pid_t  pid = fork();
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    if(pid >0){
        strcpy((char*)ptr,"你是我儿子?");
        wait(NULL);
    }
    else if(pid == 0)
    {
        printf("%s\n",(char*)ptr);
    }
    //释放内存映射区
    munmap(ptr,len);
    close(fd);

    return 0;
}