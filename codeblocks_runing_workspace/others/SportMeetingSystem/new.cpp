#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m;
    srand(time(NULL));
    do{
        for(int i=0;i<10;i++)
        printf("%d\t",rand()%100);
        system("pause");
        printf("\n");
    }while(1);
    return 0;
}
