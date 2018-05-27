#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main ()
{
    int a[N];
    srand(time(0));
    printf("随机产生的300个数的数组（<1000的正整数）是：");
    for(int i=0;i<N;i++)
       {
           a[i]=rand()%1000+1;
           printf("%d\t",a[i]);
           if(i%10==9)
            printf("\n");
       }
       printf("\n");
       for(int i=0;i<N-1;i++)
       {
           int max=i;
           for(int j=i+1;j<N;j++)
            if(a[i]<a[j])
                max=j;
            if(max!=i)
            {
                int t;
                t=a[i];
                a[i]=a[max];
                a[max]=t;
            }
       }
    printf("排好的300个数的数组（从大到小的排列）;");
    for(int i=0;i<N;i++)
       {
           a[i]=rand()%1000+1;
           printf("%d\t",a[i]);
           if(i%10==9)
            printf("\n");
       }




}
