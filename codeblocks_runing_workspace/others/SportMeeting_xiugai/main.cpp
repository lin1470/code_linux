// game.cpp : 定义控制台应用程序的入口点。
//

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#define account "123"
#define password "123"
#define PROJECTMAX	30
#define PLAYERMAX 100
typedef struct
{
	char name[20];
	int code;
	float score;
}project_player;

typedef struct
{
	int	 playerCode;
	char  playerName[10];
	char  gender[10];
	char  college[20];
	project_player pro[3];
}player;

typedef struct
{
	int player_code;
	char name[10];
	float sc;
}score_rank;
typedef struct
{
	int code;
	char name[20];
	int placeCode;
	char place[20];
	int numberOfPlayerPerGroup;
	int timeOfGroup;
	char unitOfMeasureMent[4];
	int isEnd=0;
}project;
typedef struct{
	char c[20];//学院名字字符串表示
	int cd;//学院的编号
	int goal;// 学院的积分
}collegeCode;//该结构体用来记录学院的类型
typedef struct
{
	int		projectCode;
	char		projectName[20];
	int		countOfPlayer;
	int		 estimatedTime;
}time_take;
typedef struct
{
	int  projectCode;
	char projectName[20];
	int  isConflict;
}conflict;
typedef struct
{
	int projectCode;
	char projectName[20];
	int timeCode;
}distribution;
void main_surface();
void rank_by_college();
void rank_result_file();
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
	printf("\t\t\t\t");
	while (n--)
		putchar(ch);
	printf("\n");
	return;
}

int printf_pro_data(int i)
{
	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("比赛项目表.txt", "r");
	printf("序号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\n");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		if (i)
		{
			count = pro.code-1;
		}
		printf("%d\t%8s\t%8d\t%8s\t",count+1,pro.name,pro.placeCode,pro.place);
		printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
	return count;
}

void printf_pro_info(){//打印出所有已录入的比赛项目的信息

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("比赛项目表.txt", "r");
	printf("编号\t项目名称\t场地编号\t场地名称\t计量单位\t每组人数\t每组时间\n");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{

		printf("%d\t%8s\t%8d\t%8s\t",pro.code,pro.name,pro.placeCode,pro.place);
		printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
}

int checkChongfu(int input){//检查比赛项目是否重复输入了 ,如果已经重复录入了返回1，没重复返回0

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("比赛项目表.txt", "r");

	int num;
	int flag=0;
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		num=pro.code;
		if(input==num){
			flag=1;
			break;

		}
		//printf("%d\t%8s\t%8d\t%8s\t",pro.code,pro.name,pro.placeCode,pro.place);
		//printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
	return flag;
}

int isIn(int input){//检查比赛项目是否已经录入了 ,如果已经录入了返回1，没录入返回0

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("比赛项目表.txt", "r");

	int num;
	int flag=0;
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		num=pro.code;
		if(input==num){
			flag=1;
			break;

		}
		//printf("%d\t%8s\t%8d\t%8s\t",pro.code,pro.name,pro.placeCode,pro.place);
		//printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
	return flag;
}

int printf_playerList_data(char *fileName)
{
	FILE *fp;
	FILE *fp2;
	player player1;
	int count = 0;
	fp = fopen(fileName, "r");

	printf("运动员编号\t姓名\t性别\t学院\t项目三: \n");
	int i;
	while ((i=fread(&player1, sizeof(player), 1, fp)) != NULL)
	{

		printf("%d\t%s\t%s\t%s\t",player1.playerCode,player1.playerName,player1.gender,player1.college);
		printf("%d\t%d\t%d\t\n",player1.pro[0].code,player1.pro[1].code,player1.pro[2].code);
		printf("人数%d\n",++count);
	}
	if(i==0&&count==25){
     fp2=fp;
	}
	fp2++;
	while ((i=fread(&player1, sizeof(player), 1, fp2)) != NULL)
	{

		printf("%d\t%s\t%s\t%s\t",player1.playerCode,player1.playerName,player1.gender,player1.college);
		printf("%d\t%d\t%d\t\n",player1.pro[0].code,player1.pro[1].code,player1.pro[2].code);
		printf("人数%d\n",++count);
	}
	fclose(fp);
	fclose(fp2);
	return count;

}
int printf_player_score_data(char *fileName)
{
	FILE *fp;
	player player1;
	int count = 0;
	fp = fopen(fileName, "r");
	printf("编号\t姓名\t性别\t学院\n");
	while ((fread(&player1, sizeof(player), 1, fp)) != NULL)
	{
		printf("%d\t%s\t%s\t%s\n", player1.playerCode, player1.playerName, player1.gender, player1.college);
		count++;

	}
	fclose(fp);
	return count;
}
int did_delete_or_modify()
{
	int choice;
	printf("请确认您是否要执行此次修改、删除操作YES(1)/NO(0): ");
	scanf("%d", &choice);
	return choice;
}
void delete_project()
{
	FILE *fp;
	project pro, proArr[PROJECTMAX];
	int modifyCode;
	int proCount = 0;
	printf_pro_data(0);
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
		for (int i = modifyCode-1; i < proCount; i++)
		{
			proArr[i] = proArr[i + 1];
		}
		proCount -= 1;
	}
	fp = fopen("比赛项目表.txt", "w");
	fwrite(proArr, sizeof(project), proCount, fp);
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
		printf_pro_data(0);
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
void print_sp(){//打印出所有可供选择的比赛项目

	project pro[100];
	//定义所有比赛项目
	//所有比赛场地地点对应编号如下：caochang-101;pool-102;shachi-103;kongdi1-104;kongdi2-105; kongdi3-106;
	//运动项目1 ：run100
	strcpy(pro[1].name,"run100");
	pro[1].code=201;
	strcpy(pro[1].place,"caochang");
	pro[1].placeCode=101;
	strcpy(pro[1].unitOfMeasureMent,"s") ;
	pro[1].numberOfPlayerPerGroup=4;
	pro[1].timeOfGroup=100;
	//运动项目2 :run200
	strcpy(pro[2].name,"run200");
	pro[2].code=202;
	strcpy(pro[2].place,"caochang");
	pro[2].placeCode=101;
	strcpy(pro[2].unitOfMeasureMent,"s") ;
	pro[2].numberOfPlayerPerGroup=4;
	pro[2].timeOfGroup=200;
	//运动项目3：run400
	strcpy(pro[3].name,"run400");
	pro[3].code=203;
	strcpy(pro[3].place,"caochang");
	pro[3].placeCode=101;
	strcpy(pro[3].unitOfMeasureMent,"s") ;
	pro[3].numberOfPlayerPerGroup=4;
	pro[3].timeOfGroup=400;
	//运动项目4：run800
	strcpy(pro[4].name,"run800");
	pro[4].code=204;
	strcpy(pro[4].place,"caochang");
	pro[4].placeCode=101;
	strcpy(pro[4].unitOfMeasureMent,"s") ;
	pro[4].numberOfPlayerPerGroup=4;
	pro[4].timeOfGroup=800;
	//运4动项目5：run1000
	strcpy(pro[5].name,"run1000");
	pro[5].code=205;
	strcpy(pro[5].place,"caochang");
	pro[5].placeCode=101;
	strcpy(pro[5].unitOfMeasureMent,"s") ;
	pro[5].numberOfPlayerPerGroup=4;
	pro[5].timeOfGroup=1000;
	//运动项目6：run2000
	strcpy(pro[6].name,"run2000");
	pro[6].code=206;
	strcpy(pro[6].place,"caochang");
	pro[6].placeCode=101;
	strcpy(pro[6].unitOfMeasureMent,"s") ;
	pro[6].numberOfPlayerPerGroup=4;
	pro[6].timeOfGroup=2000;
	//运动项目7：run5000
	strcpy(pro[7].name,"run5000");
	pro[7].code=207;
	strcpy(pro[7].place,"caochang");
	pro[7].placeCode=101;
	strcpy(pro[7].unitOfMeasureMent,"s") ;
	pro[7].numberOfPlayerPerGroup=4;
	pro[7].timeOfGroup=5000;
	//运动项目8：run4*100
	strcpy(pro[8].name,"run4*100");
	pro[8].code=208;
	strcpy(pro[8].place,"caochang");
	pro[8].placeCode=101;
	strcpy(pro[8].unitOfMeasureMent,"s") ;
	pro[8].numberOfPlayerPerGroup=4;
	pro[8].timeOfGroup=400;
	//运动项目9:run4*200
	strcpy(pro[9].name,"run4*200");
	pro[9].code=209;
	strcpy(pro[9].place,"caochang");
	pro[9].placeCode=101;
	strcpy(pro[9].unitOfMeasureMent,"s") ;
	pro[9].numberOfPlayerPerGroup=4;
	pro[9].timeOfGroup=800;
	//运动项目10： swim100
	strcpy(pro[10].name,"swim100");
	pro[10].code=210;
	strcpy(pro[10].place,"pool");
	pro[10].placeCode=102;
	strcpy(pro[10].unitOfMeasureMent,"s") ;
	pro[10].numberOfPlayerPerGroup=4;
	pro[10].timeOfGroup=100;
	//运动项目11：swim200
	strcpy(pro[11].name,"swim200");
	pro[11].code=211;
	strcpy(pro[11].place,"pool");
	pro[11].placeCode=102;
	strcpy(pro[11].unitOfMeasureMent,"s") ;
	pro[11].numberOfPlayerPerGroup=4;
	pro[11].timeOfGroup=200;
	//运动项目12：swim400
	strcpy(pro[12].name,"swim400");
	pro[12].code=212;
	strcpy(pro[12].place,"pool");
	pro[12].placeCode=102;
	strcpy(pro[12].unitOfMeasureMent,"s") ;
	pro[12].numberOfPlayerPerGroup=4;
	pro[12].timeOfGroup=400;
	//运动项目13：swim800
	strcpy(pro[13].name,"swim800");
	pro[13].code=213;
	strcpy(pro[13].place,"pool");
	pro[13].placeCode=102;
	strcpy(pro[13].unitOfMeasureMent,"s") ;
	pro[13].numberOfPlayerPerGroup=4;
	pro[13].timeOfGroup=800;
	//运动项目14：swim1000
	strcpy(pro[14].name,"swim1000");
	pro[14].code=214;
	strcpy(pro[14].place,"pool");
	pro[14].placeCode=102;
	strcpy(pro[14].unitOfMeasureMent,"s") ;
	pro[14].numberOfPlayerPerGroup=4;
	pro[14].timeOfGroup=1000;
	//运动项目15：swim4*100
	strcpy(pro[15].name,"swim4*100 ");
	pro[15].code=215;
	strcpy(pro[15].place,"pool");
	pro[15].placeCode=102;
	strcpy(pro[15].unitOfMeasureMent,"s") ;
	pro[15].numberOfPlayerPerGroup=4;
	pro[15].timeOfGroup=400;
	//运动项目16：jumplong
	strcpy(pro[16].name,"jumplong");
	pro[16].code=216;
	strcpy(pro[16].place,"shachi");
	pro[16].placeCode=103;
	strcpy(pro[16].unitOfMeasureMent,"m") ;
	pro[16].numberOfPlayerPerGroup=4;
	pro[16].timeOfGroup=100;
	//运动项目17：jumphigh
	strcpy(pro[17].name,"jumphigh");
	pro[17].code=217;
	strcpy(pro[17].place,"kongdi1");
	pro[17].placeCode=104;
	strcpy(pro[17].unitOfMeasureMent,"m") ;
	pro[17].numberOfPlayerPerGroup=4;
	pro[17].timeOfGroup=100;
	//运动项目18：zhibiaoqiang
	strcpy(pro[18].name,"zhibiaoqiang");
	pro[18].code=218;
	strcpy(pro[18].place,"kongdi2");
	pro[18].placeCode=105;
	strcpy(pro[18].unitOfMeasureMent,"m") ;
	pro[18].numberOfPlayerPerGroup=4;
	pro[18].timeOfGroup=100;
	//运动项目19：zhiqianqiu
	strcpy(pro[19].name,"zhiqianqiu");
	pro[19].code=219;
	strcpy(pro[19].place,"kongdi3");
	pro[19].placeCode=106;
	strcpy(pro[19].unitOfMeasureMent,"m") ;
	pro[19].numberOfPlayerPerGroup=4;
	pro[19].timeOfGroup=100;
	//


	printf("项目名\t\t编号\t地点\t\t场地编号\t单位\t每组人数\t持续时间\n");
	int i;
	for(i=1;i<20;i++){
		printf("%8s\t%d\t%8s\t%d\t\t%s\t%d\t\t%d\n",pro[i].name,pro[i].code,pro[i].place,pro[i].placeCode,pro[i].unitOfMeasureMent,pro[i].numberOfPlayerPerGroup,pro[i].timeOfGroup);
	}
}

void add_project()
{
	project pro[100];
	//定义所有比赛项目
	//所有比赛场地地点对应编号如下：caochang-101;pool-102;shachi-103;kongdi1-104;kongdi2-105; kongdi3-106;
	//运动项目1 ：run100
	strcpy(pro[1].name,"run100");
	pro[1].code=201;
	strcpy(pro[1].place,"caochang");
	pro[1].placeCode=101;
	strcpy(pro[1].unitOfMeasureMent,"s") ;
	pro[1].numberOfPlayerPerGroup=4;
	pro[1].timeOfGroup=100;
	//运动项目2 :run200
	strcpy(pro[2].name,"run200");
	pro[2].code=202;
	strcpy(pro[2].place,"caochang");
	pro[2].placeCode=101;
	strcpy(pro[2].unitOfMeasureMent,"s") ;
	pro[2].numberOfPlayerPerGroup=4;
	pro[2].timeOfGroup=200;
	//运动项目3：run400
	strcpy(pro[3].name,"run400");
	pro[3].code=203;
	strcpy(pro[3].place,"caochang");
	pro[3].placeCode=101;
	strcpy(pro[3].unitOfMeasureMent,"s") ;
	pro[3].numberOfPlayerPerGroup=4;
	pro[3].timeOfGroup=400;
	//运动项目4：run800
	strcpy(pro[4].name,"run800");
	pro[4].code=204;
	strcpy(pro[4].place,"caochang");
	pro[4].placeCode=101;
	strcpy(pro[4].unitOfMeasureMent,"s") ;
	pro[4].numberOfPlayerPerGroup=4;
	pro[4].timeOfGroup=800;
	//运4动项目5：run1000
	strcpy(pro[5].name,"run1000");
	pro[5].code=205;
	strcpy(pro[5].place,"caochang");
	pro[5].placeCode=101;
	strcpy(pro[5].unitOfMeasureMent,"s") ;
	pro[5].numberOfPlayerPerGroup=4;
	pro[5].timeOfGroup=1000;
	//运动项目6：run2000
	strcpy(pro[6].name,"run2000");
	pro[6].code=206;
	strcpy(pro[6].place,"caochang");
	pro[6].placeCode=101;
	strcpy(pro[6].unitOfMeasureMent,"s") ;
	pro[6].numberOfPlayerPerGroup=4;
	pro[6].timeOfGroup=2000;
	//运动项目7：run5000
	strcpy(pro[7].name,"run5000");
	pro[7].code=207;
	strcpy(pro[7].place,"caochang");
	pro[7].placeCode=101;
	strcpy(pro[7].unitOfMeasureMent,"s") ;
	pro[7].numberOfPlayerPerGroup=4;
	pro[7].timeOfGroup=5000;
	//运动项目8：run4*100
	strcpy(pro[8].name,"run4*100");
	pro[8].code=208;
	strcpy(pro[8].place,"caochang");
	pro[8].placeCode=101;
	strcpy(pro[8].unitOfMeasureMent,"s") ;
	pro[8].numberOfPlayerPerGroup=4;
	pro[8].timeOfGroup=400;
	//运动项目9:run4*200
	strcpy(pro[9].name,"run4*200");
	pro[9].code=209;
	strcpy(pro[9].place,"caochang");
	pro[9].placeCode=101;
	strcpy(pro[9].unitOfMeasureMent,"s") ;
	pro[9].numberOfPlayerPerGroup=4;
	pro[9].timeOfGroup=800;
	//运动项目10： swim100
	strcpy(pro[10].name,"swim100");
	pro[10].code=210;
	strcpy(pro[10].place,"pool");
	pro[10].placeCode=102;
	strcpy(pro[10].unitOfMeasureMent,"s") ;
	pro[10].numberOfPlayerPerGroup=4;
	pro[10].timeOfGroup=100;
	//运动项目11：swim200
	strcpy(pro[11].name,"swim200");
	pro[11].code=211;
	strcpy(pro[11].place,"pool");
	pro[11].placeCode=102;
	strcpy(pro[11].unitOfMeasureMent,"s") ;
	pro[11].numberOfPlayerPerGroup=4;
	pro[11].timeOfGroup=200;
	//运动项目12：swim400
	strcpy(pro[12].name,"swim400");
	pro[12].code=212;
	strcpy(pro[12].place,"pool");
	pro[12].placeCode=102;
	strcpy(pro[12].unitOfMeasureMent,"s") ;
	pro[12].numberOfPlayerPerGroup=4;
	pro[12].timeOfGroup=400;
	//运动项目13：swim800
	strcpy(pro[13].name,"swim800");
	pro[13].code=213;
	strcpy(pro[13].place,"pool");
	pro[13].placeCode=102;
	strcpy(pro[13].unitOfMeasureMent,"s") ;
	pro[13].numberOfPlayerPerGroup=4;
	pro[13].timeOfGroup=800;
	//运动项目14：swim1000
	strcpy(pro[14].name,"swim1000");
	pro[14].code=214;
	strcpy(pro[14].place,"pool");
	pro[14].placeCode=102;
	strcpy(pro[14].unitOfMeasureMent,"s") ;
	pro[14].numberOfPlayerPerGroup=4;
	pro[14].timeOfGroup=1000;
	//运动项目15：swim4*100
	strcpy(pro[15].name,"swim4*100 ");
	pro[15].code=215;
	strcpy(pro[15].place,"pool");
	pro[15].placeCode=102;
	strcpy(pro[15].unitOfMeasureMent,"s") ;
	pro[15].numberOfPlayerPerGroup=4;
	pro[15].timeOfGroup=400;
	//运动项目16：jumplong
	strcpy(pro[16].name,"jumplong");
	pro[16].code=216;
	strcpy(pro[16].place,"shachi");
	pro[16].placeCode=103;
	strcpy(pro[16].unitOfMeasureMent,"m") ;
	pro[16].numberOfPlayerPerGroup=4;
	pro[16].timeOfGroup=100;
	//运动项目17：jumphigh
	strcpy(pro[17].name,"jumphigh");
	pro[17].code=217;
	strcpy(pro[17].place,"kongdi1");
	pro[17].placeCode=104;
	strcpy(pro[17].unitOfMeasureMent,"m") ;
	pro[17].numberOfPlayerPerGroup=4;
	pro[17].timeOfGroup=100;
	//运动项目18：zhibiaoqiang
	strcpy(pro[18].name,"zhibiaoqiang");
	pro[18].code=218;
	strcpy(pro[18].place,"kongdi2");
	pro[18].placeCode=105;
	strcpy(pro[18].unitOfMeasureMent,"m") ;
	pro[18].numberOfPlayerPerGroup=4;
	pro[18].timeOfGroup=100;
	//运动项目19：zhiqianqiu
	strcpy(pro[19].name,"zhiqianqiu");
	pro[19].code=219;
	strcpy(pro[19].place,"kongdi3");
	pro[19].placeCode=106;
	strcpy(pro[19].unitOfMeasureMent,"m") ;
	pro[19].numberOfPlayerPerGroup=4;
	pro[19].timeOfGroup=100;
	//



	//
	FILE *fp;
	project pro1;
	int choice = 1;
	if ((fp = fopen("比赛项目表.txt", "a")) == NULL)
	{
		printf("打开错误！");
	}
	else
	{
		do
		{
		    system("cls");
			print_sp();
			printf("请输入要添加项目的编号：");
			int j;
			scanf("%d",&j);
			while(j<=200||j>219){//限制输入的编号在允许范围201-219之间
				scanf("%d",&j);
			}
			pro1.code=j;
			int i =pro1.code-200;//得到数组的下标
			strcpy(pro1.name,pro[i].name);
			strcpy(pro1.place,pro[i].place);
			pro1.placeCode=pro[i].placeCode;
			strcpy(pro1.unitOfMeasureMent,pro[i].unitOfMeasureMent);
			pro1.numberOfPlayerPerGroup=pro[i].numberOfPlayerPerGroup;
			pro1.timeOfGroup=pro[i].timeOfGroup;
		/*
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
		*/
			if(checkChongfu(j)){
				printf("该比赛项目已经录入系统了，操作无效\n");
			}
			else{
				printf("该比赛项目尚未录入，正在进行录入...请稍后...\n");
				fwrite(&pro1, sizeof(project), 1, fp);
				printf("录入成功!\n");
			}

			printf("是否要继续录入其他项目？YES(1)/NO(0)");
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
	   // printf("%d",playerCode);
		playerCode++;
	}
	fclose(fp);
	return playerCode;
}
void player_join()
{
	FILE *fp;
	player player1;
	int numberOfJoin;
	int playerCode;
	int s;

	printf_pro_data(1);
	//定义所有的学院和书院
	/*
	typedef struct{
	char c[20];//学院名字字符串表示
	int cd;// 学院的编号
	}collegeCode;//该结构体用来记录学院的类型
	*/
	collegeCode cc[20];
	//
	cc[1].cd=301;
	strcpy(cc[1].c,"gong");
	//
	cc[2].cd=302;
	strcpy(cc[2].c,"wen");
	//
	cc[3].cd=303;
	strcpy(cc[3].c,"li");
	//
	cc[4].cd=304;
	strcpy(cc[4].c,"yi");
	//
	cc[5].cd=305;
	strcpy(cc[5].c,"fa");
	//
	cc[6].cd=306;
	strcpy(cc[6].c,"xinwen");
	//
	cc[7].cd=307;
	strcpy(cc[7].c,"yishu");
	//
	cc[8].cd=308;
	strcpy(cc[8].c,"yanjiu");
	//
	cc[9].cd=309;
	strcpy(cc[9].c,"zhicheng");
	//
	cc[10].cd=310;
	strcpy(cc[10].c,"xinshuyuan");
	//定义完成


	if ((fp = fopen("运动员报名表.txt", "a")) == NULL)
	{
		printf("打开错误！");
	}
	else
	{
		playerCode = count_playerCode();
		player1.playerCode = playerCode;
		printf("已有%d名运动员报名!\n",playerCode-1);
		printf("请输入你的名字：");
		scanf("%s", &player1.playerName);
		printf("可供选择的学（书）院名称以及对应的编号如下：\n");
		int n;
		for(n=1;n<=10;n++){
			printf("%d %s\n",cc[n].cd,cc[n].c);
		}
		printf("请输入你的学院代码：");
		int ii;
		scanf("%d",&ii);
		int j=ii-300;//得到数组下标
		strcpy(player1.college,cc[j].c);
		printf("学院代码为%d=%s\n",ii,player1.college);
		//scanf("%s", &player1.college);
		printf("请输入你的性别(1.代表男生/2代表女生)：");
		int k;
		scanf("%d",&k);
		while(k!=1&&k!=2){
			printf("输入有误，请重新输入：\n");
			printf("请输入你的性别(1.代表男生/2代表女生)：");
			scanf("%d",&k);
		}
		if(k==1){
			strcpy(player1.gender,"male");
		}
		else if(k==2){
			strcpy(player1.gender,"female");
		}
		else{
			printf("输入的值检查机制错误\n");
		}
		//scanf("%s", &player1.gender);
		printf("请输入想要参加的项目个数(不多于3个)：");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "无");
		}
		printf("管理员已发布的比赛项目有如下：\n");
		printf_pro_info();
		int ProNum[3]={0,0,0};
		for (int i = 0;i < numberOfJoin;i++)
		{

			/*
			printf("请输入项目名称：");
			scanf("%s", &player1.pro[i].name);
			*/
            //注意我是在这里开始改动的。。。。。。。。。建立一个数组来检查是否相同

            int is_exist=0;
			printf("请输入第%d个项目的编号：",i+1);
			scanf("%d", &player1.pro[i].code);
			while(isIn(player1.pro[i].code)!=1){
				printf("您输入的运动项目管理员没有发布，请输入已经发布的项目编号\n");
				printf("请重新输入第%d个项目的编号：",i+1);
				scanf("%d", &player1.pro[i].code);
			}
			while(player1.pro[i].code==ProNum[0]||player1.pro[i].code==ProNum[1]||player1.pro[i].code==ProNum[2])
            {
                printf("您已重复输入该项目,请输入另一个项目编号\n");
                printf("请重新输入第%d个项目的编号：",i+1);
				scanf("%d", &player1.pro[i].code);
            }
            ProNum[i]=player1.pro[i].code;
			printf("输入正确，系统正在录入\n");
			int l =player1.pro[i].code-200;//得到索引值
			switch(l){
				case 1:strcpy(player1.pro[i].name,"run100");break;
				case 2:strcpy(player1.pro[i].name,"run200");break;
				case 3:strcpy(player1.pro[i].name,"run400");break;
				case 4:strcpy(player1.pro[i].name,"run800");break;
				case 5:strcpy(player1.pro[i].name,"run1000");break;
				case 6:strcpy(player1.pro[i].name,"run2000");break;
				case 7:strcpy(player1.pro[i].name,"run5000");break;
				case 8:strcpy(player1.pro[i].name,"run4*100");break;
				case 9:strcpy(player1.pro[i].name,"run4*200");break;
				case 10:strcpy(player1.pro[i].name,"swim100");break;
				case 11:strcpy(player1.pro[i].name,"swim200");break;
				case 12:strcpy(player1.pro[i].name,"swim400");break;
				case 13:strcpy(player1.pro[i].name,"swim800");break;
				case 14:strcpy(player1.pro[i].name,"swim1000");break;
				case 15:strcpy(player1.pro[i].name,"swim4*100 ");break;
				case 16:strcpy(player1.pro[i].name,"jumplong");break;
				case 17:strcpy(player1.pro[i].name,"jumphigh");break;
				case 18:strcpy(player1.pro[i].name,"zhibiaoqiang");break;
				case 19:strcpy(player1.pro[i].name,"zhiqianqiu");break;
				default:printf("输入的编号有误！\n");
			}
		}
		int is_success=fwrite(&player1, sizeof(player), 1, fp);
		printf("是否成功%d\n",is_success);
		//system("pause");
	}
	fclose(fp);
	printf("你的编号为%d\n按(1)退出:", playerCode);
	scanf("%d", &s);

}
void clean_players()
{
    int playerCode = 0;
	FILE *fp;
	player player1;
	fp = fopen("运动员报名表.txt", "r");
	while (fread(&player1, sizeof(player), 1, fp) != NULL)
	{
	   // printf("%d",playerCode);
		playerCode++;
	}
	fclose(fp);
	printf("恢复为%d个？\n",playerCode);
	player *playerArr=(player*)malloc((sizeof(player)*playerCode));
	fp=fopen("运动员报名表.txt","r");
	fread(playerArr,sizeof(player),playerCode,fp);
	fclose(fp);
	fp=fopen("运动员报名表.txt","w");
	printf("成功写进多少个%d\n",fwrite(playerArr,sizeof(player),playerCode,fp));
	fclose(fp);
	free(playerArr);

	//return playerCode;

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
			if (player1.pro[0].code == proCode || player1.pro[1].code == proCode || player1.pro[2].code == proCode)
			{
				//printf("%d", player1.playerCode);
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
		//printf("%s\n", proArr[i].name);
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
					//			printf("%d=?=%d\n", playerArrA[ii].playerCode, playerArrB[jj].playerCode);
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

				//printf("%d\t%s\t%d\n", con.projectCode, con.projectName, con.isConflict);
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
				//printf("%s\n", fileName);
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
					//printf("\n%d=?=%d\n", distriArr[count].projectCode, conArr[i].projectCode);
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
void enter_results()//录入比赛项目的成绩
{
	FILE *fp;
	project pro[PROJECTMAX];
	int count;
	int choice;
	float score;
	int is_exit;
	char *file_name;
	player playerArr[PLAYERMAX];
	score_rank score_arr[PLAYERMAX];
    count = printf_pro_data(1);
   // system("cls");
	fp = fopen("比赛项目表.txt", "r");
	fread(pro, sizeof(project), count, fp);
	fclose(fp);
	do
	{
	   // system("cls");
	   // printf_pro_data(1);
		printf("请输入要录入结果的项目编号：");
		scanf("%d", &choice);
		choice-=200;
		file_name = string_link(pro[choice - 1].name, "名单表.txt");
		count = printf_player_score_data(file_name);
		fp = fopen(file_name, "r");
		fread(playerArr, sizeof(player), count, fp);
		fclose(fp);
		/*for (int i = 0; i < 2; i++)
		{
		printf("%d", playerArr[i].playerCode);
		}*/
		printf("\n请依次输入运动员的成绩:\n");
		for (int i = 0; i <count; i++)
		{
			printf("第%d个运动员%s的成绩:", i + 1,playerArr[i].playerName);
			scanf("%f", &score);
            score_arr[i].sc = score;
            strcpy(score_arr[i].name, playerArr[i].playerName);
            score_arr[i].player_code = playerArr[i].playerCode;

		}//只是从中抽取出运动员的编码，名字，成绩放在一个文件里面。
		file_name = string_link(pro[choice - 1].name, "成绩表.txt");
		fp = fopen(file_name, "w");
		fwrite(score_arr, sizeof(score_rank), count, fp);
		fclose(fp);
		printf("退出？YES(1)(0)");
		scanf("%d", &is_exit);
	} while (!is_exit);

}

void print_all_result()
{
    FILE *fpo;
    fpo=fopen("比赛项目表.txt","r");
    project pro[PROJECTMAX];
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);
    for(int i=0;i<count_pro;i++)
    {
        char FileName[20];
        strcpy(FileName,string_link(pro[i].name,"成绩表.txt"));
        FILE *fre=fopen(FileName,"r");
        score_rank ScoreArr[PLAYERMAX];
        int count_re=fread(ScoreArr,sizeof(score_rank),PLAYERMAX,fre);
        printf("%s项目的成绩如下：\n",pro[i].name);
        for(int j=0;j<count_re;j++)
            printf("第%d个人编号%d姓名：%s的成绩：%f\n",j+1,ScoreArr[j].player_code,ScoreArr[j].name,ScoreArr[j].sc);

        fclose(fre);
    }
    fclose(fpo);
}
void rank(char *file_name,int n)//打印其中一个比赛项目的排名情况，文件名file_name，n= 1表示升序（跑步。游泳）输出，n！=1（投标枪，投铁饼）是代表 降序输入
{
	FILE *fp;
	score_rank p,q,arr[PLAYERMAX],b[1];
	int count = 0;
	int min;
	fp = fopen(file_name, "r");
	while ((fread(&q,sizeof(score_rank),1,fp))!=NULL)
	{
		arr[count] = q;
		count++;
	}
	//printf("%f\n", arr[1].sc);
	fclose(fp);
	//选择排序
	for (int i = 0;i <= count - 2;i++)
	{
		min = i;
		for (int j = i+1; j <= count-1; j++)
		{
			if (arr[j].sc < arr[min].sc)//降序排序
				min = j;
		}
		b[0] = arr[i];
		arr[i] = arr[min];
		arr[min] = b[0];
	}
	//打印信息
	printf("名次\t姓名\t成绩\n");
	if (n)
	{
		for (int i = 0; i < count; i++)
		{
			printf("%d\t%s\t%f\n", i + 1, arr[i].name, arr[i].sc);
		}
	}
	else
	{
		for (int i = count-1; i >=0 ; i--)
		{
			printf("%d\t%8s\t%8f \n", count-i, arr[i].name, arr[i].sc);
		}
	}
	//printf("请按任意键继续");
	system("pause");
}


void query_scores()
{
	int player_code;
	player p;
	score_rank q;
	FILE *fp, *fp1;
	char *fileName;
	int is_exit;
	printf("请输入你的编号：");
	scanf("%d", &player_code);

	fp = fopen("运动员报名表.txt", "r");
	while ((fread(&p, sizeof(player), 1, fp)) != NULL)
	{
		if (p.playerCode == player_code)
		{
			printf("欢迎%s\n",p.playerName);
			printf("您的所有项目成绩如下:\n项目名称\t项目成绩\n");
			for (int i = 0; i < 3; i++)
			{
				if (strcmp("无", p.pro[i].name) != 0)
				{
					fileName = string_link(p.pro[i].name, "成绩表.txt");
					//printf("%s", fileName);
					fp1 = fopen(fileName, "r");
					while ((fread(&q, sizeof(score_rank), 1, fp1)) != NULL)
					{
						if (q.player_code == player_code)
						{
							printf("%8s\t%8f\n", p.pro[i].name, q.sc);
						}
					}
					fclose(fp1);
				}
			}
		}
	}
	fclose(fp);
	printf("按（1）退出：");
	scanf("%d", &is_exit);
}
void	query_dirtribution()
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


/*
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
		printf("\t\t\t\t\t6.查看已录入的项目\n");
		printf("\t\t\t\t\t7.返回上级\n");
		bound('=', 30);
		printf("请输入选项：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			add_project();
			break;
		case 2:
			system("cls");
			modify_project();
			break;
		case 3:
			system("cls");
			delete_project();
			break;
		case 4:
			system("cls");
			enter_results();
			break;
		case 5:
			system("cls");
			//create_player_of_project();
			create_conflict_of_project();
			create_time_of_distribution();
			query_dirtribution();
			break;
		case 6:
		 	system("cls");
		 	printf_pro_info();
		 	printf("三秒后自动返回上一菜单...\n");
			Sleep(3000);
		 	break;
		case 7:
			system("cls");
			main_surface();
			break;
		}
	} while (1);
}
*/
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

void infochaxun(){
	printf("请选择查询的方式：1.按比赛项目排名；2按个人成绩查询；3.查看学院积分和排名");
	int choice;
	while((scanf("%d",&choice),choice!=1&&choice!=2&&choice!=3))
	printf("输入错误，请重新输入：\n");
	if(choice==1){
        int is_exit;
		do
        {
            system("cls");
            printf_pro_info();
            char s[20],ss[20];
            strcpy(s,"");//这句话有错了
            printf("请输入你要查询的比赛项目的编号：");
            int i;
            scanf("%d", &i);
		/*if(!isIn(i)){
			printf("该比赛项目没有举行，不能录入成绩\n");
			printf("请重新输入你要查询的比扫项目的编号：");
			scanf("%d", &i);
		}*///这个判断在这里是没有意义的，因为这个isin是判断是否存在，需要改水电费说得对水电费
		//printf("输入正确，系统正在录入\n");
            int l =i-200;//得到索引值
            int n;
            switch(l){
                case 1:strcpy(s,"run100");n=1;break;
                case 2:strcpy(s,"run200");n=1;break;
                case 3:strcpy(s,"run400");n=1;break;
                case 4:strcpy(s,"run800");n=1;break;
                case 5:strcpy(s,"run1000");n=1;break;
                case 6:strcpy(s,"run2000");n=1;break;
                case 7:strcpy(s,"run5000");n=1;break;
                case 8:strcpy(s,"run4*100");n=1;break;
                case 9:strcpy(s,"run4*200");n=1;break;
                case 10:strcpy(s,"swim100");n=1;break;
                case 11:strcpy(s,"swim200");n=1;break;
                case 12:strcpy(s,"swim400");n=1;break;
                case 13:strcpy(s,"swim800");n=1;break;
                case 14:strcpy(s,"swim1000");n=1;break;
                case 15:strcpy(s,"swim4*100 ");n=1;break;
                case 16:strcpy(s,"jumplong");n=0;break;
                case 17:strcpy(s,"jumphigh");n=0;break;
                case 18:strcpy(s,"zhibiaoqiang");n=0;break;
                case 19:strcpy(s,"zhiqianqiu");n=0;break;
                default:printf("输入的编号有误！\n");
            }
            strcpy(ss,string_link(s, "成绩表.txt"));
            rank(ss,n);
            printf("是否继续查看其它项目的排名:yes(1)/no(0)\n");

        }while((scanf("%d",&is_exit),fflush(stdin),is_exit==1));
	}
	if(choice==2){
		query_scores();
	}
	if(choice==3)
    {
        rank_by_college();
    }
}
int read_state(char *FileName)//返回阶段数据
{
    FILE *fp;


//    char name[20];
//    strcpy(name,FileName);
    fp=fopen(FileName,"r");
    int state=0;
    fscanf(fp,"%d",&state);
    fclose(fp);
    if(state==1)
        return 1;
   // fclose(fp);
    //return state;
    else return 0;
}
void write_state(char *FileName,int state)//把一个阶段的代表数字写进”阶段.txt“这个文件夹里面
{
    FILE *fp;
    fp=fopen(FileName,"w");
    fprintf(fp,"%d",state);
    //
    printf("写入%d成功\n",state);
    fclose(fp);
    //return 0;

}


int jieduan(){
	//1管理员录入比赛项目的阶段（该阶段禁止运动员报名）
	//2运动员报名期间 （解锁运动员报名功能）
	//3生成秩序册，确认比赛赛程安排（该阶段禁止运动员再报名，所以只需生成一次秩序册即可）
	//4比赛进行完录入成绩阶段（该阶段才解锁查询成绩功能）
	int i,j,k,l;
	i=read_state("第一状态表.txt");
	j=read_state("第二状态表.txt");
	k=read_state("第三状态表.txt");
	l=read_state("第四状态表.txt");
	printf("i=%d j=%d k=%d l=%d\n",i,j,k,l);
	if(l==1){//为第四阶段
		return 4;
	}
	else if(k==1){//为第三阶段
		return 3;
	}
	else if(j==1){//为第二阶段
		return 2;
	}
	else if(i==1){//为第一阶段
		return 1;
	}
	else return 0;//代表出错了
}
/*
void main_menu()//管理员主菜单
{

	int choice;
	//int temp;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\t\t\t\t\t1.项目发布\n");
		printf("\t\t\t\t\t2.项目修改\n");
		printf("\t\t\t\t\t3.项目删除\n");
		printf("\t\t\t\t\t4.结果录入\n");
		printf("\t\t\t\t\t5.秩序生成\n");
		printf("\t\t\t\t\t6.查看已录入的项目\n");
		printf("\t\t\t\t\t7.返回上级\n");
		bound('=', 30);
		printf("请输入选项：");
		scanf("%d", &choice);
		int temp;
		temp=jieduan();
		switch (choice)
		{
		case 1:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				add_project();
			}
			else{
				printf("当前时间已经不允许再发布比赛项目\n");
			}
			//
			break;
		case 2:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				modify_project();
			}
			else{
				printf("当前时间已经不允许再修改比赛项目\n");
			}
			//
			//modify_project();
			break;
		case 3:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				delete_project();
			}
			else{
				printf("当前时间已经不允许再删除比赛项目\n");
			}
			//

			break;
		case 4:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==3||temp==4){
				enter_results();//录入成绩
				//进入第四阶段，以此解锁运动员查询成绩功能
				write_state("第四状态表.txt",1);
				printf("录入完成。。。\n") ;
			}
			else{
				printf("当前时间不允许录入比赛项目成绩\n");
			}
			//
			//"第三状态表.txt"
			//enter_results();
			break;
		case 5:
			system("cls");
			//create_player_of_project();
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==2){
				printf("如果你进行此操作，运动员将不再可以报名比赛，请管理员确认是否要继续执行此操作：(1.是/2否)") ;
				int c;
				scanf("%d",c);
				if(c==1){
					printf("正在生成秩序册，请稍后。。。\n");
					//生成秩序册
					create_conflict_of_project();
					create_time_of_distribution();
					query_dirtribution();
					//
					printf("秩序册已经生成完成,将不再接受运动员报名，比赛将进入第三阶段\n");
					//修改参数使比赛过度到第三阶段
					write_state("第三状态表.txt",1);

				}
				else{
					printf("您已取消生成秩序册操作\n");
				}
			}
			else{
				printf("当前时间已经不允许生成秩序册\n");
			}
			//
			/*
			create_conflict_of_project();
			create_time_of_distribution();
			query_dirtribution();

			break;
		case 6:
		 	system("cls");
		 	printf_pro_info();
		 	printf("三秒后自动返回上一菜单...\n");
			Sleep(3000);
		 	break;
		case 7:
			system("cls");
			main_surface();
			break;
		}
	} while (1);
}
*/
/*
void main_surface()
{
	int choice;
	do
	{
		system("cls");
		printf("\t\t\t\t\t运动会管理系统\n");
		bound('=',30);
		printf("\t\t\t\t\t1.管理员登录\n\t\t\t\t\t2.运动员报名\n\t\t\t\t\t3.个人成绩查询\n\t\t\t\t\t4.信息查询\n\t\t\t\t\t5.退出系统\n");
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
			system("cls");
			player_join();
			create_player_of_project();
			break;
		case 3:
			system("cls");


			query_scores();
			break;
		case 4:
			infochaxun();
			break;
		case 5:
			exit(0);
			break;
		}
	} while (1);
}
*/

void correctjieduan(){
	int i;
	int j;
	j=jieduan();
	printf("当前阶段为：%d\n",j);
	printf("阶段说明如下；\n");
	printf("1管理员录入比赛项目的阶段（该阶段禁止运动员报名）\n");
	printf("2运动员报名期间 （解锁运动员报名功能）\n");
	printf("3生成秩序册，确认比赛赛程安排（该阶段禁止运动员再报名，所以只需生成一次秩序册即可）\n");
	printf("4比赛进行完录入成绩阶段（该阶段才解锁查询成绩功能）\n");
	printf("请选择你要进入的阶段：");
	scanf("%d",&i);
	if(i==1){
		write_state("第一状态表.txt",1);
		write_state("第二状态表.txt",0);
		write_state("第三状态表.txt",0);
		write_state("第四状态表.txt",0);

	}
	else if(i==2){
		write_state("第一状态表.txt",1);
		write_state("第二状态表.txt",1);
		write_state("第三状态表.txt",0);
		write_state("第四状态表.txt",0);

	}
	else if(i==3){
		write_state("第一状态表.txt",1);
		write_state("第二状态表.txt",1);
		write_state("第三状态表.txt",1);
		write_state("第四状态表.txt",0);

	}
	else if(i==4){
		write_state("第一状态表.txt",1);
		write_state("第二状态表.txt",1);
		write_state("第三状态表.txt",1);
		write_state("第四状态表.txt",1);

	}
	j=jieduan();
	printf("修改后的阶段变为第%d阶段\n",j);

}

void main_menu()//管理员主菜单
{

	int choice;
	//int temp;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\t\t\t\t\t1.项目发布\n");
		printf("\t\t\t\t\t2.项目修改\n");
		printf("\t\t\t\t\t3.项目删除\n");
		printf("\t\t\t\t\t4.结果录入\n");
		printf("\t\t\t\t\t5.秩序生成\n");
		printf("\t\t\t\t\t6.查看已录入的项目\n");
		printf("\t\t\t\t\t7.返回上级\n");
		bound('=', 30);
		printf("请输入选项：");
		scanf("%d", &choice);
		int temp=jieduan();
		switch (choice)
		{
		case 1:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				add_project();
			}
			else{
				printf("当前时间已经不允许再发布比赛项目\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//
			break;
		case 2:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				modify_project();
			}
			else{
				printf("当前时间已经不允许再修改比赛项目\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//
			//modify_project();
			break;
		case 3:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==1){
				delete_project();
			}
			else{
				printf("当前时间已经不允许再删除比赛项目\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//

			break;
		case 4:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==3||temp==4){
				enter_results();//录入成绩
				//进入第四阶段，以此解锁运动员查询成绩功能
				write_state("第四状态表.txt",1);
				printf("录入完成。。。\n") ;
			}
			else{
				printf("当前时间不允许录入比赛项目成绩\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//
			//"第三状态表.txt"
			//enter_results();
			break;
		case 5:
			system("cls");
			//create_player_of_project();
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==2){
				printf("如果你进行此操作，运动员将不再可以报名比赛，请管理员确认是否要继续执行此操作：(1.是/2否)") ;
				int c;
				scanf("%d",&c);
				if(c==1){
					printf("正在生成秩序册，请稍后。。。\n");
					//生成秩序册
					create_conflict_of_project();
					create_time_of_distribution();
					query_dirtribution();
					//
					printf("秩序册已经生成完成,将不再接受运动员报名，比赛将进入第三阶段\n");
					//修改参数使比赛过度到第三阶段
					write_state("第三状态表.txt",1);
					system("pause");

				}
				else{
					printf("您已取消生成秩序册操作\n");
					printf("三秒后自动返回....\n");
					Sleep(3000);
				}
			}
			else{
				printf("当前时间已经不允许生成秩序册\n");
			}
			//
			/*
			create_conflict_of_project();
			create_time_of_distribution();
			query_dirtribution();
			*/
			break;
		case 6:
		 	system("cls");
		 	printf_pro_info();
		 	printf("三秒后自动返回上一菜单...\n");
			Sleep(3000);
		 	break;
		case 7:
			system("cls");
			main_surface();
			break;
		}
	} while (1);
}

void main_surface()//主页面
{
	int choice;
	do
	{
		system("cls");
		printf("\t\t\t\t\t运动会管理系统\n");
		bound('=',30);
		printf("\t\t\t\t\t1.管理员登录\n\t\t\t\t\t2.运动员报名\n\t\t\t\t\t3.个人成绩查询\n\t\t\t\t\t4.信息查询\n\t\t\t\t\t5.退出系统\n\t\t\t\t\t6修改比赛阶段\n");
		bound('=', 30);
		printf("输入您的选择:");
		scanf("%d", &choice);
		int temp=jieduan();
		switch (choice)
		{
		case 1:
			while (check_account()==0);
			main_menu();
			break;
		case 2:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			if(temp==2){
				player_join();
				create_player_of_project();
			}
			else{
				printf("当前时间已经不允许运动员再进行报名了\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//
			/*
			player_join();
			create_player_of_project();
			*/
			break;
		case 3:
			system("cls");
			//
			//int temp=jieduan();
			printf("当前阶段为%d\n",temp) ;
			//
			if(temp==4){
				query_scores();
			}
			else{
				printf("当前时间还未可以查询成绩\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//

			//query_scores();
			break;
		case 4:
			//
			if(temp==4){
				infochaxun();
			}
			else{
				printf("当前时间还未可以查询信息\n");
				printf("三秒后自动返回....\n");
				Sleep(3000);
			}
			//

			//infochaxun();
			break;
		case 5:
			exit(0);
			break;

		case 6:
			correctjieduan();
			break;
		}
	} while (1);
}
int get_project_number_from_name(char *ProjectName)//根据一个项目名字来确定一个项目的编号用以确定是否升序还是降序来排
{
    FILE *fpo=fopen("比赛项目表.txt","r");
    project pro[PROJECTMAX];
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);
    fclose(fpo);
    int project_number=0;
    while(project_number<20)
    {
        project_number++;
        if(strcmp(pro[project_number-1].name,ProjectName)==0)
           return project_number;
    }//这里有bug因为如果这个项目还没有录入比赛项目里面的话就会报错的。


}
void rank_result_file()
{
    FILE *fpo;
    project pro[PROJECTMAX];
    fpo=fopen("比赛项目表.txt","r");
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);//关键就是提取这两个数组出来
    fclose(fpo);
    for(int i=0;i<count_pro;i++)
    {
        FILE *fre;
        char FileName[20];
        strcpy(FileName,string_link(pro[i].name,"成绩表.txt"));
        score_rank scoArr[PLAYERMAX];
        fre=fopen(FileName,"r");
        int count_re=fread(scoArr,sizeof(score_rank),PLAYERMAX,fre);//关键就是提取这两个数组出来哈哈。
        fclose(fre);
        int project_number=get_project_number_from_name(pro[i].name);
        if(1<=project_number&&project_number<=15)
            for(int j=0;j<count_re-1;j++)//简单的选择排序，按照成绩从小到大的排列。
                for(int k=j+1;k<count_re;k++)
                if(scoArr[j].sc>scoArr[k].sc)
                {
                score_rank temp=scoArr[j];
                scoArr[j]=scoArr[k];
                scoArr[k]=temp;
                }
        else if(project_number>15)
            for(int j=0;j<count_re-1;j++)//简单的选择排序，按照成绩从小到大的排列。
                for(int k=j+1;k<count_re;k++)
                if(scoArr[j].sc<scoArr[k].sc)
                {
                score_rank temp=scoArr[j];
                scoArr[j]=scoArr[k];
                scoArr[k]=temp;
                }

        //for(int j=0;j<count_re;j++)
           // printf("%f\n",scoArr[j].sc);
        fre=fopen(FileName,"w");
        fwrite(scoArr,sizeof(score_rank),count_re,fre);
        fclose(fre);


    }
}
char * return_colloge_from_code(int code,char *FileName)
{
    FILE *fpl=fopen(FileName,"r");
    player playArr[PLAYERMAX];
    int count_pl=fread(playArr,sizeof(player),PLAYERMAX,fpl);
    fclose(fpl);
    int i;
    for( i=0;i<count_pl;i++)
        if(playArr[i].playerCode==code)
    {
        char *college=(char *)malloc(20);
        strcpy(college,playArr[i].college);
        return college;
    }
    printf("playercode%d\tcode%d",playArr[i].playerCode,code);
    return NULL;
}
void rank_by_college()
{
    rank_result_file();
    collegeCode cc[20];
	//
	cc[1].cd=301;
	strcpy(cc[1].c,"gong");
	//
	cc[2].cd=302;
	strcpy(cc[2].c,"wen");
	//
	cc[3].cd=303;
	strcpy(cc[3].c,"li");
	//
	cc[4].cd=304;
	strcpy(cc[4].c,"yi");
	//
	cc[5].cd=305;
	strcpy(cc[5].c,"fa");
	//
	cc[6].cd=306;
	strcpy(cc[6].c,"xinwen");
	//
	cc[7].cd=307;
	strcpy(cc[7].c,"yishu");
	//
	cc[8].cd=308;
	strcpy(cc[8].c,"yanjiu");
	//
	cc[9].cd=309;
	strcpy(cc[9].c,"zhicheng");
	//
	cc[10].cd=310;
	for(int i=0;i<=10;i++)
        cc[i].goal=0;
	strcpy(cc[10].c,"xinshuyuan");
	FILE *fpo;
    project pro[PROJECTMAX];
    fpo=fopen("比赛项目表.txt","r");
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);//关键就是提取这两个数组出来
    fclose(fpo);
    for(int i=0;i<count_pro;i++)
    {
        FILE *fre;
        char FileName1[20];
        char FileName2[20];
        strcpy(FileName1,string_link(pro[i].name,"成绩表.txt"));
        strcpy(FileName2,string_link(pro[i].name,"名单表.txt"));
        score_rank scoArr[PLAYERMAX];
        fre=fopen(FileName1,"r");
        int count_re=fread(scoArr,sizeof(score_rank),PLAYERMAX,fre);//关键就是提取这两个数组出来哈哈。
        fclose(fre);
        //printf("%s\n",FileName1);
        for(int j=0;j<3;j++)
        {
           //printf("%s\n",return_colloge_from_code(scoArr[j].player_code,FileName2));
           for(int k=1;k<=10;k++)
           // printf("nihao\n");
           {
               char *college1=return_colloge_from_code(scoArr[j].player_code,FileName2);
               char college2[20];
               strcpy(college2,cc[k].c);
               //printf("%s\n",college);
               int cmp=strcmp(college1,college2);
               if(cmp==0)
                {
                    cc[k].goal+=(5-j*2);
                    int goal=cc[k].goal;break;}

                //这个用函数来关联player.code==college.
                //printf("%d\n",cmp);
                free(college1);
           }

        }

    }//冗长的代码块啊。
    for(int i=1;i<=9;i++)
        for(int j=i+1;j<=10;j++)
        if(cc[i].goal<=cc[j].goal)
    {
        collegeCode temp=cc[i];
        cc[i]=cc[j];
        cc[j]=temp;
    }
    printf("   学院   \t总积分\t排名\n");
    for(int i=1;i<=10;i++)
        printf("%8s\t%d\t%d\n",cc[i].c,cc[i].goal,i);
        system("pause");
}


int main()
{
    //printf_playerList_data("运动员报名表.txt");
   // player_join();
    //clean_players();
	 main_surface();
	//enter_results();
	//add_project();
	//rank_by_college();
	return 1;
}


