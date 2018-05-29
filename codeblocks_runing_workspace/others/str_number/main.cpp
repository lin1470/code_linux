#include<string.h>
#include<stdio.h>
int getNum(char *str)
 {
    int num = 0;
    while(*str)
           {
             if (*str >= 'A' && *str <= 'z')
                         num++;
                         str++;
            }
    return num;
 }
int main()
{
    char *ch="ha hah";
    printf("%d%d",getNum(ch),strlen(ch));
    return 0;
}
