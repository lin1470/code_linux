#include <stdio.h>

int main()
{
    int i,j,k;
    int *p1,*p2,*p3;
    printf("���С������������������\n");
    scanf("%d%d%d",&i,&j,&k);
    p1=&i;p2=&j;p3=&k;
    printf("ԭ��p1ָ�����:%d\n",*p1);
    printf("ԭ��p2ָ�����:%d\n",*p2);
    printf("ԭ��p3ָ�����:%d\n",*p3);
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
    }//�������������򣬲�û�иı�i,j,k��ֵ��
    p1=&a[0];
    p2=&a[1];
    p3=&a[2];
    printf("����p1ָ����ǣ�%d\n",*p1);
    printf("����p2ָ����ǣ�%d\n",*p2);
    printf("����p3ָ����ǣ�%d\n",*p3);



}
