#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000

void paixu(int* a)
{
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++)
        if(a[i]<a[j])
    {
        int t=a[i];
        a[j]=a[i];
        a[i]=t;
    }
}
int main()
{
    int st=clock();
    int a[N];
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%1000+1;
    }
    paixu(a);
    int et=clock();
    printf("整个程序运行的时间是：%ldms",et-st);
    return 0;
}
