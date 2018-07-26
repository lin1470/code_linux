// gameSystem.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int  playerCode;
	char playerName[10];
	char gender[2];
	char college[20];
	char projectName1[20];
	int  projectCode1;
	char projectName2[20];
	int  projectCode2;
	char projectName3[20];
	int  projectCode3;
} playerSignUp;
typedef struct
{
	int projectCode;
	char projectName[20];
	char projectPlace[20];
	int placeCode;
	int numberOfPlayerPerGroup;
	int timeOfGroupTake;
	int heighestRecord;
	char unitOfMeasurement[4];
	int isGroupProject;
} project;
//字符串拼接函数
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
//管理员添加运动项目时调用
void addProject()
{
	FILE *fp;
	FILE *fileFound;
	project pr;
	int projectNumberFound;
	scanf("%d",&projectNumberFound);
	if((fp=fopen("比赛项目表.text","a"))==NULL)
	{
		printf("打开错误！");
	}
	else
	{
		for(int i = 0; i < projectNumberFound;i++)
		{
			printf("输入项目名称：");
			scanf("%s",&pr.projectName);
			printf("输入项目编号：");
			scanf("%d",&pr.projectCode);
			printf("输入项目场地：");
			scanf("%s",&pr.projectPlace);
			printf("输入场地编号：");
			scanf("%d",&pr.placeCode);
			printf("输入每组人数：");
			scanf("%d",&pr.numberOfPlayerPerGroup);
			printf("输入每组时间：");
			scanf("%d",&pr.timeOfGroupTake);
			printf("输入最高纪录：");
			scanf("%d",&pr.heighestRecord);
			printf("输入计量单位：");
			scanf("%s",&pr.unitOfMeasurement);
		}
	}
	fclose(fp);
}
//运动员报名调用
void playerJoin()
{
	FILE *fp;
	playerSignUp player;
	int numberOfJoin;
	if((fp=fopen("运动员报名表.txt","a"))==NULL)
	{
		printf("打开错误！");
	}
	else
	{
		printf("请输入你的名字：");
		scanf("%s",&player.playerName);
		printf("请输入你的性别：");
		scanf("%s",&player.gender);
		printf("请输入你的学院：");
		scanf("%s",&player.college);
		printf("请输入想要参加的项目个数(不多于3个)：");
		scanf("%d",&numberOfJoin);
		for(int i=0;i<numberOfJoin;i++)
		{
			switch(i)
			{
				case 0:
					printf("请输入项目名称：");
					scanf("%s",&player.projectName1);
					printf("请输入项目编号：");
					scanf("%d",&player.projectCode1);
					break;
				case 1:
					printf("请输入项目名称：");
					scanf("%s",&player.projectName2);
					printf("请输入项目编号：");
					scanf("%d",&player.projectCode2);
					break;
				case 2:
					printf("请输入项目名称：");
					scanf("%s",&player.projectName3);
					printf("请输入项目编号：");
					scanf("%d",&player.projectCode3);
					break;
				default:break;
			}
		}
		fwrite(&player,sizeof(playerSignUp),1,fp);
	}
	fclose(fp);
}
//生成各个项目的运动员名单表
void createPlayerOfProject()
{
	char *fileName;
	FILE *fpOfPro;
	FILE *fpOfPlayer;
	FILE *tempFile;
	int proCode;
	project pro;
	playerSignUp player;
	fpOfPro=fopen("比赛项目表.txt","r");
	fpOfPlayer=fopen("运动员报名表.txt","r");
	while(fread(&pro,sizeof(project),1,fpOfPro)!=EOF)
	{
		proCode=pro.projectCode;
		fileName=stringLink(pro.projectName,"名单表.txt");
		while(fread(&player,sizeof(playerSignUp),1,fpOfPlayer)!=EOF)
		{
			if(player.projectCode1 == proCode || player.projectCode2 == proCode ||player.projectCode3 == proCode)
			{
				tempFile=fopen(fileName,"");
			}
		}

	}
	fclose(fpOfPro);
	fclose(fpOfPlayer);
}
int main()
{

	playerJoin();
	return 0;
}

