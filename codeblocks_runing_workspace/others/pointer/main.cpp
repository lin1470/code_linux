#include <stdio.h>

int main()
{
    int i,j,k;
    int *p1,*p2,*p3;
    printf("请从小到大输入三个整数：\n");
    scanf("%d%d%d",&i,&j,&k);
    p1=&i;p2=&j;p3=&k;
    printf("原来p1指向的是:%d\n",*p1);
    printf("原来p2指向的是:%d\n",*p2);
    printf("原来p3指向的是:%d\n",*p3);
    int a[3];
    a[0]=i;
    a[1]=j;
    a[2]=k;
    for(int i=0;i<2;i++)
        for(int j=i;j<3;j++)
        if(a[i]>a[j])
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }//这个是数组的排序，并没有改变i,j,k的值。
    p1=&a[0];
    p2=&a[1];
    p3=&a[2];
    printf("现在p1指向的是：%d\n",*p1);
    printf("现在p2指向的是：%d\n",*p2);
    printf("现在p3指向的是：%d\n",*p3);



}
