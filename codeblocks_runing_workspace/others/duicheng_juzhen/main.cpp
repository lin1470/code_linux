#include<stdio.h>
#include<stdlib.h>

void input(int a[], int e, int i, int j)
{
       	 a[(i*(i-1))/2+j-1] = e;
}

void output(int a[],int i, int j)
{
    	if (i>=j)
       	 printf("%d",a[(i*(i-1))/2+j-1]);
    	else
       	 printf("%d",a[(j*(j-1))/2+i-1]);
}

int main(){
	int b,i,j,n=3;
    int a[100];
	for(i=1;i<=n;i++)
    {
        for(j=1; j<=i; j++)
        {
            printf("输入第%d行的%d个数据元素: ", i, j);

             scanf("%d", &b);
             input(a, b, i, j);
        }
    }
return 0;
}
