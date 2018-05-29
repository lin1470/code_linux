//
// Created by bruce on 18-5-18.
//
#include<sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

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
//    strcpy((char*)ptr,"heollllllo \n");
    printf("%s",(char*)ptr);

    //释放内存映射区
    munmap(ptr,len);
    close(fd);

    return 0;
}