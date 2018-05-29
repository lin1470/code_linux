#include"SportMeeting.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#define account "123"
#define password "123"
#define PROJECTMAX 10
#define PLAYERMAX 100
void bound(char ch,int n)
{
    printf("\t\t\t\t");
	while (n--)
		putchar(ch);
	printf("\n");
}
char* string_link(char *str1, char *str2)
{
    char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1);//动态分配空间的事情，注意了这个是需要再后面来
    //手动释放的
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

int printf_pro_data()
{
    FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("比赛项目表.txt", "r");
	printf("序号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\n");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		printf("%d\t%8s\t%8d\t%8s\t",count+1,pro.name,pro.placeCode,pro.place);
		printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
	return count;
}

int printf_playerList_data(char *fileName)
{
    FILE *fp;
	player player1;
	int count = 0;
	int i;
	fp = fopen(fileName, "r");
	printf("编号\t名字\t性别\t学院\t参加项目\n");
	while ((i=fread(&player1, sizeof(player), 1, fp),i!=NULL))
	{
		printf("%d\t%s\t%s\t%s\t1.%s\t2.%s\t3.%s\t\n",player1.playerCode,player1.playerName,player1.gender,player1.college,player1.pro[0].name,player1.pro[1].name,player1.pro[2].name);
		count++;
	}
	return count;
}

int did_delete_or_modify()
{
	int choice;
	printf("是否修改、删除YES(1)/NO(0): ");
	scanf("%d", &choice);
	fflush(stdin);
	return choice;
}

void delete_project()
{
	FILE *fp;
	project pro, proArr[PROJECTMAX];
	int modifyCode;
	int proCount = 0;
	printf_pro_data();
	fp = fopen("比赛项目表.txt", "r");
	while (fread(&pro,sizeof(project),1,fp)!=NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("请选择删除信息的序号：");
	scanf("%d", &modifyCode);
	if (did_delete_or_modify())
	{
		for (int i = modifyCode; i < proCount; i++)
		{
			if (i < proCount - 1)
			{
				proArr[i] = proArr[i + 1];
			}
		}
	}
	fp = fopen("比赛项目表.txt", "w");
	fwrite(proArr, sizeof(project), proCount - 1, fp);
	fclose(fp);
}

void add_project()
{
	FILE *fp;
	project pro;
	int choice = 1;
	char c;
	printf("你是要重新输入所有的项目还是想要添加项目：\n1.重新输入\t2.添加项目\n请输入：");
    while((c=getchar(),fflush(stdin),c!='1'&&c!='2'))
    {
        printf("输入不正确，请重新输入:");
    }
    if(c=='1')
        fp=fopen("比赛项目表.txt","w");
    else fp=fopen("比赛项目表.txt","a");

		do
		{
		    Sleep(1000);
		    system("cls");
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
			printf("是否需要再次输入一个项目YES(1)/NO(0)");
			scanf("%d", &choice);
			fflush(stdin);
		} while (choice ==1);
	fclose(fp);
}

void modify_project()
{
		FILE *fp;
		project pro, proArr[PROJECTMAX];
		int proCount = 0;
		int modifyProCode;
		int modifyCode;
		char modifyStrData[20];
		int modifyIntData;
		printf_pro_data();
		fp = fopen("比赛项目表.txt", "r");
		while (fread(&pro, sizeof(project), 1, fp) != NULL)
		{
			proArr[proCount] = pro;
			proCount++;
		}
		fclose(fp);
		printf("请输入要修改的项目的编号:");
		scanf("%d", &modifyProCode);
		printf("请选择要修改的选项：\n1. 项目名称\n2. 场地名称\n3. 计量单位\n4. 每组人数\n5. 每组时间\n");
		scanf("%d", &modifyCode);
		printf("请输入改后数据：");
		if (modifyCode <= 3)
		{
			scanf("%s", &modifyStrData);
		}
		else
		{
			scanf("%d", &modifyIntData);
		}
		switch (modifyCode)
		{
		case 1:
			if (did_delete_or_modify())
			{
				strcpy(proArr[modifyProCode - 1].name, modifyStrData);
			}
			break;
		case 2:
			if (did_delete_or_modify())
			{
				strcpy(proArr[modifyProCode - 1].place, modifyStrData);
			}
			break;
		case 3:
			if (did_delete_or_modify())
			{
				strcpy(proArr[modifyProCode - 1].unitOfMeasureMent, modifyStrData);
			}
			break;
		case 4:
			if (did_delete_or_modify())
			{
				proArr[modifyProCode - 1].numberOfPlayerPerGroup = modifyIntData;
			}
			break;
		case 5:
			if (did_delete_or_modify())
			{
				proArr[modifyProCode - 1].timeOfGroup = modifyIntData;
			}
			break;
		default:
			break;
		}
		fp = fopen("比赛项目表.txt", "w");
		fwrite(proArr, sizeof(project), proCount, fp);
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
	printf_pro_data();
	if ((fp = fopen("运动员报名表.txt", "a")) == NULL)
	{
		printf("打开错误！");
	}
	else
	{
		playerCode = count_playerCode();
		printf("你是第%d个报名的运动员\n",playerCode);
		player1.playerCode = playerCode;
		printf("请输入你的名字：");
		scanf("%s", &player1.playerName);
		printf("请输入你的学院：");
		scanf("%s", &player1.college);
		printf("请输入你的性别：\n1.男\t2.女\n");
		int c=0;
		while((scanf("%d",&c),fflush(stdin),c!=1&&c!=2))
            printf("输入错误 请重新输入：");
		if(c==1)
            strcpy(player1.gender,"男");
        else strcpy(player1.gender,"女");
		printf("请输入想要参加的项目个数(不多于3个)：");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "无");
			//strcpy(player1.pro[i].code)
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
		int playerNum=0;
		fileName = string_link(pro.name, "名单表.txt");//把这些项目表和运动员连接起来的。
		tempFile = fopen(fileName, "w");
		fpOfPlayer = fopen("运动员报名表.txt", "r");//遍历一遍这个运动员的，然后如何存在的话就把他们加进来。
		while (fread(&player1, sizeof(player), 1, fpOfPlayer) != NULL)
		{
			if (player1.pro[0].code == proCode || player1.pro[1].code == proCode || player1.pro[2].code == proCode)
			{
				//printf("%d", player1.playerCode);
				fwrite(&player1, sizeof(player), 1, tempFile);
				playerNum++;
			}
		}
		printf("参加%s项目的有：%d个人\n",pro.name,playerNum);
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
		fileName = string_link(pro.name, "名单表.txt");
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

void enter_result()
{
	FILE *fp;
	project pro[PROJECTMAX];
	int count;
	int choice;
	int score;
	char *file_name;
	player playerArr[PLAYERMAX];
	count = printf_pro_data();
	printf("请输入要录入结果的项目编号：");
	fp = fopen("比赛项目表.txt","r");
	fread(pro, sizeof(project), count, fp);
	fclose(fp);
	scanf("%d", &  choice);
	file_name = string_link(pro[choice - 1].name, "名单表.txt");
	count = printf_playerList_data(file_name);
	fp = fopen(file_name, "r");
	fread(playerArr, sizeof(player), count, fp);
	fclose(fp);
	printf("请依次输入运动员的成绩:");
	for (int i = 0; i < count; i++)
	{
		printf("第%d运动员的成绩:", i);
		scanf("%d\n",&score);
		for (int j = 0; j < 3; j++)
		{
			if (playerArr[i].pro[j].code==pro[i].code)
			{
				playerArr[i].pro[i].score = score;
			}
		}
	}
	file_name = string_link(pro[choice - 1].name, "成绩表");
	fwrite(playerArr, sizeof(player), count, fp);
	fp = fopen(file_name,"a");
	fclose(fp);
}

void query_score()
{
	int player_code;
	player p,q;
	FILE *fp;
	char *fileName;
	printf("请输入你的编号：");
	scanf("%d", &player_code);
	fp = fopen("运动员报名表.txt", "r");
	while (!fread(&p, sizeof(player), 1, fp))
	{
		if (p.playerCode == player_code)
		{
			q = p;
		}
	}
	fclose(fp);
	for (int i = 0; i < 3; i++)
	{
		if (q.pro[i].name != "无")
		{
			fileName = string_link(q.pro[i].name, "成绩表.txt");
			fp = fopen(fileName,"r");
			while (!fread(&p,sizeof(player),1,fp))
			{
				if (p.playerCode == player_code)
				{
					printf("%s\t\t%d\n", p.pro[i].name, p.pro[i].score);
				}
			}
			fclose(fp);
		}
	}
}

void query_dirtribution()
{
	FILE *fp;
	distribution distri;
	int choice;
	if (fp = fopen("项目时间分配表.txt", "r"))
	{
		printf("项目编号\t项目名称\t时间段号\n");
		while ((fread(&distri, sizeof(distribution), 1, fp)!=NULL))
		{
			printf("%8d\t%8s\t%8d\n", distri.projectCode,distri.projectName,distri.timeCode);
		}
	}
	printf("按1退出：");
	scanf("%d", &choice);
}

void main_menu()
{
	int choice;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\t\t\t\t\t1.项目发布\n");
		printf("\t\t\t\t\t2.项目修改\n");
		printf("\t\t\t\t\t3.项目删除\n");
		printf("\t\t\t\t\t4.结果录入\n");
		printf("\t\t\t\t\t5.秩序生成\n");
		printf("\t\t\t\t\t6.返回上级\n");
		bound('=', 30);
		printf("请输入选项：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add_project();
			break;
		case 2:
			modify_project();
			break;
		case 3:
			delete_project();
			break;
		case 4:
			enter_result();
			break;
		case 5:
			create_player_of_project();
			create_conflict_of_project();
			create_time_of_distribution();
			query_dirtribution();
			break;
		case 6:
			system("cls");
			main_surface();
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
	printf("账号:");
	scanf("%s",real_account);
	printf("密码:");
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
		system("cls");
		printf("\t\t\t\t\t运动会管理系统\n");
		bound('=',30);
		printf("\t\t\t\t\t1.管理员登录\n\t\t\t\t\t2.运动员报名\n\t\t\t\t\t3.成绩查询\n\t\t\t\t\t4.信息查询\n\t\t\t\t\t5.退出系统\n");
		bound('=', 30);
		printf("输入您的选择:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			while (check_account()==0);
			main_menu();
			break;
		case 2:
			player_join();
			break;
		case 3:
			query_score();
			break;
		case 4:
			break;
		case 5:
			exit(0);
			break;
		}
	} while (1);
}
