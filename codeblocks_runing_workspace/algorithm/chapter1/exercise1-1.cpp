#include<stdio.h>
#include<stdlib.h>
int main(){
    int a,b,c;
    double result;
    printf("Please input three numbers:");
    scanf("%d %d %d",&a,&b,&c);
    result = (a+b+c)*1.0/3;
    printf("%.3f",result);
//    printf(a)
    printf("%d,%d",sizeof(int),sizeof(long));
    return 0;
}
