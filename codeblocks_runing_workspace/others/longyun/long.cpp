#include"long.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
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
        length--;
    }
    p->next=head;
    head->pre=p;//至此就构成了一个完整的循环链表了
    return head;
}
void InsertList(char *string,DblList &list)
{
    //int count=0;
    DblList p=list;
    int length=0;
    int is_ne=0;//控制判断是否是一个负数的情况。
   // printf("%d",list->data);
    for(int i=0;i<list->data;i++)
    {
        char num[10];
        int count=0;
        while((*string)&&(*string!=','))
        {
            //char num[10];
            num[count++]=*string;
            string++;
        }
        num[count]='\0';
        p=p->next;
        p->data=abs(atoi(num));
        if(0==i&&atoi(num)<0)
            is_ne=1;
            //else length=list->data;
      //  int data=list->data;
       // printf("%d\n",p->data);
        string++;
    }
    if(is_ne)
        list->data*=(-1);
    //int data=list->data;
  //  printf("%d\n",list->data);

}
void printlist(DblList& list)
{
    DblList p=list;
    int is_ne=0;
   int length=abs(p->data);
   int data=p->data;
   int nonzero=0;
   while(length&&(p=p->next,p->data==0))
        {
            nonzero++;
            length--;
        }
    p=list;
    length=abs(p->data);
   if(p->data==1&&p->next->data==0)
   {
        printf("0\n");
        return ;
   }
   if(p->data<0)
        is_ne=1;
  // printf("%d\n",p->data);
    for(int i=0;i<length;i++)
      {
       p=p->next;
      // if(p->data)
      if(p->data==0&&i<nonzero)
        continue;
      else
        if(nonzero==i&&is_ne)
            printf("-%d",p->data);
        else if(nonzero==i&&!is_ne)
                printf("%d",p->data);
            else printf("%04d",p->data);
       if(i!=length-1)
        printf(",");
      }
   printf("\n");
}
void PlusList(DblList la, DblList lb)
{
    DblList sum;
    DblList pa,pb,pc,p;
    int is_ne=0;
    pa=la;pb=lb;
    sum=(DblList)malloc(sizeof(DblNode));
    p=sum;
    int count=abs(la->data)>abs(lb->data)? abs(la->data):abs(lb->data);
    int length=count;
    int count_a=abs(la->data);
    int count_b=abs(lb->data);
    int a,b,c;
    if((la->data>0&&lb->data>0)||(la->data<0&&lb->data<0))
    {//实现同符号相加的程序

        c=0;
        while(count)//根据我们一般运算的方法，我们是从后面进来的。
        {
            if(count_a>0)
                {
                    a=pa->pre->data;
                    pa=pa->pre;
                    count_a--;
                }
            else a=0;
            if(count_b>0)
                {
                    b=pb->pre->data;
                    pb=pb->pre;
                    count_b--;
                }
            else b=0;
            c=a+b+c;

            pc=(DblList)malloc(sizeof(DblNode));
            pc->data=c%10000;
            c/=10000;
            pc->next=p;
            p->pre=pc;
            p=pc;
            count--;
        }
        if(c!=0)//判断是否需要进位然后在链表中增加长度。
            {
                sum->data=(++length);
                pc=(DblList)malloc(sizeof(DblNode));
                pc->data=c;
                pc->next=p;
                p->pre=pc;
                p=pc;
            }
            else sum->data=length;

        if(la->data<0)
            sum->data*=(-1);
        p->pre=sum;
        sum->next=p;
        printlist(sum);
    }
    if((pa->data<0&&pb->data>0)||(pa->data>0&&pb->data<0))
    {
        if(bigger_one(pa,pb)==0)
        {
            printf("0\n");return ;
        }//交换两个链表把大的一个放在pa;
        else if(bigger_one(pa,pb)==-1)
        {
            DblList temp=pa;
            pa=pb;
            pb=temp;
            count_a=abs(pa->data);
            count_b=abs(pb->data);
        }
        int is_carry=0;
        while(count)
        {
            c=0;
            if(count_a>0)
            {
                pa=pa->pre;
                a=pa->data;
                if(is_carry)
                    a--;
                count_a--;
            }
            else a=0;
            if(count_b>0)
            {
                pb=pb->pre;
                b=pb->data;
                count_b--;
            }
            else b=0;
            if(a<b)
                is_carry=1;
            else is_carry=0;
            if(is_carry)
                a+=10000;
            c=a-b;
            pc=(DblList)malloc(sizeof(DblNode));
            pc->data=c;
            p->pre=pc;
            pc->next=p;
            p=pc;
            count--;
        }
        if(bigger_one(la,lb)==1&&la->data<0||bigger_one(la,lb)==-1&&lb->data<0)
            is_ne=1;
        if(bigger_one(la,lb)==1&&la->data>0||bigger_one(la,lb)==1&&lb->data>0)
            is_ne=0;
        if(is_ne)
            sum->data=length*(-1);
            else sum->data=length;
        sum->next=p;
        p->pre=sum;
        printlist(sum);
    }
}
int bigger_one(DblList la,DblList lb)
{//如果la比较大返回1，lb大-1，相等则返回0；
    int win_la=0;
    if(abs(la->data)>abs(lb->data))
        win_la=1;
    else if(abs(la->data)<abs(lb->data))
        win_la=-1;
        else
        {
            int length=abs(la->data);
            for(int i=0;i<length;i++)
                {
                    la=la->next;
                    lb=lb->next;
                   // printf("%d\t%d\n",la->data,lb->data);
                    if(la->data>lb->data)
                    {win_la=1;break;}
                    if(la->data<lb->data)
                    {
                        win_la=-1;
                        break;
                    }
                }
        }
    return win_la;
}
