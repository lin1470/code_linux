#include <iostream>
#include<cstring>
#define maxn 105
//环状串s的表示发是否比表示发q的字典序小
int less(const char *s,int p,int q){
    int n = strlen(s);
    for(int i = 0;i<n;i++)
        if(s[(p+i)%n]!=s[(q+i)%n])
            return s[(p+i)%n]<s[(q+i)%n]; //小于就返回1,大于或者等于都返回0;

    return 0;// 相等.也是返回0
}
int main() {
    int T;
    char s[maxn];
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int ans =0;
        int n = strlen(s);
        for(int i=1;i<n;i++)
            if(less(s,i,ans)) ans =i; //不断的更新ans
        for(int i = 0;i<n;i++)
            putchar(s[(i+ans)%n]); //循环打印.
        putchar('\n');
    }
    return 0;
}