#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
    char c;
    int n=0;
    while((c=getchar())!='\n')

             n++;

    printf("这个字符串的个数是:%d\n",n);
    return 0;
}
