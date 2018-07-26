#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct node {
	char c;
	node* next;
	node* prior;
} ListNode;

typedef ListNode* LinkList;

typedef struct rnode {
	int num;
	char head;
	LinkList str1;                //表面字符串
	LinkList str2;                //解释完后的字符串
	rnode* next;
} RuleNode;

RuleNode* rules;

int destory(LinkList &l) {           //销毁字符串
	ListNode* p;
	ListNode* q;
	p=l->next;
	q=p->next;
	while(p!=l) {
		free(p);
		p=q;
		q=q->next;
	}
	free(p);
}

int prints(LinkList l) {             //打印字符串
	ListNode* p;
	p=l->next;
	while(p!=l) {
		printf("%c",p->c);
		p=p->next;
	}
}

LinkList connect(LinkList l1,LinkList l2) {           //连接字符串
	ListNode* p;
	ListNode* q;
	ListNode* r;
	LinkList res;
	q=l1->next;
	res=(ListNode*)malloc(sizeof(ListNode));
	p=res;
	while(q!=l1) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		r=p;
		p=p->next;
		p->c=q->c;
		p->prior=r;
		q=q->next;
	}
	q=l2->next;
	while(q!=l2) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		r=p;
		p=p->next;
		p->c=q->c;
		p->prior=r;
		q=q->next;
	}
	p->next=res;
	res->prior=p;
	return res;
}

LinkList opper2(LinkList l) {      //将字符串做括号内的处理
	ListNode* p;
	ListNode* q;
	ListNode* r;
	LinkList res;
	char head;
	if(l->next==l) {
		return l;
	}
	p=l->next;
	head=p->c;
	p=p->prior->prior;
	res=(ListNode*)malloc(sizeof(ListNode));
	res->next=(ListNode*)malloc(sizeof(ListNode));
	q=res->next;
	q->c=head;
	while(p!=l->next) {
		q->next=(ListNode*)malloc(sizeof(ListNode));
		r=q;
		q=q->next;
		q->c=p->c;
		q->prior=r;
		q->next=(ListNode*)malloc(sizeof(ListNode));
		r=q;
		q=q->next;
		q->c=head;
		q->prior=r;
		p=p->prior;
	}
	q->next=res;
	res->prior=q;
	return res;
}

int opper1(LinkList l,LinkList &p1,LinkList &p2,LinkList &p3) {         //将字符串按最外面最左边的括号拆成三个字符串,返回括号数量
	ListNode* p;
	ListNode* q;
	ListNode* r;
	int i=0,j=0,count=0;
	if(l->next==l) {
		return -2;                       //空链表
	}
	p=l->next;
	while(p!=l) {
		if(p->c=='(') {
			i++;
		} else if(p->c==')') {
			j++;
		}
		p=p->next;
	}
	if(i!=j) {                           //输入（）数量不等
		return -1;
	} else if(i==0) {
		return 0;                     //没有括号
	}
	p1=(ListNode*)malloc(sizeof(ListNode));
	p2=(ListNode*)malloc(sizeof(ListNode));
	p3=(ListNode*)malloc(sizeof(ListNode));
	p=l->next;
	q=p1;
	while(p->c!='(') {
		q->next=(ListNode*)malloc(sizeof(ListNode));
		r=q;
		q=q->next;
		q->c=p->c;
		q->prior=r;
		p=p->next;
	}
	q->next=p1;
	p1->prior=q;

	p=p->next;
	q=p2;
	count=0;
	while((count>0)||((p->c)!=')')) {
		q->next=(ListNode*)malloc(sizeof(ListNode));
		r=q;
		q=q->next;
		q->c=p->c;
		q->prior=r;
		if((p->c)=='(') {
			count=count+1;
		} else if((p->c)==')') {
			count=count-1;
		}
		p=p->next;
	}
	q->next=p2;
	p2->prior=q;

	p=p->next;
	q=p3;
	while(p!=l) {
		q->next=(ListNode*)malloc(sizeof(ListNode));
		r=q;
		q=q->next;
		q->c=p->c;
		q->prior=r;
		p=p->next;
	}
	q->next=p3;
	p3->prior=q;
	return i;
}

LinkList opper3(LinkList l) {               //去除所有括号
	LinkList res;
	LinkList temp;
	LinkList left;
	LinkList middle;
	LinkList right;
	int num=0;
	num=opper1(l,left,middle,right);
	if(num<=0) {
		return l;
	} else if(num==1) {
		temp=opper2(middle);
		res=connect(left,temp);
		destory(temp);
		temp=res;
		res=connect(res,right);
		destory(temp);
		return res;
	} else if(num>1) {
		temp=opper2(opper3(middle));
		res=connect(left,temp);
		destory(temp);
		temp=res;
		res=connect(res,opper3(right));
		destory(temp);
		return res;
	}
}

int start() {
	char temp;
	char head;
	int i=0,num=0,j=0;
	LinkList l1;
	LinkList l2;
	LinkList l3;
	ListNode* p;
	ListNode* q;
	ListNode* r;
	RuleNode* rule;
	LinkList copys(LinkList l);
	int replace(char head,LinkList &str2,LinkList l);

	l1=(ListNode*)malloc(sizeof(ListNode));           //输入原句，含头结点
	p=l1;
	printf("\n\n请输入要解释的句子：");
	while((temp=getchar())!=10) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		q=p;
		p=p->next;
		p->c=temp;
		p->prior=q;
	}
	p->next=l1;
	l1->prior=p;


	l2=opper3(l1);

	l3=copys(l2);
	rule=rules->next;
	while(rule!=rules) {
		replace(rule->head,l3,rule->str2);
		rule=rule->next;
	}
	prints(l3);
	printf("\n\n\n");
}

int compare1(LinkList l,char head) {
	ListNode* p;
	p=l->next;
	while(p!=l) {
		if(p->c==head) {
			return 1;
		}
		p=p->next;
	}
	return 0;
}

int replace(char head,LinkList &str2,LinkList l) {
	ListNode* p;
	ListNode* q;
	ListNode* r;
	ListNode* s;
	ListNode* t;
	ListNode* u;

	p=l->next;
	q=str2->next;
	while(q!=str2) {
		if(q->c==head) {
			r=q->next;
			q=q->prior;
			s=(ListNode*)malloc(sizeof(ListNode));
			t=s;
			p=l->next;
			while(p!=l) {
				t->next=(ListNode*)malloc(sizeof(ListNode));
				u=t;
				t=t->next;
				t->c=p->c;
				t->prior=u;
				p=p->next;
			}
			q->next=s->next;
			s->next->prior=q;
			t->next=r;
			r->prior=t;

			q=r;
		} else {
			q=q->next;
		}
	}
}

int addr(char head,LinkList l1,LinkList l2,RuleNode* &rules) {
	RuleNode* r;
	RuleNode* r2;
	LinkList t;
	LinkList t2;
	ListNode* p;
	ListNode* q;
	ListNode* n;
	r=rules->next;
	while(r->next!=rules) {
		r=r->next;
	}
	rules->num=rules->num+1;
	r2=(RuleNode*)malloc(sizeof(RuleNode));
	r2->head=head;
	r2->num=rules->num;

	t=(ListNode*)malloc(sizeof(ListNode));
	p=t;
	q=l1->next;
	while(q!=l1) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		n=p;
		p=p->next;
		p->c=q->c;
		p->prior=n;
		q=q->next;
	}
	p->next=t;
	t->prior=p;

	t2=(ListNode*)malloc(sizeof(ListNode));
	p=t2;
	q=l2->next;
	while(q!=l2) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		n=p;
		p=p->next;
		p->c=q->c;
		p->prior=n;
		q=q->next;
	}
	p->next=t2;
	t2->prior=p;

	r2->str1=t;
	r2->str2=t2;

	r2->next=rules;
	r->next=r2;

}

LinkList copys(LinkList l) {
	LinkList res;
	ListNode* p;
	ListNode* q;
	ListNode* n;
	p=l->next;
	res=(ListNode*)malloc(sizeof(ListNode));
	q=res;
	while(p!=l) {
		q->next=(ListNode*)malloc(sizeof(ListNode));
		n=q;
		q=q->next;
		q->c=p->c;
		q->prior=n;
		p=p->next;
	}
	q->next=res;
	res->prior=q;
	return res;
}

int addrule() {
	char head;
	char temp;
	int flag=0,flag2=0,flag3=0,i,j;
	LinkList l1;
	LinkList l2;
	RuleNode* r;
	ListNode* p;
	ListNode* q;
	printf("\n\na->b1b2...bm\n");
	printf("\n请输入a的值：");
	scanf("%c",&head);
	getchar();
	printf("请输入b1b2b...bm的值：");
	l1=(ListNode*)malloc(sizeof(ListNode));
	p=l1;
	while((temp=getchar())!=10) {
		p->next=(ListNode*)malloc(sizeof(ListNode));
		q=p;
		p=p->next;
		p->c=temp;
		p->prior=q;
	}
	p->next=l1;
	l1->prior=p;

	flag=1;                //代表输入无误
	if(compare1(l1,head)==1) {
		flag=0;
		printf("\nb1b2b...bm中不能含有a！\n");
		return 0;
	}
	flag2=1;     //代表规则不相关
	flag3=1;     //代表规则不需要改变
	r=rules->next;
	while(r!=rules) {
		if(r->head==head) {
			flag=-1;                 //代表a重复
			break;
		}
		if(compare1(r->str2,head)==1) {
			flag2=0;
			if(compare1(l1,r->head)==1) {
				flag=-2;              //代表循环冲突
				break;
			}
		}
		if(compare1(l1,r->head)==1) {
			flag3=0;
		}
		r=r->next;
	}
	if(flag==1) {
		if((flag2==0)&&(flag3!=0)) {
			r=rules->next;
			while(r!=rules) {
				if(compare1(r->str2,head)==1) {
					replace(head,r->str2,l1);
				}
				r=r->next;
			}
			addr(head,l1,l1,rules);
		} else if((flag2!=0)&&(flag3==0)) {
			r=rules->next;
			l2=copys(l1);
			while(r!=rules) {
				if(compare1(l1,r->head)==1) {
					replace(r->head,l1,r->str2);
				}
				r=r->next;
			}
			addr(head,l2,l1,rules);
		} else if((flag2==0)&&(flag3==0)) {
			r=rules->next;
			l2=copys(l1);
			while(r!=rules) {
				if(compare1(l1,r->head)==1) {
					replace(r->head,l1,r->str2);
				}
				r=r->next;
			}
			r=rules->next;
			while(r!=rules) {
				if(compare1(r->str2,head)==1) {
					replace(head,r->str2,l1);
				}
				r=r->next;
			}
			addr(head,l2,l1,rules);
		} else {
			addr(head,l1,l1,rules);
		}
	} else if(flag==-1) {
		printf("\na有重复！\n");
	} else if(flag==-2) {
		printf("\n循环冲突！\n");
	}

}

int view() {
	char head;
	LinkList l1;
	LinkList l2;
	RuleNode* r;
	ListNode* p;
	ListNode* q;
	r=rules->next;
	while(r!=rules) {
		printf("\n%c->",r->head);
		prints(r->str1);
		printf("   ");
		prints(r->str2);
		r=r->next;
	}
}

int main() {
	char key=0;
	int kaiguan2=0;
	rules=(RuleNode*)malloc(sizeof(RuleNode));
	rules->num=0;
	rules->next=rules;
	while(1) {
		kaiguan2=0;
		system("cls");
		printf("\t迎来到魔王的世界！\n\t\t");
		printf("\n-----------------------------------------\n");
		printf("    1.添加		   2.解释语言  			\n");
		//printf("    3.解释语言		     			\n");
		printf("                        	Esc.退出\n");
		printf("------------------------------------------\n");
		printf("请输入你的选择：");
		while(1) {
			key=getchar();
			fflush(stdin);
			switch(key) {
				case '1':
					addrule();
					printf("\n\n\n");
					kaiguan2=1;
					break;
				case '3':
					view();
					printf("\n\n\n");
					kaiguan2=1;
					break;
				case '2':
					start();
					printf("\n\n\n");
					kaiguan2=1;
					system("pause");
					break;
				case 27 :
					return 0;
			}
			if(kaiguan2==1) {
				break;
			}
		}
	}
}
