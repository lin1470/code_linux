#include<stdio.h>
int main(){
    int n;
    int m;
    printf("please input a number with 3 digits:");
    scanf("%d",&n);
    m = (n%10)*100+(n/10%10)*10+(n/100);
    printf("%03d\n",m);
    return 0;
}
