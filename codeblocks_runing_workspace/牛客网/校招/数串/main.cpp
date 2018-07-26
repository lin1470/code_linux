#include <iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int com(char *a, char* b)
{
    //长度相等的比较
    char *at= a;
    char *bt = b;
    while((*a)&&(*b)){
        if(*a > *b)
            return 1;
        else if(*a < *b)
            return -1;
        else{
            a++;b++;
        }
    }
    //如果还有存在的长度的就是大的一个数.
    if(*a) return com(a,bt);
    else if(*b) return com(at,b);
    else return 0;
}
int main()
{
    char a[101][1001];
    int n;
    cin >> n;
    for(int i =0;i<n;i++)
        scanf("%s",a[i]);
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(com(a[i],a[j])==-1){
                char t[1001];
                strcpy(t,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],t);
            }
        }
    }
//    cout << com("12","123");
    for(int i=0;i<n;i++){
        cout << a[i];
    }
    return 0;
}
