#include<stdio.h>
#include<string.h>
#define inf 100000000
#define eps 1e-9
#include<algorithm>
using namespace std;
double a[200]; // 充电站距离数组
double dp[200];
int main()
{
    double s; // 跑道长度
    while(scanf("%lf",&s)==1)
    {
        int n;
        double c,t;
        scanf("%d%lf%lf",&n,&c,&t); //读取三个参数,充电站个数,电动车行驶能行驶的距离,每次充电需要的时间
        double vr,v1,v2;
        scanf("%lf%lf%lf",&vr,&v1,&v2);// 三个速度,兔子速度,车速度,脚蹬速度
        for(int i=0;i<=n+20;i++)
            dp[i]=inf;
        dp[0]=0;
        memset(a,0,sizeof(dp)); // 动态规划数组
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&a[i]);
        }
        a[n+1]=s; // 最后一个充电站设置为总长
        for(int i=1;i<=n+1;i++)
        {
            for(int j=0;j<i;j++)
            {
                double t1,s1;
                s1=a[i]-a[j]; // 两个充电站之间的距离
                if(s1<c)      //开车
                    t1=s1/v1; // 开车需要的时间
                else
                    t1=(c/v1)+(s1-c)/v2; //开车一半然后蹬车时间
                if(j)        //是否充电
                    t1+=t;
                dp[i]=min(dp[i],dp[j]+t1);
            }
        }
        dp[n+1]=min(dp[n+1],s/v2);
        if((s/vr)>dp[n+1]+eps)
            printf("What a pity rabbit!\n");
        else
            printf("Good job,rabbit!\n");
    }
}