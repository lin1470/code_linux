#include <stdio.h>
#include "student.h"
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
//#inlcude<conio.h>
int player_number=0;
int project_number=0;
int check_account()
{
    char real_account[10];
    char real_password[10];
    int i;
    fflush(stdin);
    printf("account:");
    gets(real_account);
    printf("password:");
    for(i=0;i<10&&((real_password[i]=getch())!=13);i++)
 	   		    putchar('*');
 	   		    putchar('\n');
 		real_password[i]='\0';
    if(strcmp(real_account,account)==0&&strcmp(real_password,password)==0)
            {
                printf("登陆成功！\n");
                Sleep(1000);
                return 1;
            }
    else {
            printf("输入的账号或者密码错误，请重新输入！\n");
            Sleep(1000);//用一个sleep函数来实现在一秒之后自动刷新屏幕。
            system("cls");
            return 0;
        }

}
char* stringLink(char *str1,char *str2)
{
	char *result=(char *)malloc(strlen(str1)+strlen(str2)+1);
	if(result==NULL)
	{
		printf("内存申请错误!");
	}
	else
	{
		strcpy(result,str1);
		strcat(result,str2);
	}
	return result;
}

 void bound(char ch,int n)
 {
 	while(n--)
		putchar(ch);

	printf("\n");
	return;
 }//划分界限

 void mainmenu()//手动打印界面
 {
 	char choice;
    udapt_playerArray(100);
    udapt_projectArray(7);
 	do{
            system("cls");
 		printf("\t运动会管理系统\n");
 		bound('_',40);
 		printf("\t1.管理员登录\n");
 		printf("\t2.运动员报名\n");
 		printf("\t3.比赛成绩查询\n");
 		printf("\t4.运动项目信息及进程查询\n");
 		printf("\t5.退出\n");
 		bound('_',40);
 		printf("\n请选择你的操作:");


 	    fflush(stdin);
		choice=getchar();
		system("cls");
		system("cls");

		switch(choice)
		{
			case'1':
				{
				    while(check_account()==0);
                    admin_manage();
                    break;
				}
			case'2':
			    {

			        join_project();
			        break;
			    }

			case'3':
				break;
			case'4':
			    show_project_in_detail();
				break;
			case'5':
				exit(EXIT_SUCCESS);
            default:break;
		}


	 }while(1);
 }

 void admin_manage()
 {

	char choice;


 	do{
        system("cls");
 		bound('_',30);
		printf("\n\t1.运动项目发布\n");
		printf("\t2.运动项目修改\n");
		printf("\t3.比赛结果录入\n");
		printf("\t4.返回上一级\n");
		printf("\t5.退出\n");
		bound('_',30);

        printf("请输入你的选择：");
		fflush(stdin);
		choice=getchar();
		fflush(stdin);
		system("cls");

		switch(choice)
		{
			case'1':
                {
                addProject();
                //printf("添加项目");
                Sleep(1000);
                system("cls");
				break;
                }

			case'2':
			    {
                    udate_project();
                    break;
			    }
			case'3':
				{printf("\n运动项目发布");
				break;}
			case'4':
				{
				    break;
				}
			case'5':
				exit(0);

		}
		if(choice=='4')
		  break;

	 }while(1);

 }

 void addProject(void)
 {
     FILE *fp;
    project *pr;
    project PROJECT[MAX_PROJECT_NUMBER];
    int size=sizeof(project);
    int count=show_project();
    printf("\n");
    //show_project();
    char c;
    printf("你想要添加还是重新录入？\n");
    printf("1.添加项目\t 2.重新录入项目\n");
    printf("请输入选择：");
    c=getchar();
    fflush(stdin);
    switch(c)
    {
        case '1':{fp=fopen("项目名册.txt","a+");break;}//这个是添加在末尾的
        case '2':{fp=fopen("项目名册.txt","w");break;}
    }
    if(fp==NULL)
    {
        fputs("can't open 项目名册.txt file\n",stderr);
        exit(1);
    }
    if(c=='2')
       {

       for(int i=0;i<MAX_PROJECT_NUMBER;i++)
        {
            pr=get_project_from_input();
            PROJECT[i]=*pr;
            free(pr);
        }
        count=MAX_PROJECT_NUMBER;
        fwrite(PROJECT,size,MAX_PROJECT_NUMBER,fp);
       }
    else
        {
            if(count>=7)
                printf("项目个数大于7，无法再添加项目了！\n");
            else{
                rewind(fp);
                fread(PROJECT,SIZE_OF_PROJECT,count,fp);
                pr=get_project_from_input();
                PROJECT[count]=*pr;
                free(pr);
                fwrite(&PROJECT[count],size,1,fp);
                }
        }
    //注意

    fclose(fp);
    udapt_projectArray(((count<=MAX_PROJECT_NUMBER)? count:MAX_PROJECT_NUMBER));
    fputs("输入了全部的项目了！",stdout);
    Sleep(2000);
 }
 void udate_project(void)
 {
    int count=show_project();
    FILE *fp;
    project PROJECT[MAX_PROJECT_NUMBER];
    project* pr;
    if((fp=fopen("项目名册.txt","r+"))==NULL)
        {
            fputs("打开项目名册.txt失败",stderr);
            exit(1);
        }
    rewind(fp);
    fread(PROJECT,SIZE_OF_PROJECT,count,fp);
    printf("输入你要修改的项目：");
    int choice;
    scanf("%d",&choice);
    pr=get_project_from_input();//读取pr的更新后的值
    PROJECT[choice-1]=*pr;//然后把pr的值复制给
    rewind(fp);//rewind然后在把数组的值还原给原本的项目名册。
    fwrite(PROJECT,SIZE_OF_PROJECT,count,fp);
    printf("项目更新成功！");
    Sleep(2000);
    fclose(fp);



 }

 int show_project(void)//这个函数会返回一个已经存在的项目数的个数
 {
     FILE *fp;
     project PROJECT[MAX_PROJECT_NUMBER];
   //  project pr;
     if((fp=fopen("项目名册.txt","r"))==NULL)
     {
         fputs("无法打开 项目名册.txt",stderr);
         exit(1);
     }

      bound('=',120);
   // printf("\n");
    printf("项目：");
     int pro_size=sizeof(project);
    int existed_count=fread(PROJECT,pro_size,MAX_PROJECT_NUMBER,fp);
    for(int i=0;i<existed_count;i++)
        printf("%d.%s\t",i+1,PROJECT[i].man.projectName);
    putchar('\n');
    fclose(fp);
    return existed_count;
 }
void show_project_in_detail(void)
{
    FILE *fp;
    fp=fopen("项目名册.txt","r");
    project_number=fread(all_projects,SIZE_OF_PROJECT,MAX_PROJECT_NUMBER,fp);
    for(int i=0;i<project_number;i++)
        printf("项目号码%d\t\t项目名%s\t\t项目开始时间%.2f\t\t项目结束时间%.2f\n",all_projects[i].man.projectCode,all_projects[i].man.projectName,all_projects[i].man.beganTime,all_projects[i].man.endedTime);
    fclose(fp);
    system("pause");
    return 0;
}
 void show_player(void)
 {
     FILE* fp;
     fp=fopen("学生名册.txt","r");
     player_number=fread(all_players,SIZE_OF_PLAYER,MAX_PEOPLE_NUMBER,fp);
     printf("下面是学生们的信息：");
     for(int i=0;i<player_number;i++)
     printf("学号%d，性别%s，姓名%s，学院%s，项目1%d，项目2%d，项目3%d\n",all_players[i].playerCode,all_players[i].gender,all_players[i].playerName,all_players[i].college,all_players[i].project_in[0].projectCode,all_players[i].project_in[1].projectCode,all_players[i].project_in[2].projectCode);
    printf("一共有%d个运动员！",player_number);
    fclose(fp);
    return 0;
 }
project* get_project_from_input(void)
{
        project pr;
        project* pr1=(project*)malloc(SIZE_OF_PROJECT);
        system("cls");
        printf("请输入项目编码:");
        scanf("%d",&pr.man.projectCode);
        pr.womman.projectCode=pr.man.projectCode;
        printf("请输入项目名称:");
        scanf("%s",&pr.man.projectName);
        printf("是否是团体项目:");
        fflush(stdin);
        printf("Y/N?\n");
        char c=getchar();
        if(c=='y'||c=='Y')
            {   pr.man.isGroupProject=1;pr.womman.isGroupProject=1;}
        else {  pr.man.isGroupProject=0;pr.womman.isGroupProject=0;}
        strcpy(pr.womman.projectName,pr.man.projectName);
        printf("请输入项目进行的场地:");
        scanf("%s",&pr.man.projectPlace);
        strcpy(pr.womman.projectPlace,pr.man.projectPlace);
        printf("请输入项目开始时间:");
        scanf("%f",&pr.man.beganTime);
        pr.womman.beganTime=pr.man.beganTime;
        printf("请输入项目结束时间:");
        scanf("%f",&pr.man.endedTime);
        pr.womman.endedTime=pr.man.endedTime;
        printf("请输入项目单位:");
        scanf("%s",pr.man.unitOfMeasurement);
        strcpy(pr.womman.unitOfMeasurement,pr.man.unitOfMeasurement);
        *pr1=pr;
        return pr1;
}
void udapt_projectArray(int count)
{
    FILE* fp;
    fp=fopen("项目名册.txt","r");
    if(fp==NULL)
    {
        printf("无法打开项目名册.txt");
        exit(1);//退出异常的
    }
    project_number=fread(all_projects,SIZE_OF_PROJECT,count,fp);
    fclose(fp);
    return 0;
}
void udapt_playerArray(int count)
{
    FILE* fp;
    if((fp=fopen("学生名册.txt","r"))==NULL)
    {
        printf("打开学生名册.txt失败","r");
        exit(1);
    }
    player_number=fread(all_players,SIZE_OF_PLAYER,count,fp);
    fclose(fp);
    return 0;
}

void join_project(void)//学生报名的过程实际上就是把信息存进文件的过程
{
    FILE *fp;
    char c;
    player_record* player;
    printf("你好随机输入学生名册还是自己输入：1.随机输入\t 2.手动输入\n");
    c=getchar();
    fflush(stdin);
    if(c=='1')
    {
        printf("注意这个是清空原来的文件然后自动获取70个人的运动员信息。");
        player_number=0;
        fp=fopen("学生名册.txt","w+");
       // printf()
           for(int i=0;i<70;i++)
            {
            player=get_player_from_rand();
            fwrite(player,SIZE_OF_PLAYER,1,fp);
            free(player);
            }
    }
    else
    {
        fp=fopen("学生名册.txt","a+");
        player_number=fread(all_players,SIZE_OF_PLAYER,MAX_PEOPLE_NUMBER,fp);//读取已有的学生的个数是没有错的吧
        player=get_player_from_input();
        fwrite(player,SIZE_OF_PLAYER,1,fp);
       free(player);
    }



   // fwrite(player,SIZE_OF_PLAYER,1,fp);
   // free(player);
    fclose(fp);
    udapt_playerArray(player_number);
    return 0;
}

player_record* get_player_from_input(void)
{
    system("cls");
    player_number++;
    printf("你是第%d报名的学生!\n",player_number);
    player_record* player=(player_record*)malloc(SIZE_OF_PLAYER);
    printf("请先填写运动员基本的信息！\n");
    printf("请输入学号：");
    scanf("%d",&player->playerCode);
    fflush(stdin);
    printf("请输入性别:1.男   2.女    \n ");
    char c=getchar();
    fflush(stdin);
    while(c!='1'&&c!='2')
    {
        printf("输入有误！请重新输入！\n");
        c=getchar();
        fflush(stdin);
    }
    if(c=='1')
        strcpy(player->gender,"男");
    else
        strcpy(player->gender,"女");
    fflush(stdin);
    printf("请输入姓名：");
    scanf("%s",&player->playerName);
    printf("请输入学院；");
    scanf("%s",&player->college);
    printf("个人信息输入完毕！");
    fflush(stdin);
    Sleep(1000);
    system("cls");
    printf("请看现在可以报的项目  (请注意你只能参加最多三项的比赛)\n");
    //udapt_playerArray(MAX_PROJECT_NUMBER);
    show_project();
    printf("请输入第一项比赛(输入号码，或n以退出)");
    c=getchar();
    //fflush(stdin);
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[0].projectCode=all_projects[c-'0'].man.projectCode;
    else {player->project_in[0].projectCode=0;player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
    printf("请输入第二项比赛(输入号码，或n以退出)");
    c=getchar();
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[1].projectCode=all_projects[c-'0'].man.projectCode;
    else {player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
    printf("请输入第三项比赛(输入号码，或n以退出)");
    c=getchar();
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[2].projectCode=all_projects[c-'0'].man.projectCode;
    else {player->project_in[2].projectCode=0;}
    return player;
}

player_record* get_player_from_rand()
{
    udapt_playerArray(player_number);
    udapt_projectArray(7);
    char* rand_str="abcdefghijklmnopqrstuvwsyz";
//    int rand_number[10]={0,1,2,3,4,5,6,7,8,9};
    srand(time(NULL));//set the seed of the rand number.
   // system("cls");
    player_number++;
    printf("自动生成你是第%d报名的学生!\n",player_number);
    player_record* player=(player_record*)malloc(SIZE_OF_PLAYER);
    printf("请先填写运动员基本的信息！\n");
    printf("请输入学号：");
   // scanf("%d",&player->playerCode);
   player->playerCode=rand()%1000+2015100000;
    printf("请输入性别:1.男   2.女    \n ");
   char c;
    if(rand()%2)
        c='1';
    else c='2';
    /*while(c!='1'&&c!='2')
    {
        printf("输入有误！请重新输入！\n");
        c=getchar();
        fflush(stdin);
    }*/
    if(c=='1')
        strcpy(player->gender,"男");
    else
        strcpy(player->gender,"女");//set the gender of the player.
        printf("运动员的性别：%s",player->gender);
        char* project_gender=&player->gender;
        char* project_college=&player->college;
       // system("pause");
    printf("请输入姓名：");
    //scanf("%s",&player->playerName);
    srand(time(NULL));
    strncpy(player->playerName,rand_str+rand()%20,5);
    player->playerName[5]='\0';
    printf("%s",player->playerName);
    printf("请输入学院；");
   // scanf("%s",&player->college);
   srand(time(NULL));
   strncpy(player->college,rand_str+rand()%20,5);//
    player->college[5]='\0';//randomly set the name and college of player.
    printf("%s",player->college);
  //  system("pause");
    printf("个人信息输入完毕！");
   // fflush(stdin);
    //Sleep(1000);
    //system("cls");
   // printf("请看现在可以报的项目  (请注意你只能参加最多三项的比赛)\n");
    //udapt_playerArray(MAX_PROJECT_NUMBER);
    show_project();
    printf("请输入第一项比赛(输入号码，或n以退出)");
    srand(time(NULL));
    c=rand()%7+'0'+1;
    putchar(c);
    //fflush(stdin);
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[0].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[0].projectCode=0;player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
   // printf("%d\t%d", player->project_in[0].projectCode,all_projects[c-'0'-1].man.projectCode);//注意了这个是调试项目号码为什么会是零
   // system("pause");
    printf("请输入第二项比赛(输入号码，或n以退出)");
   // c=getchar();
   c=rand()%7+'0'+1;
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[1].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[1].projectCode=0;player->project_in[1].projectCode=0;return player;}
    printf("请输入第三项比赛(输入号码，或n以退出)");
   // c=getchar();
   c=rand()%7+'0'+1;
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[2].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[2].projectCode=0;}
   // printf("学号：%d性别：%s名字：%s项目一：%d项目二：%d项目三：%d\n",player->playerCode,player->gender,player->playerName,player->project_in[0].projectCode,player->project_in[1].projectCode,player->project_in[2].projectCode);
   Sleep(100);
    //system("pause");
    return player;


}
void creat_project_file(void)
{
    udapt_playerArray(100);//先更新程序中的运动员数组，和确定了运动员的个数
    udapt_projectArray(7);//先更新程序中项目数组，和确定了项目的个数
    FILE* fp;
    int playerCode_in_project[100];
    char* file_name;
    int project_player_number=0;//这个内部变量是用来显示这个项目名字有多少个人的。
    for(int i=0;i<project_number;i++)
    {
        project_player_number=0;
        file_name=stringLink("男子",all_projects[i].man.projectName);
        strcat(file_name,".txt");
        for(int j=0;j<player_number;j++)
        {
           // printf("%s",all_players[j].gender);//发现错误了，性别输入有误。
           // printf("项目编号：%d",all_projects[i].man.projectCode);
           // printf("运动员的第一个项目的编号%d",all_players[j].project_in[0].projectCode);
           // printf("运动员的第一个项目的编号%d",all_players[j].project_in[1].projectCode);
           // printf("运动员的第一个项目的编号%d",all_players[j].project_in[2].projectCode);

        if(strcmp(all_players[j].gender,"男")==0&&(all_players[j].project_in[0].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[1].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[2].projectCode==all_projects[i].man.projectCode))
            {
                project_player_number++;
                playerCode_in_project[project_player_number-1]=all_players[j].playerCode;
            }
        }
        printf("%s项目的人数是%d人\n",file_name,project_player_number);
        fp=fopen(file_name,"w");
        free(file_name);
        printf("请显示是否成功了？%d\n",fwrite(playerCode_in_project,sizeof(int)*100,1,fp));
        fclose(fp);
    }
    memset(playerCode_in_project,0,sizeof(int)*100);
     for(int i=0;i<project_number;i++)
    {
        project_player_number=0;
        file_name=stringLink("女子",all_projects[i].man.projectName);
        strcat(file_name,".txt");
        for(int j=0;j<player_number;j++)
        if(strcmp(all_players[j].gender,"女")==0&&(all_players[j].project_in[0].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[1].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[2].projectCode==all_projects[i].man.projectCode))
            {
                project_player_number++;
                playerCode_in_project[project_player_number-1]=all_players[j].playerCode;
            }
        printf("%s项目的人数：%d\n",file_name,project_player_number);
        fp=fopen(file_name,"w");
        free(file_name);
        printf("请显示是否成功了？%d\n",fwrite(playerCode_in_project,sizeof(int)*100,1,fp));
        fclose(fp);
    }
}

