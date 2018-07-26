#include <string.h>
#include<stdio.h>
void uper_string(char* str)
{
   for(int i=0;i<strlen(str);i++)
    if(str[i]>='a'&&str[i]<='z')
    str[i]-=32;
}
int main()
{
    char str1[100]="hith";
    uper_string(str1);
    printf("%s",str1);
    return 0;
}
