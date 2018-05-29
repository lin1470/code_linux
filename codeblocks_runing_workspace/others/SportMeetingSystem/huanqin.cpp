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
 	printf("请输入比赛项目");
 	
	  
 }
 
 void signup()
 {
 	char choice;
	system("cls");
	printf("请填写个人信息:");
	
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
		printf("请输入用户名和密码\n");
 		printf("用户名:");
 		scanf("%s",account);
 		printf("\n");
 		printf("密码:");
 		for(i=0;i<10&&((pwd[i]=getch())!=13);i++)
 	   		putchar('*');
 		pwd[i]='\0';
		if(strcmp(pwd,password)!=0)
		{
			printf("\n密码输入错误，重新输入");
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
		printf("\n\t1.运动项目发布\n");
		printf("\t2.运动项目修改\n");
		printf("\t3.比赛结果录入\n");
		printf("\t4.返回上一级\n");
		printf("\t5.退出\n");
		bound('_',30);
		
		
		fflush(stdin);
		choice=getchar();
		system("cls");
			
		switch(choice)
		{
			case'1':
				printf("\n运动项目发布");
				break; 
			case'2':
				printf("\n运动项目发布");
				break; 
			case'3':
				printf("\n运动项目发布");
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
 		printf("\t运动会管理系统\n");
 		bound('_',40);
 		printf("\t1.管理员登录\n");
 		printf("\t2.运动员报名\n");
 		printf("\t3.比赛成绩查询\n");
 		printf("\t4.运动项目信息及进程查询\n");
 		printf("\t5.退出\n");
 		bound('_',40);
 		printf("\n请选择你的操作！");
 		
 		
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