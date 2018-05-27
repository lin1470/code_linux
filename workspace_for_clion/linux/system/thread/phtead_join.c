//
// Created by bruce on 18-5-20.
//


#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int num =100;
void *myfunc(void* args)
{
    printf("child thread id:%lu\n",pthread_self());
    for(int i =0;i<5;i++)
    {
        printf("child i=%d\n",i);
        if(i==2)
        {
            pthread_exit(&num);
        }
    }
    return NULL;
}
int main()
{
    //穿件一个子线程
    //线程ID变量
    pthread_t pthid;

    int ret = pthread_create(&pthid,NULL,myfunc,NULL);

    if(ret != 0)
    {
        printf("error number%d\n",ret);
        printf("%s\n",strerror(ret));
    }
    printf("parent thread id:%lu\n",pthread_self());
    void *ptr = NULL;
    pthread_join(pthid,&ptr); //阻塞函数
    printf("number = %d\n",*(int*)ptr);
    int i=0;
    while(i<10)
    {
        printf("i=%d\n",i++);
    }
    pthread_exit(NULL);
    sleep(2);
    return 0;
}
