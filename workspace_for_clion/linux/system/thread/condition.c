//
// Created by bruce on 18-5-20.
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
//节点结构
typedef struct node
{
    int data;
    struct node* next;
}Node;

//永远指向链表头部指针
Node *head = NULL;

//XIANCHENG同步,互斥锁
pthread_mutex_t mutex;
//线程阻塞-条件变量类型的变量
pthread_cond_t cond;

void* produce(void *arg)
{
    while(1)
    {
        Node *pnew = (Node*)malloc(sizeof(Node));

        //节点初始化
        pnew->data = rand()%1000;
        //使用互斥锁保护共享数据
        pthread_mutex_lock(&mutex);
        //指针域
        pnew->next = head;
        head = pnew;
        printf("======prodece:%lu,%d\n",pthread_self(),pnew->data);
        pthread_mutex_unlock(&mutex);

        //tongzhi 阻塞的消费者进程,解除阻塞
        pthread_cond_signal(&cond);

        sleep(rand()%3);
    }
    return NULL;
}

void* customer(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        //判断链表是否为空
        if(head == NULL)
        {
            //阻塞函数
            pthread_cond_wait(&cond,&mutex);//注意这里有个互斥锁的加进去
            //解除阻塞之后,对互斥锁做枷锁操作

        }
        //部位空
        Node *pdel = head;
        head = head->next;
        printf("=====customer:%ld,%d\n",pthread_self(),pdel->data);
        free(pdel);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
int main()
{
    pthread_t p1,p2;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    //创建生产者线程
    pthread_create(&p1,NULL,produce,NULL);
    pthread_create(&p2,NULL,customer,NULL);


    //阻塞回收子线程
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
}