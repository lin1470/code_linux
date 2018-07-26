// game.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#define account "123"
#define password "123"
#define PROJECTMAX				10
#define PLAYERMAX					100
typedef struct 
{
	char name[20];
	int code;
	float score;
}project_player;
typedef struct
{
	int	 playerCode;
	char	 playerName[10];
	char  gender[4];
	char  college[20];
	project_player pro[3];
}player;
typedef struct
{
	int code;
	char name[20];
	int placeCode;
	char place[20];
	int numberOfPlayerPerGroup;
	int timeOfGroup;
	char unitOfMeasureMent[4];
}project;
typedef struct
{
	int		projectCode;
	char		projectName[20];
	int		countOfPlayer;
	int		 estimatedTime;
} time_take;
typedef struct
{
	int  projectCode;
	char projectName[20];
	int  isConflict;
} conflict;
typedef struct
{
	int projectCode;
	char projectName[20];
	int timeCode;
} distribution;
//字符串拼接函数
char* string_link(char *str1, char *str2)
{
	char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1);
	if (result == NULL)
	{
		printf("内存申请错误!");
	}
	else
	{
		strcpy(result, str1);
		strcat(result, str2);
	}
	return result;
}
void bound(char ch, int n)
{
	while (n--)
		putchar(ch);
	printf("\n");
	return;
}
void add_project()
{
	FILE *fp;
	project pro;
	int projectNumberFound;
	int choice = 1;
	printf("请输入项目个数：");
	scanf("%d", &projectNumberFound);
	if ((fp = fopen("比赛项目表.txt", "a")) == NULL)
	{
		printf("打开错误！");
	}
	else
	{
		do
		{
			printf("请输入项目名称：");
			scanf("%s", &pro.name);
			printf("请输入项目编号：");
			scanf("%d", &pro.code);
			printf("请输入项目场地：");
			scanf("%s", &pro.place);
			printf("请输入场地编号：");
			scanf("%d", &pro.placeCode);
			printf("请输入计量单位：");
			scanf("%s", &pro.unitOfMeasureMent);
			printf("请输入每组人数：");
			scanf("%d", &pro.numberOfPlayerPerGroup);
			printf("请输入每组时间：");
			scanf("%d", &pro.timeOfGroup);
			fwrite(&pro, sizeof(project), 1, fp);
			scanf("%d", &choice);
		} while (choice ==1);
	}
	fclose(fp);
}
int  count_playerCode()
{
	int playerCode = 1;
	FILE *fp;
	player player1;
	fp = fopen("运动员报名表.txt", "r");
	while (fread(&player1, sizeof(player), 1, fp) != NULL)
	{
		playerCode++;
	}
	return playerCode;
}
void player_join()
{
	FILE *fp;
	player player1;
	int numberOfJoin;
	int playerCode;
	if ((fp = fopen("运动员报名表.txt", "a")) == NULL)
	{
		printf("打开错误！");
	}
	else
	{
		playerCode = count_playerCode();
		player1.playerCode = playerCode;
		printf("请输入你的名字：");
		scanf("%s", &player1.playerName);
		printf("请输入你的学院：");
		scanf("%s", &player1.college);
		printf("请输入你的性别：");
		scanf("%s", &player1.gender);
		printf("请输入想要参加的项目个数(不多于3个)：");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "无");
		}
		for (int i = 0;i < numberOfJoin;i++)
		{
			printf("请输入项目名称：");
			scanf("%s", &player1.pro[i].name);
			printf("请输入项目编号：");
			scanf("%d", &player1.pro[i].code);
		}
		fwrite(&player1, sizeof(player), 1, fp);
	}
	fclose(fp);
}
void create_player_of_project()
{
	char *fileName;		//创建临时的文件名
	FILE *fpOfPro;			//指向比赛项目表的文件指针变量
	FILE *fpOfPlayer;		//指向运动员报名表的文件指针变量
	FILE *tempFile;		//临时文件指针变量
	int proCode;			//项目编号
	project pro;
	player player1;
	fpOfPro = fopen("比赛项目表.txt", "r");

	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proCode = pro.code;
		fileName = string_link(pro.name, "名单表.txt");
		tempFile = fopen(fileName, "w");
		fpOfPlayer = fopen("运动员报名表.txt", "r");
		while (fread(&player1, sizeof(player), 1, fpOfPlayer) != NULL)
		{
			if (player1.pro[0].code == proCode || player1.pro[1].code == proCode || player1.pro[2].score == proCode)
			{
				printf("%d", player1.playerCode);
				fwrite(&player1, sizeof(player), 1, tempFile);
			}
		}
		fclose(tempFile);
		fclose(fpOfPlayer);
	}
	fclose(fpOfPro);

}
void create_time_of_estimation()
{
	char *fileName;			//临时文件名
	FILE *fpOfPro;			//指向“比赛项目表”的指针变量
	FILE *fpOfPlayerList;	//指向“项目运动员名单表”的指针变量
	FILE *fpOfTemp;			//临时文件指针变量
	project pro;
	player player1;
	time_take ti;
	int baseTime = 0;			//每组花费时间，即基本单位时间
	int count;
	fpOfPro = fopen("比赛项目表.txt", "r");
	fpOfTemp = fopen("项目时间估算表.txt", "w");
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		fileName = stringLink(pro.name, "名单表.txt");
		fpOfPlayerList = fopen(fileName, "r");
		ti.projectCode = pro.code;
		//ti.projectName[20] = pro.projectName;
		strcpy(ti.projectName, pro.name);
		ti.countOfPlayer = 0;
		count = pro.numberOfPlayerPerGroup;
		baseTime = pro.timeOfGroup;
		while (fread(&player1, sizeof(player), 1, fpOfPlayerList) != NULL)
		{
			ti.countOfPlayer++;
		}
		float tempVar = (float)ti.countOfPlayer / count;
		ti.estimatedTime = ceil(tempVar) *baseTime;
		printf("%s %d\n", ti.projectName, ti.estimatedTime);
		fwrite(&ti, sizeof(time_take), 1, fpOfTemp);
		fclose(fpOfPlayerList);
	}
	fclose(fpOfTemp);
}
void create_conflict_of_project()
{
	char *fileName, *fileName1, *fileName2;
	FILE *fpOfPro;													//指向“比赛项目表”的指针变量
	FILE *fpOfPlayerListA, *fpOfPlayerListB;			//指向“项目运动员名单表”的指针变量
	FILE *fpOfTemp;												//创建冲突表使用的指针变量
	int countOfPro = 0;
	project proArr[PROJECTMAX], pro;					//proArr用于存储所有的项目
														/*
														playerArrA以及playerArrB用于存储项目运动员名单表的数据
														用于对A和B两个项目作是否含有同一个运动员的比较
														*/
	player player1, playerArrA[PLAYERMAX], playerArrB[PLAYERMAX];
	conflict con;
	fpOfPro = fopen("比赛项目表.txt", "r");
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proArr[countOfPro] = pro;
		countOfPro++;
	}
	fclose(fpOfPro);
	for (int i = 0;i<countOfPro;i++)
	{
		fileName = string_link(proArr[i].name, "冲突表.txt");
		fileName1 = string_link(proArr[i].name, "名单表.txt");
		fpOfTemp = fopen(fileName, "w");
		printf("%s\n", proArr[i].name);
		fpOfPlayerListA = fopen(fileName1, "r");
		int countOfPlayerA = 0;
		//将要被比较的运动员名单数据存储到A区
		while (fread(&player1, sizeof(player), 1, fpOfPlayerListA) != NULL)
		{
			playerArrA[countOfPlayerA] = player1;
			countOfPlayerA++;
		}
		fclose(fpOfPlayerListA);
		for (int j = 0; j<countOfPro; j++)
		{

			if (i != j)
			{
				con.projectCode = proArr[j].code;
				strcpy(con.projectName, proArr[j].name);
				int countOfPlayerB = 0;
				fileName2 = string_link(proArr[j].name, "名单表.txt");
				fpOfPlayerListB = fopen(fileName2, "r");
				//将要比较的运动员名单数据存储到B区
				while (fread(&player1, sizeof(player), 1, fpOfPlayerListB) != NULL)
				{
					playerArrB[countOfPlayerB] = player1;
					countOfPlayerB++;
				}
				fclose(fpOfPlayerListB);
				if (proArr[i].placeCode == proArr[j].placeCode)
				{
					con.isConflict = 1;
				}
				else
				{
					//printf("%d  %d\n",countOfPlayerA,countOfPlayerB);
					/*如果运动项目的场地相同，或者不同的项目的名单表中含有相同的运动员
					则说明这两个项目时冲突的*/
					if (countOfPlayerA>0 && countOfPlayerB>0)
					{
						for (int ii = 0;ii<countOfPlayerA;ii++)
						{
							for (int jj = 0;jj<countOfPlayerB;jj++)
							{
								printf("%d=?=%d\n", playerArrA[ii].playerCode, playerArrB[jj].playerCode);
								if (playerArrA[ii].playerCode == playerArrB[jj].playerCode)
								{
									con.isConflict = 1;
								}
								else
								{
									con.isConflict = 0;
								}
							}
						}
					}
					else
					{
						con.isConflict = 0;
					}
				}

				printf("%d\t%s\t%d\n", con.projectCode, con.projectName, con.isConflict);
				fwrite(&con, sizeof(conflict), 1, fpOfTemp);
			}
		}
		fclose(fpOfTemp);
	}
}
void create_time_of_distribution()
{
	FILE *fpOfTemp;											//打开或者创建项目时间分配表的指针变量
	FILE *fpOfPro;												//指向比赛项目表的指针变量
	FILE *fpOfCon;												//指向冲突表的指针变量
	char *fileName;												//打开各个项目的冲突表的临时指针变量
	int	 countOfPro = 0;									//项目总数
	int	timeOfSegment = 0;								//时间段号数
	int	 count = 0;
	int    weipai = 0;											//未排时间段号的项目个数
	project pro, proArr[PROJECTMAX];					//存储项目表数据的数组
	conflict con, conArr[PROJECTMAX];				//存储冲突表数据的数组
	distribution distriArr[PROJECTMAX];				//存储时间分配表数据的数组
	fpOfPro = fopen("比赛项目表.txt", "r");
	//初始化时间分配表
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proArr[countOfPro] = pro;
		countOfPro++;
		weipai++;
	}
	fclose(fpOfPro);
	//初始化时间表和项目冲突比对表的数据
	for (int i = 0;i<countOfPro;i++)
	{
		distriArr[i].projectCode = proArr[i].code;
		strcpy(distriArr[i].projectName, proArr[i].name);
		distriArr[i].timeCode = 0;
		conArr[i].projectCode = proArr[i].code;
		strcpy(conArr[i].projectName, proArr[i].name);
		conArr[i].isConflict = 0;
	}
	fpOfTemp = fopen("项目时间分配表.txt", "w");
	//但未排项目个数大于0时
	while (weipai>0)
	{
		if (distriArr[count].timeCode == 0)//如果项目的时间段号为0，即项目的时间段号还没有分配
		{
			timeOfSegment++;
			distriArr[count].timeCode = timeOfSegment;
			weipai--;
			while (count<countOfPro)
			{
			here:fileName = string_link(distriArr[count].projectName, "冲突表.txt");
				printf("%s\n", fileName);
				fpOfCon = fopen(fileName, "r");
				//更新冲突比对表
				while (fread(&con, sizeof(conflict), 1, fpOfCon) != NULL)
				{
					for (int i = 0;i<countOfPro;i++)
					{
						if (conArr[i].projectCode == con.projectCode)
							conArr[i].isConflict = conArr[i].isConflict || con.isConflict;
					}
				}
				fclose(fpOfCon);
				//for(int i =0;i<countOfPro;i++)
				//printf("\n%d\t%s\t%d\n",conArr[i].projectCode,conArr[i].projectName,conArr[i].isConflict);
				count++;
				for (int i = count; i < countOfPro; i++)
				{
					printf("\n%d=?=%d\n", distriArr[count].projectCode, conArr[i].projectCode);
					if (distriArr[count].projectCode == conArr[i].projectCode && conArr[i].isConflict != 1 && distriArr[count].timeCode == 0)
					{
						distriArr[count].timeCode = timeOfSegment;
						weipai--;
						goto here;
					}
					//printf("count = %d",count);
					count++;
				}
			}
		}
		else
		{
			count++;
		}
		if (count >= countOfPro)
			count = 0;
	}
	fwrite(distriArr, sizeof(distribution), countOfPro, fpOfTemp);
	fclose(fpOfTemp);
}
void main_menu()
{
	int choice;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\n\t1.运动项目发布\n");
		printf("\t2.运动项目修改\n");
		printf("\t3.比赛结果录入\n");
		printf("\t4.返回上一级\n");
		printf("\t5.退出\n");
		bound('=', 30);
		switch (choice)
		{
		case 1:
			add_project();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	} while (1);
}
int check_account()
{
	char real_account[10];
	char real_password[10];
	int i;
	fflush(stdin);
	printf("account:");
	scanf("%s",real_account);
	printf("password:");
	for (i = 0;i<10 && ((real_password[i] = _getch()) != 13);i++)
		putchar('*');
	putchar('\n');
	real_password[i] = '\0';
	if (strcmp(real_account, account) == 0 && strcmp(real_password, password) == 0)
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
void main_surface()
{
	int choice;
	do
	{
		printf("\t\t\t\t运动会管理系统\n");
		printf("\t\t\t________________________________\n");
		printf("\t\t\t\t1.管理员登录\n\t\t\t\t2.运动员报名\n\t\t\t\t3.成绩查询\n\t\t\t\t4.信息查询\n\t\t\t\t5.退出系统\n");
		printf("\t\t\t________________________________\n");
		printf("输入您的选择:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			while (check_account==0);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		}
	} while (1);
}
int main()
{
	int choice;
	main_surface();
    return 0;
}

