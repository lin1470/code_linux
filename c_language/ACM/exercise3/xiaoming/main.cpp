#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int trans(int a)
{
    int len = 0;
    int a0 = abs(a);
    while(a0){
        len++;
        a0 /=10;
    }
//    cout << len<< endl;
    int ans;
    a0 =abs(a);
    for(int i=0;i<len;i++){
//        cout << int(pow(10,len-i-1));
        ans += (a0%10)*int(pow(10,len-i-1));
        a0 /=10;
    }
//    cout << a<< endl;
    if(a<0)
    {
        return (-1)*ans;
    }
    else return ans;
}
int main()
{
//    int aa,bb,a,b,x,y,t;
    printf("%d %d",trans(13),trans(22));
//    scanf("%d",&t);
//    while(t--)
//    {
//        scanf("%d %d",&x,&y);
//        a=(x+y)/2; b=(x-y)/2;
//        aa=trans(a);
//        bb=trans(b);
//        printf("%d %d\n",aa+bb,aa-bb);
//
//    }
}
