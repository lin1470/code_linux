#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void mainmenu();
void bound(char c,int a);
void login();
void manage();

typedef struct student
{
	char num[12];
	char name[20];
	unsigned char age[3];
	char sex[6];
	char department[25];
	char college[25];
	char join1[20];
	char join2[20];
	char join3[20];
	int score1,score2,score3;
	struct student *next;
}student;


typedef struct sport
{
	char name[15];
	int pcounts;
	char place[5];
	char strattime[10];
	char endtime[10];
	int statu;
}sport;
    
 char account[]="admin";
 char password[]="123456";
 student *first,*end;
 
 
 void logging()
 {
 	system("cls");
 	printf("�����������Ŀ");
 	
	  
 }
 
 void signup()
 {
 	char choice;
	system("cls");
	printf("����д������Ϣ:");
	
 }
 void bound(char ch,int n)
 {
 	while(n--)
		putchar(ch);
		
	printf("\n");
	return;
 }
 
 void login()
 {  int i;
    char account[10];
 	char pwd[10];
 	int flag=1;
	do{
		printf("�������û���������\n");
 		printf("�û���:");
 		scanf("%s",account);
 		printf("\n");
 		printf("����:");
 		for(i=0;i<10&&((pwd[i]=getch())!=13);i++)
 	   		putchar('*');
 		pwd[i]='\0';
		if(strcmp(pwd,password)!=0)
		{
			printf("\n�������������������");
			flag=0;
		}
		 
		    
	}while(flag==0);

	
 	    
 }
 void manage()
 {
 	
	char choice;
 	system("cls");
 	
 	do{
 		bound('_',30);
		printf("\n\t1.�˶���Ŀ����\n");
		printf("\t2.�˶���Ŀ�޸�\n");
		printf("\t3.�������¼��\n");
		printf("\t4.������һ��\n");
		printf("\t5.�˳�\n");
		bound('_',30);
		
		
		fflush(stdin);
		choice=getchar();
		system("cls");
			
		switch(choice)
		{
			case'1':
				printf("\n�˶���Ŀ����");
				break; 
			case'2':
				printf("\n�˶���Ŀ����");
				break; 
			case'3':
				printf("\n�˶���Ŀ����");
				break; 	
			case'4':
				break;
			case'5':
				exit(0);	
					
		}
		if(choice='4')
		  break;
		
	 }while(1);
	 
 }
 
 void sign()
 {
  } 
 void mainmenu()
 {
 	char choice;
 	system("cls");
 	
 	do{
 		printf("\t�˶������ϵͳ\n");
 		bound('_',40);
 		printf("\t1.����Ա��¼\n");
 		printf("\t2.�˶�Ա����\n");
 		printf("\t3.�����ɼ���ѯ\n");
 		printf("\t4.�˶���Ŀ��Ϣ�����̲�ѯ\n");
 		printf("\t5.�˳�\n");
 		bound('_',40);
 		printf("\n��ѡ����Ĳ�����");
 		
 		
 	    fflush(stdin);
		choice=getchar();
		system("cls");
			
		switch(choice)
		{
			case'1':
				login();
				manage();
				break;
			case'2':
				break;
			case'3':
				break;	
			case'4':
				break;	
			case'5':
				break;					
		}
		 
 		
	 }while(1);
 }
 int main()
 {
 	mainmenu();
 	return 0;
 }