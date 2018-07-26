// game.cpp : �������̨Ӧ�ó������ڵ㡣
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
	char c[20];//ѧԺ�����ַ�����ʾ
	int cd;//ѧԺ�ı��
	int goal;// ѧԺ�Ļ���
}collegeCode;//�ýṹ��������¼ѧԺ������
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
		printf("�ڴ��������!");
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
	fp = fopen("������Ŀ��.txt", "r");
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\n");
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

void printf_pro_info(){//��ӡ��������¼��ı�����Ŀ����Ϣ

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("������Ŀ��.txt", "r");
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\n");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{

		printf("%d\t%8s\t%8d\t%8s\t",pro.code,pro.name,pro.placeCode,pro.place);
		printf("%8s\t%8d\t%8d\n", pro.unitOfMeasureMent, pro.numberOfPlayerPerGroup, pro.timeOfGroup);
		count++;
	}
}

int checkChongfu(int input){//��������Ŀ�Ƿ��ظ������� ,����Ѿ��ظ�¼���˷���1��û�ظ�����0

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("������Ŀ��.txt", "r");

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

int isIn(int input){//��������Ŀ�Ƿ��Ѿ�¼���� ,����Ѿ�¼���˷���1��û¼�뷵��0

	FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("������Ŀ��.txt", "r");

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

	printf("�˶�Ա���\t����\t�Ա�\tѧԺ\t��Ŀ��: \n");
	int i;
	while ((i=fread(&player1, sizeof(player), 1, fp)) != NULL)
	{

		printf("%d\t%s\t%s\t%s\t",player1.playerCode,player1.playerName,player1.gender,player1.college);
		printf("%d\t%d\t%d\t\n",player1.pro[0].code,player1.pro[1].code,player1.pro[2].code);
		printf("����%d\n",++count);
	}
	if(i==0&&count==25){
     fp2=fp;
	}
	fp2++;
	while ((i=fread(&player1, sizeof(player), 1, fp2)) != NULL)
	{

		printf("%d\t%s\t%s\t%s\t",player1.playerCode,player1.playerName,player1.gender,player1.college);
		printf("%d\t%d\t%d\t\n",player1.pro[0].code,player1.pro[1].code,player1.pro[2].code);
		printf("����%d\n",++count);
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
	printf("���\t����\t�Ա�\tѧԺ\n");
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
	printf("��ȷ�����Ƿ�Ҫִ�д˴��޸ġ�ɾ������YES(1)/NO(0): ");
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
	fp = fopen("������Ŀ��.txt", "r");
	while (fread(&pro,sizeof(project),1,fp)!=NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("��ѡ��ɾ����Ϣ����ţ�");
	scanf("%d", &modifyCode);
	if (did_delete_or_modify())
	{
		for (int i = modifyCode-1; i < proCount; i++)
		{
			proArr[i] = proArr[i + 1];
		}
		proCount -= 1;
	}
	fp = fopen("������Ŀ��.txt", "w");
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
		fp = fopen("������Ŀ��.txt", "r");
		while (fread(&pro, sizeof(project), 1, fp) != NULL)
		{
			proArr[proCount] = pro;
			proCount++;
		}
		fclose(fp);
		printf("������Ҫ�޸ĵ���Ŀ�ı��:");
		scanf("%d", &modifyProCode);
		printf("��ѡ��Ҫ�޸ĵ�ѡ�\n1. ��Ŀ����\n2. ��������\n3. ������λ\n4. ÿ������\n5. ÿ��ʱ��\n");
		scanf("%d", &modifyCode);
		printf("������ĺ����ݣ�");
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
		fp = fopen("������Ŀ��.txt", "w");
		fwrite(proArr, sizeof(project), proCount, fp);
		fclose(fp);
}
void print_sp(){//��ӡ�����пɹ�ѡ��ı�����Ŀ

	project pro[100];
	//�������б�����Ŀ
	//���б������صص��Ӧ������£�caochang-101;pool-102;shachi-103;kongdi1-104;kongdi2-105; kongdi3-106;
	//�˶���Ŀ1 ��run100
	strcpy(pro[1].name,"run100");
	pro[1].code=201;
	strcpy(pro[1].place,"caochang");
	pro[1].placeCode=101;
	strcpy(pro[1].unitOfMeasureMent,"s") ;
	pro[1].numberOfPlayerPerGroup=4;
	pro[1].timeOfGroup=100;
	//�˶���Ŀ2 :run200
	strcpy(pro[2].name,"run200");
	pro[2].code=202;
	strcpy(pro[2].place,"caochang");
	pro[2].placeCode=101;
	strcpy(pro[2].unitOfMeasureMent,"s") ;
	pro[2].numberOfPlayerPerGroup=4;
	pro[2].timeOfGroup=200;
	//�˶���Ŀ3��run400
	strcpy(pro[3].name,"run400");
	pro[3].code=203;
	strcpy(pro[3].place,"caochang");
	pro[3].placeCode=101;
	strcpy(pro[3].unitOfMeasureMent,"s") ;
	pro[3].numberOfPlayerPerGroup=4;
	pro[3].timeOfGroup=400;
	//�˶���Ŀ4��run800
	strcpy(pro[4].name,"run800");
	pro[4].code=204;
	strcpy(pro[4].place,"caochang");
	pro[4].placeCode=101;
	strcpy(pro[4].unitOfMeasureMent,"s") ;
	pro[4].numberOfPlayerPerGroup=4;
	pro[4].timeOfGroup=800;
	//��4����Ŀ5��run1000
	strcpy(pro[5].name,"run1000");
	pro[5].code=205;
	strcpy(pro[5].place,"caochang");
	pro[5].placeCode=101;
	strcpy(pro[5].unitOfMeasureMent,"s") ;
	pro[5].numberOfPlayerPerGroup=4;
	pro[5].timeOfGroup=1000;
	//�˶���Ŀ6��run2000
	strcpy(pro[6].name,"run2000");
	pro[6].code=206;
	strcpy(pro[6].place,"caochang");
	pro[6].placeCode=101;
	strcpy(pro[6].unitOfMeasureMent,"s") ;
	pro[6].numberOfPlayerPerGroup=4;
	pro[6].timeOfGroup=2000;
	//�˶���Ŀ7��run5000
	strcpy(pro[7].name,"run5000");
	pro[7].code=207;
	strcpy(pro[7].place,"caochang");
	pro[7].placeCode=101;
	strcpy(pro[7].unitOfMeasureMent,"s") ;
	pro[7].numberOfPlayerPerGroup=4;
	pro[7].timeOfGroup=5000;
	//�˶���Ŀ8��run4*100
	strcpy(pro[8].name,"run4*100");
	pro[8].code=208;
	strcpy(pro[8].place,"caochang");
	pro[8].placeCode=101;
	strcpy(pro[8].unitOfMeasureMent,"s") ;
	pro[8].numberOfPlayerPerGroup=4;
	pro[8].timeOfGroup=400;
	//�˶���Ŀ9:run4*200
	strcpy(pro[9].name,"run4*200");
	pro[9].code=209;
	strcpy(pro[9].place,"caochang");
	pro[9].placeCode=101;
	strcpy(pro[9].unitOfMeasureMent,"s") ;
	pro[9].numberOfPlayerPerGroup=4;
	pro[9].timeOfGroup=800;
	//�˶���Ŀ10�� swim100
	strcpy(pro[10].name,"swim100");
	pro[10].code=210;
	strcpy(pro[10].place,"pool");
	pro[10].placeCode=102;
	strcpy(pro[10].unitOfMeasureMent,"s") ;
	pro[10].numberOfPlayerPerGroup=4;
	pro[10].timeOfGroup=100;
	//�˶���Ŀ11��swim200
	strcpy(pro[11].name,"swim200");
	pro[11].code=211;
	strcpy(pro[11].place,"pool");
	pro[11].placeCode=102;
	strcpy(pro[11].unitOfMeasureMent,"s") ;
	pro[11].numberOfPlayerPerGroup=4;
	pro[11].timeOfGroup=200;
	//�˶���Ŀ12��swim400
	strcpy(pro[12].name,"swim400");
	pro[12].code=212;
	strcpy(pro[12].place,"pool");
	pro[12].placeCode=102;
	strcpy(pro[12].unitOfMeasureMent,"s") ;
	pro[12].numberOfPlayerPerGroup=4;
	pro[12].timeOfGroup=400;
	//�˶���Ŀ13��swim800
	strcpy(pro[13].name,"swim800");
	pro[13].code=213;
	strcpy(pro[13].place,"pool");
	pro[13].placeCode=102;
	strcpy(pro[13].unitOfMeasureMent,"s") ;
	pro[13].numberOfPlayerPerGroup=4;
	pro[13].timeOfGroup=800;
	//�˶���Ŀ14��swim1000
	strcpy(pro[14].name,"swim1000");
	pro[14].code=214;
	strcpy(pro[14].place,"pool");
	pro[14].placeCode=102;
	strcpy(pro[14].unitOfMeasureMent,"s") ;
	pro[14].numberOfPlayerPerGroup=4;
	pro[14].timeOfGroup=1000;
	//�˶���Ŀ15��swim4*100
	strcpy(pro[15].name,"swim4*100 ");
	pro[15].code=215;
	strcpy(pro[15].place,"pool");
	pro[15].placeCode=102;
	strcpy(pro[15].unitOfMeasureMent,"s") ;
	pro[15].numberOfPlayerPerGroup=4;
	pro[15].timeOfGroup=400;
	//�˶���Ŀ16��jumplong
	strcpy(pro[16].name,"jumplong");
	pro[16].code=216;
	strcpy(pro[16].place,"shachi");
	pro[16].placeCode=103;
	strcpy(pro[16].unitOfMeasureMent,"m") ;
	pro[16].numberOfPlayerPerGroup=4;
	pro[16].timeOfGroup=100;
	//�˶���Ŀ17��jumphigh
	strcpy(pro[17].name,"jumphigh");
	pro[17].code=217;
	strcpy(pro[17].place,"kongdi1");
	pro[17].placeCode=104;
	strcpy(pro[17].unitOfMeasureMent,"m") ;
	pro[17].numberOfPlayerPerGroup=4;
	pro[17].timeOfGroup=100;
	//�˶���Ŀ18��zhibiaoqiang
	strcpy(pro[18].name,"zhibiaoqiang");
	pro[18].code=218;
	strcpy(pro[18].place,"kongdi2");
	pro[18].placeCode=105;
	strcpy(pro[18].unitOfMeasureMent,"m") ;
	pro[18].numberOfPlayerPerGroup=4;
	pro[18].timeOfGroup=100;
	//�˶���Ŀ19��zhiqianqiu
	strcpy(pro[19].name,"zhiqianqiu");
	pro[19].code=219;
	strcpy(pro[19].place,"kongdi3");
	pro[19].placeCode=106;
	strcpy(pro[19].unitOfMeasureMent,"m") ;
	pro[19].numberOfPlayerPerGroup=4;
	pro[19].timeOfGroup=100;
	//


	printf("��Ŀ��\t\t���\t�ص�\t\t���ر��\t��λ\tÿ������\t����ʱ��\n");
	int i;
	for(i=1;i<20;i++){
		printf("%8s\t%d\t%8s\t%d\t\t%s\t%d\t\t%d\n",pro[i].name,pro[i].code,pro[i].place,pro[i].placeCode,pro[i].unitOfMeasureMent,pro[i].numberOfPlayerPerGroup,pro[i].timeOfGroup);
	}
}

void add_project()
{
	project pro[100];
	//�������б�����Ŀ
	//���б������صص��Ӧ������£�caochang-101;pool-102;shachi-103;kongdi1-104;kongdi2-105; kongdi3-106;
	//�˶���Ŀ1 ��run100
	strcpy(pro[1].name,"run100");
	pro[1].code=201;
	strcpy(pro[1].place,"caochang");
	pro[1].placeCode=101;
	strcpy(pro[1].unitOfMeasureMent,"s") ;
	pro[1].numberOfPlayerPerGroup=4;
	pro[1].timeOfGroup=100;
	//�˶���Ŀ2 :run200
	strcpy(pro[2].name,"run200");
	pro[2].code=202;
	strcpy(pro[2].place,"caochang");
	pro[2].placeCode=101;
	strcpy(pro[2].unitOfMeasureMent,"s") ;
	pro[2].numberOfPlayerPerGroup=4;
	pro[2].timeOfGroup=200;
	//�˶���Ŀ3��run400
	strcpy(pro[3].name,"run400");
	pro[3].code=203;
	strcpy(pro[3].place,"caochang");
	pro[3].placeCode=101;
	strcpy(pro[3].unitOfMeasureMent,"s") ;
	pro[3].numberOfPlayerPerGroup=4;
	pro[3].timeOfGroup=400;
	//�˶���Ŀ4��run800
	strcpy(pro[4].name,"run800");
	pro[4].code=204;
	strcpy(pro[4].place,"caochang");
	pro[4].placeCode=101;
	strcpy(pro[4].unitOfMeasureMent,"s") ;
	pro[4].numberOfPlayerPerGroup=4;
	pro[4].timeOfGroup=800;
	//��4����Ŀ5��run1000
	strcpy(pro[5].name,"run1000");
	pro[5].code=205;
	strcpy(pro[5].place,"caochang");
	pro[5].placeCode=101;
	strcpy(pro[5].unitOfMeasureMent,"s") ;
	pro[5].numberOfPlayerPerGroup=4;
	pro[5].timeOfGroup=1000;
	//�˶���Ŀ6��run2000
	strcpy(pro[6].name,"run2000");
	pro[6].code=206;
	strcpy(pro[6].place,"caochang");
	pro[6].placeCode=101;
	strcpy(pro[6].unitOfMeasureMent,"s") ;
	pro[6].numberOfPlayerPerGroup=4;
	pro[6].timeOfGroup=2000;
	//�˶���Ŀ7��run5000
	strcpy(pro[7].name,"run5000");
	pro[7].code=207;
	strcpy(pro[7].place,"caochang");
	pro[7].placeCode=101;
	strcpy(pro[7].unitOfMeasureMent,"s") ;
	pro[7].numberOfPlayerPerGroup=4;
	pro[7].timeOfGroup=5000;
	//�˶���Ŀ8��run4*100
	strcpy(pro[8].name,"run4*100");
	pro[8].code=208;
	strcpy(pro[8].place,"caochang");
	pro[8].placeCode=101;
	strcpy(pro[8].unitOfMeasureMent,"s") ;
	pro[8].numberOfPlayerPerGroup=4;
	pro[8].timeOfGroup=400;
	//�˶���Ŀ9:run4*200
	strcpy(pro[9].name,"run4*200");
	pro[9].code=209;
	strcpy(pro[9].place,"caochang");
	pro[9].placeCode=101;
	strcpy(pro[9].unitOfMeasureMent,"s") ;
	pro[9].numberOfPlayerPerGroup=4;
	pro[9].timeOfGroup=800;
	//�˶���Ŀ10�� swim100
	strcpy(pro[10].name,"swim100");
	pro[10].code=210;
	strcpy(pro[10].place,"pool");
	pro[10].placeCode=102;
	strcpy(pro[10].unitOfMeasureMent,"s") ;
	pro[10].numberOfPlayerPerGroup=4;
	pro[10].timeOfGroup=100;
	//�˶���Ŀ11��swim200
	strcpy(pro[11].name,"swim200");
	pro[11].code=211;
	strcpy(pro[11].place,"pool");
	pro[11].placeCode=102;
	strcpy(pro[11].unitOfMeasureMent,"s") ;
	pro[11].numberOfPlayerPerGroup=4;
	pro[11].timeOfGroup=200;
	//�˶���Ŀ12��swim400
	strcpy(pro[12].name,"swim400");
	pro[12].code=212;
	strcpy(pro[12].place,"pool");
	pro[12].placeCode=102;
	strcpy(pro[12].unitOfMeasureMent,"s") ;
	pro[12].numberOfPlayerPerGroup=4;
	pro[12].timeOfGroup=400;
	//�˶���Ŀ13��swim800
	strcpy(pro[13].name,"swim800");
	pro[13].code=213;
	strcpy(pro[13].place,"pool");
	pro[13].placeCode=102;
	strcpy(pro[13].unitOfMeasureMent,"s") ;
	pro[13].numberOfPlayerPerGroup=4;
	pro[13].timeOfGroup=800;
	//�˶���Ŀ14��swim1000
	strcpy(pro[14].name,"swim1000");
	pro[14].code=214;
	strcpy(pro[14].place,"pool");
	pro[14].placeCode=102;
	strcpy(pro[14].unitOfMeasureMent,"s") ;
	pro[14].numberOfPlayerPerGroup=4;
	pro[14].timeOfGroup=1000;
	//�˶���Ŀ15��swim4*100
	strcpy(pro[15].name,"swim4*100 ");
	pro[15].code=215;
	strcpy(pro[15].place,"pool");
	pro[15].placeCode=102;
	strcpy(pro[15].unitOfMeasureMent,"s") ;
	pro[15].numberOfPlayerPerGroup=4;
	pro[15].timeOfGroup=400;
	//�˶���Ŀ16��jumplong
	strcpy(pro[16].name,"jumplong");
	pro[16].code=216;
	strcpy(pro[16].place,"shachi");
	pro[16].placeCode=103;
	strcpy(pro[16].unitOfMeasureMent,"m") ;
	pro[16].numberOfPlayerPerGroup=4;
	pro[16].timeOfGroup=100;
	//�˶���Ŀ17��jumphigh
	strcpy(pro[17].name,"jumphigh");
	pro[17].code=217;
	strcpy(pro[17].place,"kongdi1");
	pro[17].placeCode=104;
	strcpy(pro[17].unitOfMeasureMent,"m") ;
	pro[17].numberOfPlayerPerGroup=4;
	pro[17].timeOfGroup=100;
	//�˶���Ŀ18��zhibiaoqiang
	strcpy(pro[18].name,"zhibiaoqiang");
	pro[18].code=218;
	strcpy(pro[18].place,"kongdi2");
	pro[18].placeCode=105;
	strcpy(pro[18].unitOfMeasureMent,"m") ;
	pro[18].numberOfPlayerPerGroup=4;
	pro[18].timeOfGroup=100;
	//�˶���Ŀ19��zhiqianqiu
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
	if ((fp = fopen("������Ŀ��.txt", "a")) == NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		do
		{
		    system("cls");
			print_sp();
			printf("������Ҫ�����Ŀ�ı�ţ�");
			int j;
			scanf("%d",&j);
			while(j<=200||j>219){//��������ı��������Χ201-219֮��
				scanf("%d",&j);
			}
			pro1.code=j;
			int i =pro1.code-200;//�õ�������±�
			strcpy(pro1.name,pro[i].name);
			strcpy(pro1.place,pro[i].place);
			pro1.placeCode=pro[i].placeCode;
			strcpy(pro1.unitOfMeasureMent,pro[i].unitOfMeasureMent);
			pro1.numberOfPlayerPerGroup=pro[i].numberOfPlayerPerGroup;
			pro1.timeOfGroup=pro[i].timeOfGroup;
		/*
			printf("��������Ŀ���ƣ�");
			scanf("%s", &pro.name);
			printf("��������Ŀ��ţ�");
			scanf("%d", &pro.code);
			printf("��������Ŀ���أ�");
			scanf("%s", &pro.place);
			printf("�����볡�ر�ţ�");
			scanf("%d", &pro.placeCode);
			printf("�����������λ��");
			scanf("%s", &pro.unitOfMeasureMent);
			printf("������ÿ��������");
			scanf("%d", &pro.numberOfPlayerPerGroup);
			printf("������ÿ��ʱ�䣺");
			scanf("%d", &pro.timeOfGroup);
		*/
			if(checkChongfu(j)){
				printf("�ñ�����Ŀ�Ѿ�¼��ϵͳ�ˣ�������Ч\n");
			}
			else{
				printf("�ñ�����Ŀ��δ¼�룬���ڽ���¼��...���Ժ�...\n");
				fwrite(&pro1, sizeof(project), 1, fp);
				printf("¼��ɹ�!\n");
			}

			printf("�Ƿ�Ҫ����¼��������Ŀ��YES(1)/NO(0)");
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
	fp = fopen("�˶�Ա������.txt", "r");
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
	//�������е�ѧԺ����Ժ
	/*
	typedef struct{
	char c[20];//ѧԺ�����ַ�����ʾ
	int cd;// ѧԺ�ı��
	}collegeCode;//�ýṹ��������¼ѧԺ������
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
	//�������


	if ((fp = fopen("�˶�Ա������.txt", "a")) == NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		playerCode = count_playerCode();
		player1.playerCode = playerCode;
		printf("����%d���˶�Ա����!\n",playerCode-1);
		printf("������������֣�");
		scanf("%s", &player1.playerName);
		printf("�ɹ�ѡ���ѧ���飩Ժ�����Լ���Ӧ�ı�����£�\n");
		int n;
		for(n=1;n<=10;n++){
			printf("%d %s\n",cc[n].cd,cc[n].c);
		}
		printf("���������ѧԺ���룺");
		int ii;
		scanf("%d",&ii);
		int j=ii-300;//�õ������±�
		strcpy(player1.college,cc[j].c);
		printf("ѧԺ����Ϊ%d=%s\n",ii,player1.college);
		//scanf("%s", &player1.college);
		printf("����������Ա�(1.��������/2����Ů��)��");
		int k;
		scanf("%d",&k);
		while(k!=1&&k!=2){
			printf("�����������������룺\n");
			printf("����������Ա�(1.��������/2����Ů��)��");
			scanf("%d",&k);
		}
		if(k==1){
			strcpy(player1.gender,"male");
		}
		else if(k==2){
			strcpy(player1.gender,"female");
		}
		else{
			printf("�����ֵ�����ƴ���\n");
		}
		//scanf("%s", &player1.gender);
		printf("��������Ҫ�μӵ���Ŀ����(������3��)��");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "��");
		}
		printf("����Ա�ѷ����ı�����Ŀ�����£�\n");
		printf_pro_info();
		int ProNum[3]={0,0,0};
		for (int i = 0;i < numberOfJoin;i++)
		{

			/*
			printf("��������Ŀ���ƣ�");
			scanf("%s", &player1.pro[i].name);
			*/
            //ע�����������￪ʼ�Ķ��ġ���������������������һ������������Ƿ���ͬ

            int is_exist=0;
			printf("�������%d����Ŀ�ı�ţ�",i+1);
			scanf("%d", &player1.pro[i].code);
			while(isIn(player1.pro[i].code)!=1){
				printf("��������˶���Ŀ����Աû�з������������Ѿ���������Ŀ���\n");
				printf("�����������%d����Ŀ�ı�ţ�",i+1);
				scanf("%d", &player1.pro[i].code);
			}
			while(player1.pro[i].code==ProNum[0]||player1.pro[i].code==ProNum[1]||player1.pro[i].code==ProNum[2])
            {
                printf("�����ظ��������Ŀ,��������һ����Ŀ���\n");
                printf("�����������%d����Ŀ�ı�ţ�",i+1);
				scanf("%d", &player1.pro[i].code);
            }
            ProNum[i]=player1.pro[i].code;
			printf("������ȷ��ϵͳ����¼��\n");
			int l =player1.pro[i].code-200;//�õ�����ֵ
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
				default:printf("����ı������\n");
			}
		}
		int is_success=fwrite(&player1, sizeof(player), 1, fp);
		printf("�Ƿ�ɹ�%d\n",is_success);
		//system("pause");
	}
	fclose(fp);
	printf("��ı��Ϊ%d\n��(1)�˳�:", playerCode);
	scanf("%d", &s);

}
void clean_players()
{
    int playerCode = 0;
	FILE *fp;
	player player1;
	fp = fopen("�˶�Ա������.txt", "r");
	while (fread(&player1, sizeof(player), 1, fp) != NULL)
	{
	   // printf("%d",playerCode);
		playerCode++;
	}
	fclose(fp);
	printf("�ָ�Ϊ%d����\n",playerCode);
	player *playerArr=(player*)malloc((sizeof(player)*playerCode));
	fp=fopen("�˶�Ա������.txt","r");
	fread(playerArr,sizeof(player),playerCode,fp);
	fclose(fp);
	fp=fopen("�˶�Ա������.txt","w");
	printf("�ɹ�д�����ٸ�%d\n",fwrite(playerArr,sizeof(player),playerCode,fp));
	fclose(fp);
	free(playerArr);

	//return playerCode;

}
void create_player_of_project()
{
	char *fileName;		//������ʱ���ļ���
	FILE *fpOfPro;			//ָ�������Ŀ����ļ�ָ�����
	FILE *fpOfPlayer;		//ָ���˶�Ա��������ļ�ָ�����
	FILE *tempFile;		//��ʱ�ļ�ָ�����
	int proCode;			//��Ŀ���
	project pro;
	player player1;
	fpOfPro = fopen("������Ŀ��.txt", "r");
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proCode = pro.code;
		fileName = string_link(pro.name, "������.txt");
		tempFile = fopen(fileName, "w");
		fpOfPlayer = fopen("�˶�Ա������.txt", "r");
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
	char *fileName;			//��ʱ�ļ���
	FILE *fpOfPro;			//ָ�򡰱�����Ŀ����ָ�����
	FILE *fpOfPlayerList;	//ָ����Ŀ�˶�Ա��������ָ�����
	FILE *fpOfTemp;			//��ʱ�ļ�ָ�����
	project pro;
	player player1;
	time_take ti;
	int baseTime = 0;			//ÿ�黨��ʱ�䣬��������λʱ��
	int count;
	fpOfPro = fopen("������Ŀ��.txt", "r");
	fpOfTemp = fopen("��Ŀʱ������.txt", "w");
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		fileName = string_link(pro.name, "������.txt");
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
	FILE *fpOfPro;													//ָ�򡰱�����Ŀ����ָ�����
	FILE *fpOfPlayerListA, *fpOfPlayerListB;			//ָ����Ŀ�˶�Ա��������ָ�����
	FILE *fpOfTemp;												//������ͻ��ʹ�õ�ָ�����
	int countOfPro = 0;
	project proArr[PROJECTMAX], pro;					//proArr���ڴ洢���е���Ŀ
	player player1, playerArrA[PLAYERMAX], playerArrB[PLAYERMAX];
	conflict con;
	fpOfPro = fopen("������Ŀ��.txt", "r");
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proArr[countOfPro] = pro;
		countOfPro++;
	}
	fclose(fpOfPro);
	for (int i = 0;i<countOfPro;i++)
	{
		fileName = string_link(proArr[i].name, "��ͻ��.txt");
		fileName1 = string_link(proArr[i].name, "������.txt");
		fpOfTemp = fopen(fileName, "w");
		//printf("%s\n", proArr[i].name);
		fpOfPlayerListA = fopen(fileName1, "r");
		int countOfPlayerA = 0;
		//��Ҫ���Ƚϵ��˶�Ա�������ݴ洢��A��
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
				fileName2 = string_link(proArr[j].name, "������.txt");
				fpOfPlayerListB = fopen(fileName2, "r");
				//��Ҫ�Ƚϵ��˶�Ա�������ݴ洢��B��
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
					/*����˶���Ŀ�ĳ�����ͬ�����߲�ͬ����Ŀ���������к�����ͬ���˶�Ա
					��˵����������Ŀʱ��ͻ��*/
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
	FILE *fpOfTemp;											//�򿪻��ߴ�����Ŀʱ�������ָ�����
	FILE *fpOfPro;												//ָ�������Ŀ���ָ�����
	FILE *fpOfCon;												//ָ���ͻ���ָ�����
	char *fileName;												//�򿪸�����Ŀ�ĳ�ͻ�����ʱָ�����
	int	 countOfPro = 0;									//��Ŀ����
	int	timeOfSegment = 0;								//ʱ��κ���
	int	 count = 0;
	int    weipai = 0;											//δ��ʱ��κŵ���Ŀ����
	project pro, proArr[PROJECTMAX];					//�洢��Ŀ�����ݵ�����
	conflict con, conArr[PROJECTMAX];				//�洢��ͻ�����ݵ�����
	distribution distriArr[PROJECTMAX];				//�洢ʱ���������ݵ�����
	fpOfPro = fopen("������Ŀ��.txt", "r");
	//��ʼ��ʱ������
	while (fread(&pro, sizeof(project), 1, fpOfPro) != NULL)
	{
		proArr[countOfPro] = pro;
		countOfPro++;
		weipai++;
	}
	fclose(fpOfPro);
	//��ʼ��ʱ������Ŀ��ͻ�ȶԱ������
	for (int i = 0;i<countOfPro;i++)
	{
		distriArr[i].projectCode = proArr[i].code;
		strcpy(distriArr[i].projectName, proArr[i].name);
		distriArr[i].timeCode = 0;
		conArr[i].projectCode = proArr[i].code;
		strcpy(conArr[i].projectName, proArr[i].name);
		conArr[i].isConflict = 0;
	}
	fpOfTemp = fopen("��Ŀʱ������.txt", "w");
	//��δ����Ŀ��������0ʱ
	while (weipai>0)
	{
		if (distriArr[count].timeCode == 0)//�����Ŀ��ʱ��κ�Ϊ0������Ŀ��ʱ��κŻ�û�з���
		{
			timeOfSegment++;
			distriArr[count].timeCode = timeOfSegment;
			weipai--;
			while (count<countOfPro)
			{
			here:fileName = string_link(distriArr[count].projectName, "��ͻ��.txt");
				//printf("%s\n", fileName);
				fpOfCon = fopen(fileName, "r");
				//���³�ͻ�ȶԱ�
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
void enter_results()//¼�������Ŀ�ĳɼ�
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
	fp = fopen("������Ŀ��.txt", "r");
	fread(pro, sizeof(project), count, fp);
	fclose(fp);
	do
	{
	   // system("cls");
	   // printf_pro_data(1);
		printf("������Ҫ¼��������Ŀ��ţ�");
		scanf("%d", &choice);
		choice-=200;
		file_name = string_link(pro[choice - 1].name, "������.txt");
		count = printf_player_score_data(file_name);
		fp = fopen(file_name, "r");
		fread(playerArr, sizeof(player), count, fp);
		fclose(fp);
		/*for (int i = 0; i < 2; i++)
		{
		printf("%d", playerArr[i].playerCode);
		}*/
		printf("\n�����������˶�Ա�ĳɼ�:\n");
		for (int i = 0; i <count; i++)
		{
			printf("��%d���˶�Ա%s�ĳɼ�:", i + 1,playerArr[i].playerName);
			scanf("%f", &score);
            score_arr[i].sc = score;
            strcpy(score_arr[i].name, playerArr[i].playerName);
            score_arr[i].player_code = playerArr[i].playerCode;

		}//ֻ�Ǵ��г�ȡ���˶�Ա�ı��룬���֣��ɼ�����һ���ļ����档
		file_name = string_link(pro[choice - 1].name, "�ɼ���.txt");
		fp = fopen(file_name, "w");
		fwrite(score_arr, sizeof(score_rank), count, fp);
		fclose(fp);
		printf("�˳���YES(1)(0)");
		scanf("%d", &is_exit);
	} while (!is_exit);

}

void print_all_result()
{
    FILE *fpo;
    fpo=fopen("������Ŀ��.txt","r");
    project pro[PROJECTMAX];
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);
    for(int i=0;i<count_pro;i++)
    {
        char FileName[20];
        strcpy(FileName,string_link(pro[i].name,"�ɼ���.txt"));
        FILE *fre=fopen(FileName,"r");
        score_rank ScoreArr[PLAYERMAX];
        int count_re=fread(ScoreArr,sizeof(score_rank),PLAYERMAX,fre);
        printf("%s��Ŀ�ĳɼ����£�\n",pro[i].name);
        for(int j=0;j<count_re;j++)
            printf("��%d���˱��%d������%s�ĳɼ���%f\n",j+1,ScoreArr[j].player_code,ScoreArr[j].name,ScoreArr[j].sc);

        fclose(fre);
    }
    fclose(fpo);
}
void rank(char *file_name,int n)//��ӡ����һ��������Ŀ������������ļ���file_name��n= 1��ʾ�����ܲ�����Ӿ�������n��=1��Ͷ��ǹ��Ͷ�������Ǵ��� ��������
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
	//ѡ������
	for (int i = 0;i <= count - 2;i++)
	{
		min = i;
		for (int j = i+1; j <= count-1; j++)
		{
			if (arr[j].sc < arr[min].sc)//��������
				min = j;
		}
		b[0] = arr[i];
		arr[i] = arr[min];
		arr[min] = b[0];
	}
	//��ӡ��Ϣ
	printf("����\t����\t�ɼ�\n");
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
	//printf("�밴���������");
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
	printf("��������ı�ţ�");
	scanf("%d", &player_code);

	fp = fopen("�˶�Ա������.txt", "r");
	while ((fread(&p, sizeof(player), 1, fp)) != NULL)
	{
		if (p.playerCode == player_code)
		{
			printf("��ӭ%s\n",p.playerName);
			printf("����������Ŀ�ɼ�����:\n��Ŀ����\t��Ŀ�ɼ�\n");
			for (int i = 0; i < 3; i++)
			{
				if (strcmp("��", p.pro[i].name) != 0)
				{
					fileName = string_link(p.pro[i].name, "�ɼ���.txt");
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
	printf("����1���˳���");
	scanf("%d", &is_exit);
}
void	query_dirtribution()
{
	FILE *fp;
	distribution distri;
	int choice;
	if (fp = fopen("��Ŀʱ������.txt", "r"))
	{
		printf("��Ŀ���\t��Ŀ����\tʱ��κ�\n");
		while ((fread(&distri, sizeof(distribution), 1, fp)!=NULL))
		{
			printf("%8d\t%8s\t%8d\n", distri.projectCode,distri.projectName,distri.timeCode);
		}
	}
	printf("��1�˳���");
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
		printf("\t\t\t\t\t1.��Ŀ����\n");
		printf("\t\t\t\t\t2.��Ŀ�޸�\n");
		printf("\t\t\t\t\t3.��Ŀɾ��\n");
		printf("\t\t\t\t\t4.���¼��\n");
		printf("\t\t\t\t\t5.��������\n");
		printf("\t\t\t\t\t6.�鿴��¼�����Ŀ\n");
		printf("\t\t\t\t\t7.�����ϼ�\n");
		bound('=', 30);
		printf("������ѡ�");
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
		 	printf("������Զ�������һ�˵�...\n");
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
	printf("�˺�:");
	scanf("%s",real_account);
	printf("����:");
	for (i = 0;i<10 && ((real_password[i] = _getch()) != 13);i++)
		putchar('*');
	putchar('\n');
	real_password[i] = '\0';
	if (strcmp(real_account, account) == 0 && strcmp(real_password, password) == 0)
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

void infochaxun(){
	printf("��ѡ���ѯ�ķ�ʽ��1.��������Ŀ������2�����˳ɼ���ѯ��3.�鿴ѧԺ���ֺ�����");
	int choice;
	while((scanf("%d",&choice),choice!=1&&choice!=2&&choice!=3))
	printf("����������������룺\n");
	if(choice==1){
        int is_exit;
		do
        {
            system("cls");
            printf_pro_info();
            char s[20],ss[20];
            strcpy(s,"");//��仰�д���
            printf("��������Ҫ��ѯ�ı�����Ŀ�ı�ţ�");
            int i;
            scanf("%d", &i);
		/*if(!isIn(i)){
			printf("�ñ�����Ŀû�о��У�����¼��ɼ�\n");
			printf("������������Ҫ��ѯ�ı�ɨ��Ŀ�ı�ţ�");
			scanf("%d", &i);
		}*///����ж���������û������ģ���Ϊ���isin���ж��Ƿ���ڣ���Ҫ��ˮ���˵�ö�ˮ���
		//printf("������ȷ��ϵͳ����¼��\n");
            int l =i-200;//�õ�����ֵ
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
                default:printf("����ı������\n");
            }
            strcpy(ss,string_link(s, "�ɼ���.txt"));
            rank(ss,n);
            printf("�Ƿ�����鿴������Ŀ������:yes(1)/no(0)\n");

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
int read_state(char *FileName)//���ؽ׶�����
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
void write_state(char *FileName,int state)//��һ���׶εĴ�������д�����׶�.txt������ļ�������
{
    FILE *fp;
    fp=fopen(FileName,"w");
    fprintf(fp,"%d",state);
    //
    printf("д��%d�ɹ�\n",state);
    fclose(fp);
    //return 0;

}


int jieduan(){
	//1����Ա¼�������Ŀ�Ľ׶Σ��ý׶ν�ֹ�˶�Ա������
	//2�˶�Ա�����ڼ� �������˶�Ա�������ܣ�
	//3��������ᣬȷ�ϱ������̰��ţ��ý׶ν�ֹ�˶�Ա�ٱ���������ֻ������һ������ἴ�ɣ�
	//4����������¼��ɼ��׶Σ��ý׶βŽ�����ѯ�ɼ����ܣ�
	int i,j,k,l;
	i=read_state("��һ״̬��.txt");
	j=read_state("�ڶ�״̬��.txt");
	k=read_state("����״̬��.txt");
	l=read_state("����״̬��.txt");
	printf("i=%d j=%d k=%d l=%d\n",i,j,k,l);
	if(l==1){//Ϊ���Ľ׶�
		return 4;
	}
	else if(k==1){//Ϊ�����׶�
		return 3;
	}
	else if(j==1){//Ϊ�ڶ��׶�
		return 2;
	}
	else if(i==1){//Ϊ��һ�׶�
		return 1;
	}
	else return 0;//���������
}
/*
void main_menu()//����Ա���˵�
{

	int choice;
	//int temp;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\t\t\t\t\t1.��Ŀ����\n");
		printf("\t\t\t\t\t2.��Ŀ�޸�\n");
		printf("\t\t\t\t\t3.��Ŀɾ��\n");
		printf("\t\t\t\t\t4.���¼��\n");
		printf("\t\t\t\t\t5.��������\n");
		printf("\t\t\t\t\t6.�鿴��¼�����Ŀ\n");
		printf("\t\t\t\t\t7.�����ϼ�\n");
		bound('=', 30);
		printf("������ѡ�");
		scanf("%d", &choice);
		int temp;
		temp=jieduan();
		switch (choice)
		{
		case 1:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				add_project();
			}
			else{
				printf("��ǰʱ���Ѿ��������ٷ���������Ŀ\n");
			}
			//
			break;
		case 2:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				modify_project();
			}
			else{
				printf("��ǰʱ���Ѿ����������޸ı�����Ŀ\n");
			}
			//
			//modify_project();
			break;
		case 3:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				delete_project();
			}
			else{
				printf("��ǰʱ���Ѿ���������ɾ��������Ŀ\n");
			}
			//

			break;
		case 4:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==3||temp==4){
				enter_results();//¼��ɼ�
				//������Ľ׶Σ��Դ˽����˶�Ա��ѯ�ɼ�����
				write_state("����״̬��.txt",1);
				printf("¼����ɡ�����\n") ;
			}
			else{
				printf("��ǰʱ�䲻����¼�������Ŀ�ɼ�\n");
			}
			//
			//"����״̬��.txt"
			//enter_results();
			break;
		case 5:
			system("cls");
			//create_player_of_project();
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==2){
				printf("�������д˲������˶�Ա�����ٿ��Ա��������������Աȷ���Ƿ�Ҫ����ִ�д˲�����(1.��/2��)") ;
				int c;
				scanf("%d",c);
				if(c==1){
					printf("������������ᣬ���Ժ󡣡���\n");
					//���������
					create_conflict_of_project();
					create_time_of_distribution();
					query_dirtribution();
					//
					printf("������Ѿ��������,�����ٽ����˶�Ա��������������������׶�\n");
					//�޸Ĳ���ʹ�������ȵ������׶�
					write_state("����״̬��.txt",1);

				}
				else{
					printf("����ȡ��������������\n");
				}
			}
			else{
				printf("��ǰʱ���Ѿ����������������\n");
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
		 	printf("������Զ�������һ�˵�...\n");
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
		printf("\t\t\t\t\t�˶������ϵͳ\n");
		bound('=',30);
		printf("\t\t\t\t\t1.����Ա��¼\n\t\t\t\t\t2.�˶�Ա����\n\t\t\t\t\t3.���˳ɼ���ѯ\n\t\t\t\t\t4.��Ϣ��ѯ\n\t\t\t\t\t5.�˳�ϵͳ\n");
		bound('=', 30);
		printf("��������ѡ��:");
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
	printf("��ǰ�׶�Ϊ��%d\n",j);
	printf("�׶�˵�����£�\n");
	printf("1����Ա¼�������Ŀ�Ľ׶Σ��ý׶ν�ֹ�˶�Ա������\n");
	printf("2�˶�Ա�����ڼ� �������˶�Ա�������ܣ�\n");
	printf("3��������ᣬȷ�ϱ������̰��ţ��ý׶ν�ֹ�˶�Ա�ٱ���������ֻ������һ������ἴ�ɣ�\n");
	printf("4����������¼��ɼ��׶Σ��ý׶βŽ�����ѯ�ɼ����ܣ�\n");
	printf("��ѡ����Ҫ����Ľ׶Σ�");
	scanf("%d",&i);
	if(i==1){
		write_state("��һ״̬��.txt",1);
		write_state("�ڶ�״̬��.txt",0);
		write_state("����״̬��.txt",0);
		write_state("����״̬��.txt",0);

	}
	else if(i==2){
		write_state("��һ״̬��.txt",1);
		write_state("�ڶ�״̬��.txt",1);
		write_state("����״̬��.txt",0);
		write_state("����״̬��.txt",0);

	}
	else if(i==3){
		write_state("��һ״̬��.txt",1);
		write_state("�ڶ�״̬��.txt",1);
		write_state("����״̬��.txt",1);
		write_state("����״̬��.txt",0);

	}
	else if(i==4){
		write_state("��һ״̬��.txt",1);
		write_state("�ڶ�״̬��.txt",1);
		write_state("����״̬��.txt",1);
		write_state("����״̬��.txt",1);

	}
	j=jieduan();
	printf("�޸ĺ�Ľ׶α�Ϊ��%d�׶�\n",j);

}

void main_menu()//����Ա���˵�
{

	int choice;
	//int temp;
	do
	{
		system("cls");
		bound('=', 30);
		printf("\t\t\t\t\t1.��Ŀ����\n");
		printf("\t\t\t\t\t2.��Ŀ�޸�\n");
		printf("\t\t\t\t\t3.��Ŀɾ��\n");
		printf("\t\t\t\t\t4.���¼��\n");
		printf("\t\t\t\t\t5.��������\n");
		printf("\t\t\t\t\t6.�鿴��¼�����Ŀ\n");
		printf("\t\t\t\t\t7.�����ϼ�\n");
		bound('=', 30);
		printf("������ѡ�");
		scanf("%d", &choice);
		int temp=jieduan();
		switch (choice)
		{
		case 1:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				add_project();
			}
			else{
				printf("��ǰʱ���Ѿ��������ٷ���������Ŀ\n");
				printf("������Զ�����....\n");
				Sleep(3000);
			}
			//
			break;
		case 2:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				modify_project();
			}
			else{
				printf("��ǰʱ���Ѿ����������޸ı�����Ŀ\n");
				printf("������Զ�����....\n");
				Sleep(3000);
			}
			//
			//modify_project();
			break;
		case 3:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==1){
				delete_project();
			}
			else{
				printf("��ǰʱ���Ѿ���������ɾ��������Ŀ\n");
				printf("������Զ�����....\n");
				Sleep(3000);
			}
			//

			break;
		case 4:
			system("cls");
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==3||temp==4){
				enter_results();//¼��ɼ�
				//������Ľ׶Σ��Դ˽����˶�Ա��ѯ�ɼ�����
				write_state("����״̬��.txt",1);
				printf("¼����ɡ�����\n") ;
			}
			else{
				printf("��ǰʱ�䲻����¼�������Ŀ�ɼ�\n");
				printf("������Զ�����....\n");
				Sleep(3000);
			}
			//
			//"����״̬��.txt"
			//enter_results();
			break;
		case 5:
			system("cls");
			//create_player_of_project();
			//
			//int temp=jieduan();
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==2){
				printf("�������д˲������˶�Ա�����ٿ��Ա��������������Աȷ���Ƿ�Ҫ����ִ�д˲�����(1.��/2��)") ;
				int c;
				scanf("%d",&c);
				if(c==1){
					printf("������������ᣬ���Ժ󡣡���\n");
					//���������
					create_conflict_of_project();
					create_time_of_distribution();
					query_dirtribution();
					//
					printf("������Ѿ��������,�����ٽ����˶�Ա��������������������׶�\n");
					//�޸Ĳ���ʹ�������ȵ������׶�
					write_state("����״̬��.txt",1);
					system("pause");

				}
				else{
					printf("����ȡ��������������\n");
					printf("������Զ�����....\n");
					Sleep(3000);
				}
			}
			else{
				printf("��ǰʱ���Ѿ����������������\n");
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
		 	printf("������Զ�������һ�˵�...\n");
			Sleep(3000);
		 	break;
		case 7:
			system("cls");
			main_surface();
			break;
		}
	} while (1);
}

void main_surface()//��ҳ��
{
	int choice;
	do
	{
		system("cls");
		printf("\t\t\t\t\t�˶������ϵͳ\n");
		bound('=',30);
		printf("\t\t\t\t\t1.����Ա��¼\n\t\t\t\t\t2.�˶�Ա����\n\t\t\t\t\t3.���˳ɼ���ѯ\n\t\t\t\t\t4.��Ϣ��ѯ\n\t\t\t\t\t5.�˳�ϵͳ\n\t\t\t\t\t6�޸ı����׶�\n");
		bound('=', 30);
		printf("��������ѡ��:");
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
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			if(temp==2){
				player_join();
				create_player_of_project();
			}
			else{
				printf("��ǰʱ���Ѿ��������˶�Ա�ٽ��б�����\n");
				printf("������Զ�����....\n");
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
			printf("��ǰ�׶�Ϊ%d\n",temp) ;
			//
			if(temp==4){
				query_scores();
			}
			else{
				printf("��ǰʱ�仹δ���Բ�ѯ�ɼ�\n");
				printf("������Զ�����....\n");
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
				printf("��ǰʱ�仹δ���Բ�ѯ��Ϣ\n");
				printf("������Զ�����....\n");
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
int get_project_number_from_name(char *ProjectName)//����һ����Ŀ������ȷ��һ����Ŀ�ı������ȷ���Ƿ������ǽ�������
{
    FILE *fpo=fopen("������Ŀ��.txt","r");
    project pro[PROJECTMAX];
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);
    fclose(fpo);
    int project_number=0;
    while(project_number<20)
    {
        project_number++;
        if(strcmp(pro[project_number-1].name,ProjectName)==0)
           return project_number;
    }//������bug��Ϊ��������Ŀ��û��¼�������Ŀ����Ļ��ͻᱨ��ġ�


}
void rank_result_file()
{
    FILE *fpo;
    project pro[PROJECTMAX];
    fpo=fopen("������Ŀ��.txt","r");
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);//�ؼ�������ȡ�������������
    fclose(fpo);
    for(int i=0;i<count_pro;i++)
    {
        FILE *fre;
        char FileName[20];
        strcpy(FileName,string_link(pro[i].name,"�ɼ���.txt"));
        score_rank scoArr[PLAYERMAX];
        fre=fopen(FileName,"r");
        int count_re=fread(scoArr,sizeof(score_rank),PLAYERMAX,fre);//�ؼ�������ȡ�������������������
        fclose(fre);
        int project_number=get_project_number_from_name(pro[i].name);
        if(1<=project_number&&project_number<=15)
            for(int j=0;j<count_re-1;j++)//�򵥵�ѡ�����򣬰��ճɼ���С��������С�
                for(int k=j+1;k<count_re;k++)
                if(scoArr[j].sc>scoArr[k].sc)
                {
                score_rank temp=scoArr[j];
                scoArr[j]=scoArr[k];
                scoArr[k]=temp;
                }
        else if(project_number>15)
            for(int j=0;j<count_re-1;j++)//�򵥵�ѡ�����򣬰��ճɼ���С��������С�
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
    fpo=fopen("������Ŀ��.txt","r");
    int count_pro=fread(pro,sizeof(project),PROJECTMAX,fpo);//�ؼ�������ȡ�������������
    fclose(fpo);
    for(int i=0;i<count_pro;i++)
    {
        FILE *fre;
        char FileName1[20];
        char FileName2[20];
        strcpy(FileName1,string_link(pro[i].name,"�ɼ���.txt"));
        strcpy(FileName2,string_link(pro[i].name,"������.txt"));
        score_rank scoArr[PLAYERMAX];
        fre=fopen(FileName1,"r");
        int count_re=fread(scoArr,sizeof(score_rank),PLAYERMAX,fre);//�ؼ�������ȡ�������������������
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

                //����ú���������player.code==college.
                //printf("%d\n",cmp);
                free(college1);
           }

        }

    }//�߳��Ĵ���鰡��
    for(int i=1;i<=9;i++)
        for(int j=i+1;j<=10;j++)
        if(cc[i].goal<=cc[j].goal)
    {
        collegeCode temp=cc[i];
        cc[i]=cc[j];
        cc[j]=temp;
    }
    printf("   ѧԺ   \t�ܻ���\t����\n");
    for(int i=1;i<=10;i++)
        printf("%8s\t%d\t%d\n",cc[i].c,cc[i].goal,i);
        system("pause");
}


int main()
{
    //printf_playerList_data("�˶�Ա������.txt");
   // player_join();
    //clean_players();
	 main_surface();
	//enter_results();
	//add_project();
	//rank_by_college();
	return 1;
}


