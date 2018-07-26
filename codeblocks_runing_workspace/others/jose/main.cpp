#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//1.元素类型，结点类型和指针类型
typedef struct LNode         //定义结构体，
{
 int num,pwd;                 //num用来存储人的序号，pwd用来存储人的密码
 struct LNode *next;
};
struct LNode *head,*p,*pt;    //定义结点
//2 、创建循环链表函数

int creatLinkList(int n)      //参数n传递人数，
{
   int i;
   head=(struct LNode*)malloc(sizeof(struct LNode));   //创建一个带头指针吧的链表
   if(!head)  {return 0;}    //创建不成功，返回0
   p=head;
   for(i=1;i<n;i++)
  {
     pt=(struct LNode*)malloc(sizeof(struct LNode));
     if(!pt)  {return 0;}
     p->next=pt;
     p=pt;
  }
    p->next=head; //构成循环链表
    pt=head;
return 0;
}
//3.创建输入密码函数
 int enterPwd(int n)        //参数n传递人数
{
   int i,j;
   printf("\n请输入密码: \n");
    for( i=1;i<=n;i++)
    {
       scanf("%d",&j);
       pt->num=i;        //num存储人的序号
       pt->pwd=j;         //pwd存储人的密码
       pt=pt->next;
    }
    pt=p;
return j;
}
 //4、创建输出函数
 int outList(int m,int n)    //参数m、n传递报数上限值和人数
{
   int i,a;
   for(i=1;i<=n;i++)         //用一个for循环搜索循环链表
   {
      for(a=1;a<m;a++)      //删除结点
      {
        pt=pt->next;
      }
      p=pt->next;
      m=p->pwd;
      printf("%d ",p->num);    //输出人的序号
      pt->next=p->next;
      free(p);          //释放动态申请的结点空间
   }
   printf("\n");
   return 0;
}
 //主函数
int  main()
{   int m,n;
    int c;//m为报数上限值，n为人数
    do
    {
        system("cls");
        printf("你好！欢迎使用约瑟夫环解决程序！\n");
        c=0;
        Sleep(1000);
        printf("\n参数m、n传递报数上限值和人数;\n");
        printf("\n请输入 m 和n: \n");
        scanf("%d %d",&m,&n);
        creatLinkList( n);  //调用创建链表函数
        enterPwd( n);       //调用输入密码函数
        printf("\n出队的人依次是:\n");
        outList( m,n);
        printf("again?\tyes(1)/no(0)\n");

        while((scanf("%d",&c),fflush(stdin),c!=1&&c!=0))
            printf("输入错误！请重新输入\nagain?\tyes(1)/no(0)\n");
    }  while(c==1);//调用输出链表函数

    return 0;
}
