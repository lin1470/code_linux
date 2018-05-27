//
// Created by bruce on 18-5-16.
//
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include <stdio.h>
#include<string.h>
#include <cstdlib>
#define PORT 2345 //定义远程端口
#define REMOTE_IP "127.0.0.1"//定义远程地址

int main(){
    int sockfd;
    struct sockaddr_in addr; //定义ipv4的套接口地址结构 用来存储远程主机ip地址和端口号
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1){
        perror("socket created error!:");
        exit(1);
    }
    else{
        printf("client socket created successfully\n");
        printf("client socket id:%d\n",sockfd);
    }
    bzero(&addr,sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = inet_addr(REMOTE_IP); // 要先进行转换才行
    if(connect(sockfd,(struct sockaddr*)(&addr),sizeof(struct sockaddr)) == -1)
    {
        perror("connect error:");
        exit(1);
    }
    else{
        printf("connected server successfully!\n");
        printf("client socket id:%d\n",sockfd);
        printf("2015101017 李柱霖\n");
    }

}
