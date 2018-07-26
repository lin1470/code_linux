#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define STACK_INIT_SIZE 100 // the initial size is 100
#define STACK_INCREATMENT 10

typedef struct
{
    char *base;//point to the base of the stack
    char *top;//
    int stack_size;
}STACK;


void InitStack(STACK &s)//initialize the stack
{
    s.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
    s.top=s.base;
    s.stack_size=STACK_INIT_SIZE;
}

void push(STACK &s,char e)//push an element into the stack;
{
    if(s.top-s.base>=STACK_INIT_SIZE)
    {
        s.base=(char*)realloc(s.base,(s.stack_size+STACK_INCREATMENT)*sizeof(char));
        s.top=s.base+s.stack_size;
        s.stack_size+=STACK_INCREATMENT;
    }// expand the size of stack;
    *s.top=e;
    s.top++;
}
char pop(STACK &s,char &e)//pop the first element of the stack
{
    e=*--s.top;
    return e;
}

int stack_empty(STACK &s)
{
    return(s.top==s.base);
}

void clear_stack(STACK &s)
{
    s.top=s.base;
}

typedef struct node
{
    char data;
    struct node *next;
}QueueNode;

typedef struct
{
    QueueNode *rear,*front;//there are two pointers one point to the head another point to the last one .
}LinkQueue;

void init_queque(LinkQueue &q)//initialize a empty queque
{
    q.front=q.rear=(QueueNode*)malloc(sizeof(QueueNode));//front and the rear is the only one
    q.front->next=NULL;
}

void en_queque(LinkQueue &q,char e)
{
    QueueNode *p;
    p=(QueueNode*)malloc(sizeof(QueueNode));
    p->data=e;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
}

void de_queque(LinkQueue &q,char &e)
{
    QueueNode *p;
    p=q.front->next;
    e=p->data;//put this element into the "e".
    q.front=p->next;
    if(q.rear==p)
        q.rear=q.front;//判断是否出列的是最后一个元素了，如果是的话就咩有咯
    free(p);
}
int queque_empty(LinkQueue &q)
{
    return(q.front==q.rear);
}

void in_stack(char *string,STACK &s)
{
    int count_string=0;
    char *hh=string;
    while(string[count_string])
    {
        count_string++;
    }

    for(int i=count_string-1;i>=0;i--)
    {
        push(s,string[i]);
    }

}
int main()
{
    char language[20];
    char translatation[100];
    STACK stack;
    printf("shenme gi ");
    gets(language);
    in_stack(language,stack);
    while(!stack_empty(stack))
    {
        char e;
        pop(stack,e);
        printf("%c\n",e);
    }
    printf("%s\n",language);
    return 0;
}
