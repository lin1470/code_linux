//
// Created by bruce on 18-10-20.
//
#include <stdio.h>
extern char ** environ;
int main()
{
    int i;
    printf("the environ is as follow:\n");
    for(i =0;environ[i];i++)
    {
        printf("%s\n",environ[i]);
    }
    return 0;
}
