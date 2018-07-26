#include <iostream>
#include<cstring>
#define maxn 100005
int main() {
    int ans[maxn];
    int T,n;
    memset(ans,0,sizeof(ans));
    for(int m=0;m<maxn;m++){
        int x = m, y = m;
        while(x>0){y += x%10;x/=10;}
        if(ans[y] == 0) ans[y] = m;
    }
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}