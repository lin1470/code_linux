#include<stdio.h>
#define N 10
void scanf_array(int** a)
{
    for(int i=0;i<N;i++)
        scanf("%d",a[0]);
    for(int i=0;i<N;i++)
        printf("%d\t",*a[0]);
}
int main() {
    int* a[N];
    printf("请输入一个10个整数的整型数组:\n");
    scanf_array(a);
    int i, j, tmp, number[10] = {95,45, 15, 78, 84, 51,24, 12, 34, 50};

    for (i = 0; i < 10; i++) {
        for (j = 10 - 1; j > i; j--) {
            if (number[j] < number[j-1]) {
                tmp = number[j-1];
                number[j-1] =  number[j];
                number[j] = tmp;
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", number[i]);
    }
    printf("\n");
    return 0;
}
