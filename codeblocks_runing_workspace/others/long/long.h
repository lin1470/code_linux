#ifndef LONG_H_INCLUDED
#define LONG_H_INCLUDED
typedef struct dnode
{
    int data;
    struct dnode *pre,*next;
}DblNode;
typedef DblNode *DblList;


int get_length_from_char(char *);
DblList InitList(int length);//创建指定的循环链表节数的方法
void InsertList(char *string,DblList &list);
#endif // LONG_H_INCLUDED
