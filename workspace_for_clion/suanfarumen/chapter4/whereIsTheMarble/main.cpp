#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000;
bool mycompare(int i,int j)
{
    return i>j;
}
int main() {
    int n,q,x,a[maxn],kase =0;
    while(scanf("%d%d",&n,&q) ==2 &&n)
    {
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,mycompare);
        for(int i=0;i<n;i++)
            cout << a[i]<< " ";
        while(q--)
        {
            scanf("%d",&x);
            int p = lower_bound(a,a+n,x)-a; //在已经排序的数组中寻找x
            if(a[p]==x) printf("%d found at %d\n",x,p+1);
            else printf("%d not found \n",x);
        }
    }
    return 0;

}