#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL)
		return NULL;
	TreeLinkNode *next = NULL;
	if (pNode->right != NULL)
	{ //if there is a right tree of the node
		TreeLinkNode *p = pNode->right;
		while (p->left != NULL)
			p = p->left;
		next = p;
	}
	else if (pNode->next != NULL && pNode->next->left == pNode)
	{
		next = pNode->next;
	}
	else
	{
		TreeLinkNode *p = pNode;
		while (p->next != NULL)
		{
			TreeLinkNode *old = p;
			p = p->next;
			if (p->left == old)
			{
				next = p;
				break;
			}
		}
	}
	return next;
}
void print_next(TreeLinkNode *head)
{
	if (head == NULL)
		return;
	print_next(head->left);
	if (GetNext(head) != NULL)
	{
		printf("the next value of %d is %d\n", head->val, GetNext(head)->val);
	}
	
	print_next(head->right);

}
int main()
{
	TreeLinkNode a(1);
	TreeLinkNode b(2);
	TreeLinkNode c(3);
	TreeLinkNode d(4);
	TreeLinkNode e(5);
	TreeLinkNode f(6);
	TreeLinkNode g(7);
	a.left = &b; a.right = &c;
	b.next = &a; b.left = &d; b.right = &e;
	d.next = &b; e.next = &b;
	c.next = &a; c.left = &f; c.right = &g;
	f.next = &c; g.next = &c;
	//TreeLinkNode *next = GetNext(&d);
	//printf("the next value is %d\n", next->val);
	print_next(&a);
	system("pause");

}
