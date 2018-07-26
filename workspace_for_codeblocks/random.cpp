#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 20
int main()
{
    int a[N];
    srand(time(0));
    printf("随机产生的20个数的数组（<1000的正整数）是：");
    for(int i=0;i<N;i++)
       {
           a[i]=rand()%1000+1;
           printf("%d\t",a[i]);
       }
       printf("\n倒置输出这个数组：");

    for(int i=N-1;i>=0;i--)
    {
        printf("%d\t",a[i]);
    }
    return 0;

}
