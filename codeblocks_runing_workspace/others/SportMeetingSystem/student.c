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
                printf("��½�ɹ���\n");
                Sleep(1000);
                return 1;
            }
    else {
            printf("������˺Ż�������������������룡\n");
            Sleep(1000);//��һ��sleep������ʵ����һ��֮���Զ�ˢ����Ļ��
            system("cls");
            return 0;
        }

}
char* stringLink(char *str1,char *str2)
{
	char *result=(char *)malloc(strlen(str1)+strlen(str2)+1);
	if(result==NULL)
	{
		printf("�ڴ��������!");
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
 }//���ֽ���

 void mainmenu()//�ֶ���ӡ����
 {
 	char choice;
    udapt_playerArray(100);
    udapt_projectArray(7);
 	do{
            system("cls");
 		printf("\t�˶������ϵͳ\n");
 		bound('_',40);
 		printf("\t1.����Ա��¼\n");
 		printf("\t2.�˶�Ա����\n");
 		printf("\t3.�����ɼ���ѯ\n");
 		printf("\t4.�˶���Ŀ��Ϣ�����̲�ѯ\n");
 		printf("\t5.�˳�\n");
 		bound('_',40);
 		printf("\n��ѡ����Ĳ���:");


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
		printf("\n\t1.�˶���Ŀ����\n");
		printf("\t2.�˶���Ŀ�޸�\n");
		printf("\t3.�������¼��\n");
		printf("\t4.������һ��\n");
		printf("\t5.�˳�\n");
		bound('_',30);

        printf("���������ѡ��");
		fflush(stdin);
		choice=getchar();
		fflush(stdin);
		system("cls");

		switch(choice)
		{
			case'1':
                {
                addProject();
                //printf("�����Ŀ");
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
				{printf("\n�˶���Ŀ����");
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
    printf("����Ҫ��ӻ�������¼�룿\n");
    printf("1.�����Ŀ\t 2.����¼����Ŀ\n");
    printf("������ѡ��");
    c=getchar();
    fflush(stdin);
    switch(c)
    {
        case '1':{fp=fopen("��Ŀ����.txt","a+");break;}//����������ĩβ��
        case '2':{fp=fopen("��Ŀ����.txt","w");break;}
    }
    if(fp==NULL)
    {
        fputs("can't open ��Ŀ����.txt file\n",stderr);
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
                printf("��Ŀ��������7���޷��������Ŀ�ˣ�\n");
            else{
                rewind(fp);
                fread(PROJECT,SIZE_OF_PROJECT,count,fp);
                pr=get_project_from_input();
                PROJECT[count]=*pr;
                free(pr);
                fwrite(&PROJECT[count],size,1,fp);
                }
        }
    //ע��

    fclose(fp);
    udapt_projectArray(((count<=MAX_PROJECT_NUMBER)? count:MAX_PROJECT_NUMBER));
    fputs("������ȫ������Ŀ�ˣ�",stdout);
    Sleep(2000);
 }
 void udate_project(void)
 {
    int count=show_project();
    FILE *fp;
    project PROJECT[MAX_PROJECT_NUMBER];
    project* pr;
    if((fp=fopen("��Ŀ����.txt","r+"))==NULL)
        {
            fputs("����Ŀ����.txtʧ��",stderr);
            exit(1);
        }
    rewind(fp);
    fread(PROJECT,SIZE_OF_PROJECT,count,fp);
    printf("������Ҫ�޸ĵ���Ŀ��");
    int choice;
    scanf("%d",&choice);
    pr=get_project_from_input();//��ȡpr�ĸ��º��ֵ
    PROJECT[choice-1]=*pr;//Ȼ���pr��ֵ���Ƹ�
    rewind(fp);//rewindȻ���ڰ������ֵ��ԭ��ԭ������Ŀ���ᡣ
    fwrite(PROJECT,SIZE_OF_PROJECT,count,fp);
    printf("��Ŀ���³ɹ���");
    Sleep(2000);
    fclose(fp);



 }

 int show_project(void)//��������᷵��һ���Ѿ����ڵ���Ŀ���ĸ���
 {
     FILE *fp;
     project PROJECT[MAX_PROJECT_NUMBER];
   //  project pr;
     if((fp=fopen("��Ŀ����.txt","r"))==NULL)
     {
         fputs("�޷��� ��Ŀ����.txt",stderr);
         exit(1);
     }

      bound('=',120);
   // printf("\n");
    printf("��Ŀ��");
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
    fp=fopen("��Ŀ����.txt","r");
    project_number=fread(all_projects,SIZE_OF_PROJECT,MAX_PROJECT_NUMBER,fp);
    for(int i=0;i<project_number;i++)
        printf("��Ŀ����%d\t\t��Ŀ��%s\t\t��Ŀ��ʼʱ��%.2f\t\t��Ŀ����ʱ��%.2f\n",all_projects[i].man.projectCode,all_projects[i].man.projectName,all_projects[i].man.beganTime,all_projects[i].man.endedTime);
    fclose(fp);
    system("pause");
    return 0;
}
 void show_player(void)
 {
     FILE* fp;
     fp=fopen("ѧ������.txt","r");
     player_number=fread(all_players,SIZE_OF_PLAYER,MAX_PEOPLE_NUMBER,fp);
     printf("������ѧ���ǵ���Ϣ��");
     for(int i=0;i<player_number;i++)
     printf("ѧ��%d���Ա�%s������%s��ѧԺ%s����Ŀ1%d����Ŀ2%d����Ŀ3%d\n",all_players[i].playerCode,all_players[i].gender,all_players[i].playerName,all_players[i].college,all_players[i].project_in[0].projectCode,all_players[i].project_in[1].projectCode,all_players[i].project_in[2].projectCode);
    printf("һ����%d���˶�Ա��",player_number);
    fclose(fp);
    return 0;
 }
project* get_project_from_input(void)
{
        project pr;
        project* pr1=(project*)malloc(SIZE_OF_PROJECT);
        system("cls");
        printf("��������Ŀ����:");
        scanf("%d",&pr.man.projectCode);
        pr.womman.projectCode=pr.man.projectCode;
        printf("��������Ŀ����:");
        scanf("%s",&pr.man.projectName);
        printf("�Ƿ���������Ŀ:");
        fflush(stdin);
        printf("Y/N?\n");
        char c=getchar();
        if(c=='y'||c=='Y')
            {   pr.man.isGroupProject=1;pr.womman.isGroupProject=1;}
        else {  pr.man.isGroupProject=0;pr.womman.isGroupProject=0;}
        strcpy(pr.womman.projectName,pr.man.projectName);
        printf("��������Ŀ���еĳ���:");
        scanf("%s",&pr.man.projectPlace);
        strcpy(pr.womman.projectPlace,pr.man.projectPlace);
        printf("��������Ŀ��ʼʱ��:");
        scanf("%f",&pr.man.beganTime);
        pr.womman.beganTime=pr.man.beganTime;
        printf("��������Ŀ����ʱ��:");
        scanf("%f",&pr.man.endedTime);
        pr.womman.endedTime=pr.man.endedTime;
        printf("��������Ŀ��λ:");
        scanf("%s",pr.man.unitOfMeasurement);
        strcpy(pr.womman.unitOfMeasurement,pr.man.unitOfMeasurement);
        *pr1=pr;
        return pr1;
}
void udapt_projectArray(int count)
{
    FILE* fp;
    fp=fopen("��Ŀ����.txt","r");
    if(fp==NULL)
    {
        printf("�޷�����Ŀ����.txt");
        exit(1);//�˳��쳣��
    }
    project_number=fread(all_projects,SIZE_OF_PROJECT,count,fp);
    fclose(fp);
    return 0;
}
void udapt_playerArray(int count)
{
    FILE* fp;
    if((fp=fopen("ѧ������.txt","r"))==NULL)
    {
        printf("��ѧ������.txtʧ��","r");
        exit(1);
    }
    player_number=fread(all_players,SIZE_OF_PLAYER,count,fp);
    fclose(fp);
    return 0;
}

void join_project(void)//ѧ�������Ĺ���ʵ���Ͼ��ǰ���Ϣ����ļ��Ĺ���
{
    FILE *fp;
    char c;
    player_record* player;
    printf("����������ѧ�����ỹ���Լ����룺1.�������\t 2.�ֶ�����\n");
    c=getchar();
    fflush(stdin);
    if(c=='1')
    {
        printf("ע����������ԭ�����ļ�Ȼ���Զ���ȡ70���˵��˶�Ա��Ϣ��");
        player_number=0;
        fp=fopen("ѧ������.txt","w+");
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
        fp=fopen("ѧ������.txt","a+");
        player_number=fread(all_players,SIZE_OF_PLAYER,MAX_PEOPLE_NUMBER,fp);//��ȡ���е�ѧ���ĸ�����û�д�İ�
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
    printf("���ǵ�%d������ѧ��!\n",player_number);
    player_record* player=(player_record*)malloc(SIZE_OF_PLAYER);
    printf("������д�˶�Ա��������Ϣ��\n");
    printf("������ѧ�ţ�");
    scanf("%d",&player->playerCode);
    fflush(stdin);
    printf("�������Ա�:1.��   2.Ů    \n ");
    char c=getchar();
    fflush(stdin);
    while(c!='1'&&c!='2')
    {
        printf("�����������������룡\n");
        c=getchar();
        fflush(stdin);
    }
    if(c=='1')
        strcpy(player->gender,"��");
    else
        strcpy(player->gender,"Ů");
    fflush(stdin);
    printf("������������");
    scanf("%s",&player->playerName);
    printf("������ѧԺ��");
    scanf("%s",&player->college);
    printf("������Ϣ������ϣ�");
    fflush(stdin);
    Sleep(1000);
    system("cls");
    printf("�뿴���ڿ��Ա�����Ŀ  (��ע����ֻ�ܲμ��������ı���)\n");
    //udapt_playerArray(MAX_PROJECT_NUMBER);
    show_project();
    printf("�������һ�����(������룬��n���˳�)");
    c=getchar();
    //fflush(stdin);
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[0].projectCode=all_projects[c-'0'].man.projectCode;
    else {player->project_in[0].projectCode=0;player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
    printf("������ڶ������(������룬��n���˳�)");
    c=getchar();
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[1].projectCode=all_projects[c-'0'].man.projectCode;
    else {player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
    printf("��������������(������룬��n���˳�)");
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
    printf("�Զ��������ǵ�%d������ѧ��!\n",player_number);
    player_record* player=(player_record*)malloc(SIZE_OF_PLAYER);
    printf("������д�˶�Ա��������Ϣ��\n");
    printf("������ѧ�ţ�");
   // scanf("%d",&player->playerCode);
   player->playerCode=rand()%1000+2015100000;
    printf("�������Ա�:1.��   2.Ů    \n ");
   char c;
    if(rand()%2)
        c='1';
    else c='2';
    /*while(c!='1'&&c!='2')
    {
        printf("�����������������룡\n");
        c=getchar();
        fflush(stdin);
    }*/
    if(c=='1')
        strcpy(player->gender,"��");
    else
        strcpy(player->gender,"Ů");//set the gender of the player.
        printf("�˶�Ա���Ա�%s",player->gender);
        char* project_gender=&player->gender;
        char* project_college=&player->college;
       // system("pause");
    printf("������������");
    //scanf("%s",&player->playerName);
    srand(time(NULL));
    strncpy(player->playerName,rand_str+rand()%20,5);
    player->playerName[5]='\0';
    printf("%s",player->playerName);
    printf("������ѧԺ��");
   // scanf("%s",&player->college);
   srand(time(NULL));
   strncpy(player->college,rand_str+rand()%20,5);//
    player->college[5]='\0';//randomly set the name and college of player.
    printf("%s",player->college);
  //  system("pause");
    printf("������Ϣ������ϣ�");
   // fflush(stdin);
    //Sleep(1000);
    //system("cls");
   // printf("�뿴���ڿ��Ա�����Ŀ  (��ע����ֻ�ܲμ��������ı���)\n");
    //udapt_playerArray(MAX_PROJECT_NUMBER);
    show_project();
    printf("�������һ�����(������룬��n���˳�)");
    srand(time(NULL));
    c=rand()%7+'0'+1;
    putchar(c);
    //fflush(stdin);
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[0].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[0].projectCode=0;player->project_in[1].projectCode=0;player->project_in[2].projectCode=0;return player;}
   // printf("%d\t%d", player->project_in[0].projectCode,all_projects[c-'0'-1].man.projectCode);//ע��������ǵ�����Ŀ����Ϊʲô������
   // system("pause");
    printf("������ڶ������(������룬��n���˳�)");
   // c=getchar();
   c=rand()%7+'0'+1;
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[1].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[1].projectCode=0;player->project_in[1].projectCode=0;return player;}
    printf("��������������(������룬��n���˳�)");
   // c=getchar();
   c=rand()%7+'0'+1;
    fflush(stdin);
    if(c!='n'&&c!='N')
        player->project_in[2].projectCode=all_projects[c-'0'-1].man.projectCode;
    else {player->project_in[2].projectCode=0;}
   // printf("ѧ�ţ�%d�Ա�%s���֣�%s��Ŀһ��%d��Ŀ����%d��Ŀ����%d\n",player->playerCode,player->gender,player->playerName,player->project_in[0].projectCode,player->project_in[1].projectCode,player->project_in[2].projectCode);
   Sleep(100);
    //system("pause");
    return player;


}
void creat_project_file(void)
{
    udapt_playerArray(100);//�ȸ��³����е��˶�Ա���飬��ȷ�����˶�Ա�ĸ���
    udapt_projectArray(7);//�ȸ��³�������Ŀ���飬��ȷ������Ŀ�ĸ���
    FILE* fp;
    int playerCode_in_project[100];
    char* file_name;
    int project_player_number=0;//����ڲ�������������ʾ�����Ŀ�����ж��ٸ��˵ġ�
    for(int i=0;i<project_number;i++)
    {
        project_player_number=0;
        file_name=stringLink("����",all_projects[i].man.projectName);
        strcat(file_name,".txt");
        for(int j=0;j<player_number;j++)
        {
           // printf("%s",all_players[j].gender);//���ִ����ˣ��Ա���������
           // printf("��Ŀ��ţ�%d",all_projects[i].man.projectCode);
           // printf("�˶�Ա�ĵ�һ����Ŀ�ı��%d",all_players[j].project_in[0].projectCode);
           // printf("�˶�Ա�ĵ�һ����Ŀ�ı��%d",all_players[j].project_in[1].projectCode);
           // printf("�˶�Ա�ĵ�һ����Ŀ�ı��%d",all_players[j].project_in[2].projectCode);

        if(strcmp(all_players[j].gender,"��")==0&&(all_players[j].project_in[0].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[1].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[2].projectCode==all_projects[i].man.projectCode))
            {
                project_player_number++;
                playerCode_in_project[project_player_number-1]=all_players[j].playerCode;
            }
        }
        printf("%s��Ŀ��������%d��\n",file_name,project_player_number);
        fp=fopen(file_name,"w");
        free(file_name);
        printf("����ʾ�Ƿ�ɹ��ˣ�%d\n",fwrite(playerCode_in_project,sizeof(int)*100,1,fp));
        fclose(fp);
    }
    memset(playerCode_in_project,0,sizeof(int)*100);
     for(int i=0;i<project_number;i++)
    {
        project_player_number=0;
        file_name=stringLink("Ů��",all_projects[i].man.projectName);
        strcat(file_name,".txt");
        for(int j=0;j<player_number;j++)
        if(strcmp(all_players[j].gender,"Ů")==0&&(all_players[j].project_in[0].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[1].projectCode==all_projects[i].man.projectCode||all_players[j].project_in[2].projectCode==all_projects[i].man.projectCode))
            {
                project_player_number++;
                playerCode_in_project[project_player_number-1]=all_players[j].playerCode;
            }
        printf("%s��Ŀ��������%d\n",file_name,project_player_number);
        fp=fopen(file_name,"w");
        free(file_name);
        printf("����ʾ�Ƿ�ɹ��ˣ�%d\n",fwrite(playerCode_in_project,sizeof(int)*100,1,fp));
        fclose(fp);
    }
}

