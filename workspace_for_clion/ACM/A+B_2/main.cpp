#include<stdio.h>
#include<string.h>
#define MAXN 1001

int main()
{
    int i,k,sum=1,t,len_str1,len_str2,max_len;
    char str1[MAXN],str2[MAXN];
    scanf("%d",&t);
    while(t--)
    {
        int a[MAXN] = {0},b[MAXN] = {0},c[MAXN] = {0};
        scanf("%s%s",str1,str2);
        len_str1=strlen(str1);
        len_str2 = strlen(str2);
        for(i=0;i<=len_str1-1;i++)
            a[i]=str1[len_str1-i-1]-'0'; // 反向填充数字
        for(i=0;i<=len_str2-1;i++)
            b[i]=str2[len_str2-i-1]-'0';// 反向填充数字
        k =0;//用k来保存是否存在进位
        max_len = len_str1>len_str2? len_str1:len_str2;

        for(i=0;i<=max_len-1;++i)
        {
            c[i]=(a[i]+b[i]+k)%10;
            k = (a[i]+b[i]+k)/10;
        }

        printf("Case %d:\n",sum);
        sum++;
        printf("%s + %s = ",str1,str2);
        if(k ==1 )printf("1");
        for(i = max_len-1;i>=0;i--)
            printf("%d",c[i]);
        printf("\n");
        if(t>=1)
            printf("\n");
    }
}