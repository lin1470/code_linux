#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"long.h"
#include<string.h>
int main()
{
   // get_length_from_char("hh");
//   InsertList("1231,1234",FirstList);
    DblList FirstList,SeconList;
    char first[100],second[100];
    //if(!(FirstList=(DblNode*)(malloc(sizeof(DblNode))))) exit(1);
    //if(!(SeconList=(DblNode*)(malloc(sizeof(DblNode))))) exit(1);//初始化来两个
    printf("please input the first number with the comma\n");
    //gets(first);
    strcpy(first,"123,123");
    printf("%s\n",first);
    printf("please input the second number with the comma\n");
    //gets(second);
    //second="123,123";
    strcpy(second,"123,123");
    printf("%s\n",second);
    FirstList=InitList(get_length_from_char(first));
    SeconList=InitList(get_length_from_char(second));
    //InsertList("1231,1234",FirstList);


    return 0;
}
