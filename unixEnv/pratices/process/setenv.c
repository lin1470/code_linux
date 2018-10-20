//
// Created by bruce on 18-10-20.
//
#include <stdio.h>
#include <stdlib.h>

int main()
{
   char *value = NULL;
   if((value = getenv("hello"))!=NULL)
   {
       printf("value is %s\n",value);
   }
   else {
       printf("there is no such name viriable %s\n",value);
   }
   int ret = setenv("hello","hello",1);
   printf("setenv ret is %d\n",ret);
   value = getenv("hello");
   printf("value is %s\n",value);
    ret = unsetenv("hello=");
    if(ret == 0)
    {
        printf("success\n");
    }
    else
    {
        printf("failed\n");
        perror("unsetenv");
    }
    if((value = getenv("hello"))!=NULL)
   {
       printf("value is %s\n",value);
   }
   else {
       printf("there is no such name viriable %s\n",value);
   }
    return 0;
}
