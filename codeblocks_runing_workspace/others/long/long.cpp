#include"long.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int get_length_from_char(char *number)
{
    int length;
    //char a[20]="nimei,nimei,nimei";
    //number=a;
    for(length=0;*number;number++)
    {
        if(*number==',')
        length++;
    }
   // printf("the length of the char string is %d",length);
    return length+1;
}
DblList InitList(int length)
{
    DblList head=(DblList)(malloc(sizeof(DblNode)));
    DblList p,pt;
    p=head;

    head->data=length;
    while(length)
    {
        pt=(DblList)(malloc(sizeof(DblNode)));
        p->next=pt;
        pt->pre=p;
        p=pt;
    }
    p->next=head;
    head->pre=p;//至此就构成了一个完整的循环链表了
    return head;
}
void InsertList(char *string,DblList &list)
{
    //int count=0;
    DblList p=list;
    for(int i=0;i<list->data;i++)
    {
        char num[10];
        int count=0;
        while((*string)&&(*string!=','))
        {
            //char num[10];
            num[count++]=*string;
        }
        num[count]='\0';
        p=p->next;
        p->data=atoi(num);
        printf("%d\n",p->data);
    }
}
