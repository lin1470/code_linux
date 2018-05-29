#include <stdio.h>
#include<string.h>
int compare_str(char* str1,char* str2)
{
   int  len=strlen(str1)>strlen(str2)? strlen(str2):strlen(str1);
    int flag=0;
    for(int i=0;i<len;i++)
    {
        if(str1[i]>str2[i])
        {
            flag=1;break;
        }
        else if(str1[i]<str2[i])
        {
            flag=-1;break;
        }
        else flag=0;//以上是判断在最小长度之内的大小
    }
      if(flag==0)
            if(strlen(str1)>len)
            flag=1;
        else if(strlen(str2)>len)
            flag=-1;
        else flag=0;
        return flag;

}
int main()
{
    char str1[100]; 
    char str2[100];
    printf("请输入第一个字符串：");
    gets(str1);
    printf("请输入第二个字符串：");
    gets(str2); 
   int  flag=compare_str(str1,str2);
   if(flag==1)
    printf("the bigger one is %s\n",str1);
   else if(flag==-1)
    printf("the bigger one is %s\n",str2);
   else printf("the two string is the same!\n");
    return 0;
}
