#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,t,i,c;
    int a[100002];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        int k=1,st=0,en=0,summax=-1000,sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>summax)
            {
                summax=sum;
                st=k;
                en=i+1;
            }
            if(sum<0)
            {
                sum=0;
                k=i+2;
            }
        }
        printf("Case %d:\n%d %d %d\n",c,summax,st,en);
        if(c!=t) cout<<endl;
    }
    return 0;
}