// gameSystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PROJECTMAX				10
#define PLAYERMAX					100
int playerCode = 1;
typedef struct
{
	int	 playerCode;
	char	 playerName[10];
	char  gender[4];
	char  college[20];
	char  projectName1[20];
	int    projectCode1;
	char projectName2[20];
	int    projectCode2;
	char projectName3[20];
	int   projectCode3;
} playerSignUp;
typedef struct
{
	int	 projectCode;
	char  projectName[20];
	char  projectPlace[20];
	int	 placeCode;
	int    numberOfPlayerPerGroup;
	int    timeOfGroupTake;
	int    heighestRecord;
	char  unitOfMeasurement[4];
	int    isGroupProject;
} project;
typedef struct
{
	int		projectCode;
	char		projectName[20];
	int		countOfPlayer;
	int		 estimatedTime;
} time;
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
//用于生成运动员的编号
void countPlayerCode()
{
	FILE *fp;
	playerSignUp player;
	fp=fopen("运动员报名表.txt","r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		playerCode++;
	}
	printf("%d",playerCode);
}
//管理员添加运动项目时调用
void addProject()
{
	FILE *fp;
	FILE *fileFound;
	project pro;
	int projectNumberFound;
	printf("请输入项目个数：");
	scanf("%d",&projectNumberFound);
	if((fp=fopen("比赛项目表.txt","a"))==NULL)
	{
		printf("打开错误！");
	}
	else
	{
		for(int i = 0; i < projectNumberFound;i++)
		{
			printf("请输入项目名称：");
			scanf("%s",&pro.projectName);
			printf("请输入项目编号：");
			scanf("%d",&pro.projectCode);
			printf("请输入项目场地：");
			scanf("%s",&pro.projectPlace);
			printf("请输入场地编号：");
			scanf("%d",&pro.placeCode);
			printf("请输入计量单位：");
			scanf("%s",&pro.unitOfMeasurement);
			printf("请输入每组人数：");
			scanf("%d",&pro.numberOfPlayerPerGroup);	
			printf("请输入每组时间：");
			scanf("%d",&pro.timeOfGroupTake);
			printf("请输入最高纪录：");
			scanf("%d",&pro.heighestRecord);	
			fwrite(&pro,sizeof(project),1,fp);
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
		countPlayerCode();
		player.playerCode = playerCode;
		printf("请输入你的名字：");
		scanf("%s",&player.playerName);
		printf("请输入你的学院：");
		scanf("%s",&player.college);
		printf("请输入你的性别：");
		scanf("%s",&player.gender);
		printf("请输入想要参加的项目个数(不多于3个)：");
		scanf("%d",&numberOfJoin);
		 strcpy(player.projectName1,"无");
		 strcpy(player.projectName2,"无");
		 strcpy(player.projectName3,"无");
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
			}		
		}
		fwrite(&player,sizeof(playerSignUp),1,fp);
	}
	fclose(fp);	
}
//生成项目运动员名单表
void createPlayerOfProject()
{
	char *fileName;		//创建临时的文件名
	FILE *fpOfPro;			//指向比赛项目表的文件指针变量
	FILE *fpOfPlayer;		//指向运动员报名表的文件指针变量
	FILE *tempFile;		//临时文件指针变量
	int proCode;			//项目编号
	project pro;
	playerSignUp player;
	fpOfPro=fopen("比赛项目表.txt","r");
	
	while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL)
	{                                                     
		proCode=pro.projectCode;
		fileName=stringLink(pro.projectName,"名单表.txt");
		tempFile=fopen(fileName,"w");
		fpOfPlayer=fopen("运动员报名表.txt","r");
		while(fread(&player,sizeof(playerSignUp),1,fpOfPlayer)!=NULL)
		{
			if(player.projectCode1 == proCode || player.projectCode2 == proCode || player.projectCode3 == proCode)
			{	
				printf("%d",player.playerCode);
				fwrite(&player,sizeof(playerSignUp),1,tempFile);	
			}
		}	
		fclose(tempFile);
		fclose(fpOfPlayer);
	}
	fclose(fpOfPro);
	
}
//生成项目时间估算表
void createTimeOfEstimation()
{
	char *fileName;			//临时文件名
	FILE *fpOfPro;			//指向“比赛项目表”的指针变量
	FILE *fpOfPlayerList;	//指向“项目运动员名单表”的指针变量
	FILE *fpOfTemp;			//临时文件指针变量
	project pro;
	playerSignUp player;
	time ti;
	int baseTime =0;			//每组花费时间，即基本单位时间
	int count;
	fpOfPro = fopen("比赛项目表.txt","r");
	fpOfTemp =fopen("项目时间估算表.txt","w");
	while(fread(&pro,sizeof(project),1,fpOfPro) != NULL)
	{
		fileName=stringLink(pro.projectName,"名单表.txt");
		fpOfPlayerList = fopen(fileName,"r");
		ti.projectCode = pro.projectCode;
		//ti.projectName[20] = pro.projectName;
		strcpy(ti.projectName,pro.projectName);
		ti.countOfPlayer=0;
		count=pro.numberOfPlayerPerGroup;
		baseTime = pro.timeOfGroupTake;
		while(fread(&player,sizeof(playerSignUp),1,fpOfPlayerList) != NULL)
		{
			ti.countOfPlayer ++;
		}
		float tempVar =(float)ti.countOfPlayer/count;
		ti.estimatedTime = ceil(tempVar) *baseTime;
		printf("%s %d\n",ti.projectName,ti.estimatedTime);
		fwrite(&ti,sizeof(time),1,fpOfTemp);	
		fclose(fpOfPlayerList);
	}
	fclose(fpOfTemp);
}
//生成项目冲突表
void createConflictOfProject()
{
	char *fileName,*fileName1,*fileName2;
	FILE *fpOfPro;													//指向“比赛项目表”的指针变量
	FILE *fpOfPlayerListA,*fpOfPlayerListB;			//指向“项目运动员名单表”的指针变量
	FILE *fpOfTemp;												//创建冲突表使用的指针变量
	int countOfPro = 0;
	project proArr[PROJECTMAX],pro;					//proArr用于存储所有的项目
	/*
	playerArrA以及playerArrB用于存储项目运动员名单表的数据
	用于对A和B两个项目作是否含有同一个运动员的比较
	*/
	playerSignUp player,playerArrA[PLAYERMAX],playerArrB[PLAYERMAX];
	conflict con;
	fpOfPro=fopen("比赛项目表.txt","r");
	while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL)
	{
		proArr[countOfPro]=pro;		
		countOfPro++;
	}
	fclose(fpOfPro);
	for(int i=0;i<countOfPro;i++)
	{
		fileName = stringLink(proArr[i].projectName,"冲突表.txt");
		fileName1 = stringLink(proArr[i].projectName,"名单表.txt");
		fpOfTemp=fopen(fileName,"w");
		printf("%s\n",proArr[i].projectName);
		fpOfPlayerListA = fopen(fileName1,"r");
		int countOfPlayerA = 0;
		//将要被比较的运动员名单数据存储到A区
		while(fread(&player,sizeof(playerSignUp),1,fpOfPlayerListA)!=NULL)
		{
			playerArrA[countOfPlayerA]=player;
			countOfPlayerA++;
		}
		fclose(fpOfPlayerListA);
		for(int j=0; j<countOfPro; j++)
		{
			
			if(i!=j)
			{	
				con.projectCode=proArr[j].projectCode;
				strcpy(con.projectName,proArr[j].projectName);
				int countOfPlayerB=0;
				fileName2 = stringLink(proArr[j].projectName,"名单表.txt");
				fpOfPlayerListB=fopen(fileName2,"r");
				//将要比较的运动员名单数据存储到B区
				while(fread(&player,sizeof(playerSignUp),1,fpOfPlayerListB)!=NULL)
				{
					playerArrB[countOfPlayerB]=player;
					countOfPlayerB++;
				}
				fclose(fpOfPlayerListB);
				if(proArr[i].placeCode == proArr[j].placeCode)
				{
					con.isConflict = 1;
				}
				else
				{
					//printf("%d  %d\n",countOfPlayerA,countOfPlayerB);
					/*如果运动项目的场地相同，或者不同的项目的名单表中含有相同的运动员
					则说明这两个项目时冲突的*/
					if(countOfPlayerA>0&&countOfPlayerB>0)
					{
						for(int ii = 0;ii<countOfPlayerA;ii++)
						{
							for(int jj = 0;jj<countOfPlayerB;jj++)
							{
								printf("%d=?=%d\n",playerArrA[ii].playerCode,playerArrB[jj].playerCode);
								if(playerArrA[ii].playerCode==playerArrB[jj].playerCode)
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
				
				printf("%d\t%s\t%d\n",con.projectCode,con.projectName,con.isConflict);
				fwrite(&con,sizeof(conflict),1,fpOfTemp);
			}		
		}
		fclose(fpOfTemp);		
	}
}
//生成时间分配表
void createTimeOfDistribution()
{
		FILE *fpOfTemp;											//打开或者创建项目时间分配表的指针变量
		FILE *fpOfPro;												//指向比赛项目表的指针变量
		FILE *fpOfCon;												//指向冲突表的指针变量
		char *fileName;												//打开各个项目的冲突表的临时指针变量
		int	 countOfPro = 0;									//项目总数
		int	timeOfSegment = 0;								//时间段号数
		int	 count=0;
		int    weipai = 0;											//未排时间段号的项目个数
		project pro,proArr[PROJECTMAX];					//存储项目表数据的数组
		conflict con,conArr[PROJECTMAX];				//存储冲突表数据的数组
		distribution distriArr[PROJECTMAX];				//存储时间分配表数据的数组
		fpOfPro = fopen("比赛项目表.txt","r");
		//初始化时间分配表
		while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL )
		{	
			proArr[countOfPro] = pro;
			countOfPro ++;
			weipai++;
		}
		fclose(fpOfPro);
		//初始化时间表和项目冲突比对表的数据
		for(int i =0;i<countOfPro;i++)
		{
			distriArr[i].projectCode = proArr[i].projectCode;
			strcpy(distriArr[i].projectName,proArr[i].projectName);
			distriArr[i].timeCode = 0;
			conArr[i].projectCode = proArr[i].projectCode;
			strcpy(conArr[i].projectName,proArr[i].projectName);
			conArr[i].isConflict=0;
		}
		fpOfTemp = fopen("项目时间分配表.txt","w");
		//但未排项目个数大于0时
		while(weipai>0)
		{
			if(distriArr[count].timeCode==0)//如果项目的时间段号为0，即项目的时间段号还没有分配
			{
				timeOfSegment++;
				distriArr[count].timeCode=timeOfSegment;
				weipai --;
				while(count<countOfPro)
				{
					here:fileName=stringLink(distriArr[count].projectName,"冲突表.txt");
					printf("%s\n",fileName);
					fpOfCon =fopen(fileName,"r");
					//更新冲突比对表
					while(fread(&con,sizeof(conflict),1,fpOfCon)!=NULL)
					{
						for(int i= 0;i<countOfPro;i++)
						{
							if(conArr[i].projectCode == con.projectCode)
								conArr[i].isConflict = conArr[i].isConflict || con.isConflict;
						}
					}
					fclose(fpOfCon);	
					//for(int i =0;i<countOfPro;i++)
						//printf("\n%d\t%s\t%d\n",conArr[i].projectCode,conArr[i].projectName,conArr[i].isConflict);
					count++;
					for(int i = count; i < countOfPro; i++)
					{
						printf("\n%d=?=%d\n",distriArr[count].projectCode,conArr[i].projectCode);
						if(distriArr[count].projectCode==conArr[i].projectCode && conArr[i].isConflict !=1 && distriArr[count].timeCode == 0)
						{
							distriArr[count].timeCode=timeOfSegment;
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
			if(count>=countOfPro)
				count =0;
		}
		fwrite(distriArr,sizeof(distribution),countOfPro,fpOfTemp);
		fclose(fpOfTemp);
}
//查询运动员报名表的内容
void queryPlayer()
{ 
	playerSignUp player;
	FILE *fp;
	fp = fopen("运动员报名表.txt","r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		printf("%s\t%s\t%d\t%s\t%s\t%s\t%s\n",player.college,player.gender,player.playerCode,player.playerName,player.projectName1,player.projectName2,player.projectName3);
	}
	fclose(fp);
}
//查询项目表的内容
int queryProject()
{
	project pro,proArr[PROJECTMAX];
	int proCount = 0;
	FILE *fp;
	fp = fopen("比赛项目表.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("序号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\t最高纪录\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	return proCount;
}
//查询项目运动员名单表的内容
void queryPlayerList(char *projectName)
{
	FILE *fp;
	char *fileName;
	playerSignUp player;
	fileName=stringLink(projectName,"名单表.txt");
	fp = fopen(fileName,"r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		printf("%d  %s  %s  %s\n",player.playerCode,player.playerName,player.college,player.gender);
	}
	fclose(fp);
}
//查询项目时间估算表的内容
void queryTime()
{
	FILE *fp;
	time ti;
	fp = fopen("项目时间估算表.txt","r");
	while(fread(&ti,sizeof(time),1,fp)!=NULL)
	{
		printf("%s\t",ti.projectName);
		printf("%d\t%d\t%d\n",ti.projectCode,ti.countOfPlayer,ti.estimatedTime);
	}
	fclose(fp);
}
//查询项目冲突表的内容
void queryConflict(char *projectName)
{
	FILE *fp;
	char *fileName;
	conflict con;
	fileName=stringLink(projectName,"冲突表.txt");
	fp =fopen(fileName,"r");
	while(fread(&con,sizeof(conflict),1,fp)!=NULL)
	{
		printf("%d\t%s\t%d\n",con.projectCode,con.projectName,con.isConflict);
	}
	fclose(fp);
}
//查询项目时间分配表的内容
void queryDistribution()
{
	distribution distri;
	FILE *fp;
	fp=fopen("项目时间分配表.txt","r");
	while(fread(&distri,sizeof(distribution),1,fp)!=NULL)
	{
		printf("\n%d,%s,%d\n",distri.projectCode,distri.projectName,distri.timeCode);
	}
	fclose(fp);
}
//判断是否修改和删除
int didDeleteOrModify()
{
	int choice;
	printf("确认修改、删除 YES(1)/NO(0):");
	scanf("%d", &choice);
	return choice;

}
//修改比赛项目表的内容
void modifyProject()
{
	FILE *fp;
	project pro,proArr[PROJECTMAX];
	int proCount = 0;
	int modifyProCode;
	int modifyCode;
	char *modifyStrData;
	int modifyIntData;
	fp = fopen("比赛项目表.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("序号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\t最高纪录\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	printf("请输入要修改的项目的编号");
	scanf("%d", &modifyProCode);
	printf("请选择要修改的选项：\n1. 项目名称\n2. 场地名称\n3. 计量单位\n4. 每组人数\n5. 每组时间\n 6. 最高纪录\n");
	scanf("%d",&modifyCode);
	printf("请输入改后数据：");
	if (modifyCode>3)
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
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectName, modifyStrData);
			}			
			break;
		case 2:
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectPlace, modifyStrData);
			}		
			break;
		case 3:
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectPlace, modifyStrData);
			}
			strcpy(proArr[modifyProCode].unitOfMeasurement, modifyStrData);
			break;
		case 4:
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectPlace, modifyStrData);
			}
			proArr[modifyProCode].numberOfPlayerPerGroup = modifyIntData;
			break;
		case 5:
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectPlace, modifyStrData);
			}
			proArr[modifyProCode].timeOfGroupTake = modifyIntData;
			break;
		case 6:
			if (didDeleteOrModify())
			{
				strcpy(proArr[modifyProCode].projectPlace, modifyStrData);
			}
			proArr[modifyProCode].heighestRecord = modifyIntData;
			break;
	default:
		break;
	}
	fp = fopen("比赛项目表.txt", "w");
	fwrite(proArr, sizeof(project), proCount, fp);
	fclose(fp);

}
//删除比赛项目表的某个内容；
void deleteProject()
{
	FILE *fp;
	project  pro, proArr[PROJECTMAX];
	int modifyCode;
	int proCount = 0;
	fp = fopen("比赛项目表.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("序号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\t最高纪录\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	printf("请输入要删除信息的序号");
	scanf("%d", &modifyCode);
	if (didDeleteOrModify())
	{
		for (int i = modifyCode; i < proCount; i++)
		{
			if (i < proCount - 1)
			{
				proArr[i] = proArr[i + 1];
			}
		}
		fp = fopen("比赛项目表.txt", "w");
		fwrite(proArr, sizeof(project), proCount - 1, fp);
		fclose(fp);
	}
}
void queryPersonInfo()
{
	FILE *fp;
	int playerCode;
	int playerCount = 0;
	playerSignUp player, playerArr[PLAYERMAX];
	printf("请输入你的运动员编号");
	scanf("%d", playerCode);
	if (fp = fopen("运动员报名表.txt","r"))
	{
		while (fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
		{
			playerArr[playerCount] = player;
			playerCount++;
		}
	}
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i].playerCode ==playerCode)
		{
			printf("%s\t%s\t%s\t%s\t%s\t%s\n",playerArr[i].playerName,playerArr[i].gender,playerArr[i].college,playerArr[i].projectName1,playerArr[i].projectName2,playerArr[i].projectName3);
		}
	}
}
int main()
{
	int choice = 0;
	int count;
	//addProject();
	//queryProject();
/*	
	scanf("%d",&count);
	for(int i =0;i<count;i++)
	{
		playerJoin();
	}
*/
	//queryPlayer();
	// createPlayerOfProject();
	//queryPlayerList("男子100米");
	//createTimeOfEstimation();
	//queryTime();
	//createConflictOfProject();
	//queryConflict("男子100米");
	//createTimeOfDistribution();
	//createTimeOfDistribution();
	//queryDistribution();
	//countPlayerCode();
	deleteProject();
	scanf("%d",choice);
	
	return 0;
}

