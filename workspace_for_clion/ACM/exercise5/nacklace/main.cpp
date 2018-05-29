#include<iostream>
#include<cstring>
using namespace std;
int dp[1022][22];
struct stone
{
    int v,w;
} a[21];
int main()
{
    int t,n,k,w,i,j,z;//t是测试用例,n砖石个数,k接受的砖石个数,w总数量
    cin>>t;
    while(t--)
    {
        cin >> n>>k;
        for(i=1;i<=n;i++)
            cin>>a[i].v>>a[i].w;
        cin >>w;
        memset(dp,0,sizeof(dp));

        for(i=1;i<=n;i++)
            for(j=w;j>=a[i].w;j--)
                for(z=1;z<=k;z++)
                    dp[j][z] = max(dp[j][z],dp[j-a[i].w][z-1]+a[i].v);
        cout << dp[w][k] << endl;
    }
}
