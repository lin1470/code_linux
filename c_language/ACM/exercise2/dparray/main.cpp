#include <iostream>
#include<cstring>
#define MaxN 105
using namespace std;
int max(int a,int b){
    return a>=b? a:b;
}
int dp[MaxN][MaxN],num[MaxN][MaxN];
int n;
//记忆化搜索的形式.
int solve(int i,int j)
{
    if(dp[i][j]>0) return dp[i][j];
    return dp[i][j] = num[i][j]+(i == n-1? 0:max(solve(i+1,j),solve(i+1,j+1)));
}
int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        //读入数组
        for(int i =0;i<n;i++)
            for(int j =0;j<=i;j++)
                cin >> num[i][j];

        memset(dp,-1,sizeof(dp));
//        for(int i = n-1;i>=0;i--){
//            for(int j = 0;j<=i;j++)
//                dp[i][j] = num[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
//        }

        cout << solve(0,0) << endl;
    }
    return 0;
}