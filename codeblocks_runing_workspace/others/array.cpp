#include <stdio.h>
#define N 10

//using namespace std;
void scanf_array(int *a,int len)
{
    for(int i=0;i<len;i++)
        scanf("%d",&a[i]);
}//��ȡ����
void treat_array(int *a,int *p1,int *p2)
{
    int maxn=0,mini=0;
    for(int i=0;i<N;i++)
        if(a[maxn]<a[i])
        maxn=i;
    for(int i=0;i<N;i++)
    {
        if(a[mini]>a[i])
            mini=i;
    }
    p1=&a[maxn];
    p2=&a[mini];
    int t=a[mini];
    a[mini]=a[0];
    a[0]=t;
    t=a[maxn];
    a[maxn]=a[N-1];
    a[N-1]=t;
}//�������鲢�ҽ���..������ָ�뷽�����ġ�
void printf_array(int* a)
{
    for(int i=0;i<N;i++)
        printf("%d\t",a[i]);
}//��ӡ�������
int main()
{
    int a[N];
    int *p1,*p2;
    printf("������һ��ʮ�������������飺");
    scanf_array(a,N);
    treat_array(a,p1,p2);
    printf("������ɵ������ǣ�\n");
    printf_array(a);
    return 0;

}
