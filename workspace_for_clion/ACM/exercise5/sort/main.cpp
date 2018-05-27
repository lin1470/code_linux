#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct sa
{
    char name[105];
    int date;
} arr[105];
int cmp(sa a, sa b)
{
    return a.date > b.date;
}
char str[200];
int main()
{
    int t,m;
    scanf("%d",&t);
    while(t--)
    {
        cin>>m;
        getchar();
        for(int i=0; i<m; i++)
        {
            fgets(str,199,stdin); // 会读取一个换行符
            int len = strlen(str)-1;
//            arr[i].date = str[len-4]*1000+str[len-3]*100+str[len-2]*10+str[len-1];
            int year = 0;
            for(int i=len-4;i<=len-1;i++)
                year = year*10+(str[i]-'0');
            arr[i].date = year;
//            cout << arr[i].date<< endl;
            len -= 5;
            str[len] = '\0';
            strcpy(arr[i].name,str);
        }
        sort(arr, arr+m, cmp);
        for(int i=0; i<m; i++)
            cout<<arr[i].name<<endl;
    }
    return 0;
}
