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
#define PORT 2345

int main()
{
    int sockfd,newSockfd;
    struct sockaddr_in addr; // 定义 ipv4套接口地址数据结构 addr
    int addr_len = sizeof(struct sockaddr_in);
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))==-1) //创建一个socket如果失败返回-1
    {
        perror("socket created error!");
        exit(1);
    }
    else
    {
        printf("socket created successfully!\n");
        printf("socket id:%d\n",sockfd);
    }
    bzero(&addr,sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET; // 设置IPv4的协议组
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY); //IP地址为本机IP
    if(bind(sockfd,(struct sockaddr*)(&addr),sizeof(struct sockaddr))==-1) // 绑定如果失败的话就返回-1
    {
        perror("bind error!\n");
        exit(1);
    }
    else{
        printf("bind port successfully!\n");
        printf("local port:%d\n",PORT);
    }
    if(listen(sockfd,5)==-1) //调用listen函数进行监听,能同时处理最大链接请求数5,如果是ipv4的话,则可以达到128
    {
        perror("listen error!\n");
        exit(1);
    }
    else{
        printf("listening....\n"); //监听中
    }
    if((newSockfd = accept(sockfd,(struct sockaddr *)(&addr),(socklen_t *)&addr_len))==-1)
        //调用accept接受一个连接请求
        //addr的
    {
        perror("accept error!\n");
    }
    else
    {
        printf("accepted a client connection.\n");
        printf("now, the server socket id:%d\n",newSockfd);
        printf("2015101017 李柱霖\n");
    }
    return 0;
}
