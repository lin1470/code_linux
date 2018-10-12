//
// Created by bruce on 18-5-20.
//

#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//
// Created by bruce on 18-5-20.
//
void *myfunc(void* args)
{
    int num = (int)args;
    printf("%dth child thread id:%lu\n",num,pthread_self());
    return NULL;
}
int main()
{
    //穿件一个子线程
    //线程ID变量
    pthread_t pthid[5];
    for(int i=0;i<5;++i)
    {
        //第四个参数传递的是地址
//        pthread_create(&pthid[i],NULL,myfunc,(void*)&i);
        //强制性转为int,然后传值进去.
        pthread_create(&pthid[i],NULL,myfunc,(void*)i);
    }
    printf("parent thread id:%lu\n",pthread_self());

    for(int i=0;i<5;++i)
    {
        printf("i=%d\n",i);
    }
    sleep(2);
    return 0;
}
