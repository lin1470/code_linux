#include <iostream>
#include <cstring>

using namespace std;
int main() {
    long long dp[100];
    int n;
    while(cin >>n){
        memset(dp,0,sizeof(dp));
        for(long long i=2;i<=n;i++){
            if(i ==2)
                dp[i] = 1;
            else if(i==3)
                dp[i] = 2;
            else{
                dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
            }
        }
        cout << dp[n]<< endl;
   }
    return 0;
}