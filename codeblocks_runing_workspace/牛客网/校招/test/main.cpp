#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    char a[10][10];
    for(int i=0;i<3;i++){
        scanf("%s",a[i]);
    }
    char t[10];
    strcpy(t,a[1]);
    strcpy(a[1],a[2]);
    strcpy(a[2],t);
    for(int i=0;i<3;i++){
        printf("%s\n",a[i]);
    }
    cout << "Hello world!" << endl;
    return 0;
}
