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
    char c;
    do{
        printf("hello, this is the operation between long integer!\n");
        printf("--------------------------------------------------\n\n");
        printf("please input the first number with the comma\n");
        gets(first);
        /*{
            strcpy(first," 0000,0000,00001");
            FirstList=InitList(get_length_from_char(first));
            InsertList(first,FirstList);
            printlist(FirstList);
        }*/
      //  system("pause");
       // printf("%s\n",first);
        printf("please input the second number with the comma\n");
    //gets(second);
    //second="123,123";
        //strcpy(second,"1,0000,0000,0000");
        gets(second);
        fflush(stdin);
      //  printf("%s\n",second);
        FirstList=InitList(get_length_from_char(first));
        SeconList=InitList(get_length_from_char(second));
        InsertList(first,FirstList);
        InsertList(second,SeconList);
        printf("the first number is:\n");
        printlist(FirstList);
        printf("the second number is:\n");
        printlist(SeconList);
        printf("the result is:\n");
        PlusList(FirstList,SeconList);
        free(FirstList);
        free(SeconList);
        printf("again?\n");
    }while(c=getchar(),fflush(stdin),system("cls"),c=='y'||c=='Y');
    printf("thank you!\n");
    return 0;
}
