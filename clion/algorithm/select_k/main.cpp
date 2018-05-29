#include <iostream>
using namespace std;
void InsertSort(int *a,int n)
{
    int  temp,i,j;
    for( i=1;i<n;i++)
    {
        temp = a[i];
        for( j=i;j>0&&a[j-1]>temp;j--)
                a[j] = a[j-1]; //记录后移
        a[j]= temp; //插入记录
    }
}

int select_median(int *a,int n)
{//寻找数组a中的中位数，并且返回这个中位数
    if(n==1)
        return a[0];
    int k = n%5 == 0? n/5:n/5+1;//表示有k组
    for(int i=0;i<k;i++)
    {
        if(i==k-1)//如果是最后一组
        {
            int n0 = n%5==0? n%5+5:n%5;
            InsertSort(a+i*5,n0);
            a[i] = (a+i*5)[n0&1? n0/2:n0/2-1];//这个可能要调整
            printf("%d\n",a[i]);
        }else{
        InsertSort(a+i*5,5);
        a[i] = (a+i*5)[2];
        printf("%d\n",a[i]);
        }

    }
    select_median(a,k);
}
int main() {

    int a[] = {0,3,20,1,5,10,44,6,8,30};
//    InsertSort(a,5);
    int n = sizeof(a)/sizeof(int);
   cout << select_median(a,n)<<endl;
//    for(int i=0;i<5;i++)
//        printf("%d ",a[i]);
    return 0;
}