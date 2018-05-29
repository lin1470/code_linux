// gameSystem.cpp : �������̨Ӧ�ó������ڵ㡣
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
//�ַ���ƴ�Ӻ���
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
//����Ա����˶���Ŀʱ����
void addProject()
{
	FILE *fp;
	FILE *fileFound;
	project pr;
	int projectNumberFound;
	scanf("%d",&projectNumberFound);
	if((fp=fopen("������Ŀ��.text","a"))==NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		for(int i = 0; i < projectNumberFound;i++)
		{
			printf("������Ŀ���ƣ�");
			scanf("%s",&pr.projectName);
			printf("������Ŀ��ţ�");
			scanf("%d",&pr.projectCode);
			printf("������Ŀ���أ�");
			scanf("%s",&pr.projectPlace);
			printf("���볡�ر�ţ�");
			scanf("%d",&pr.placeCode);
			printf("����ÿ��������");
			scanf("%d",&pr.numberOfPlayerPerGroup);
			printf("����ÿ��ʱ�䣺");
			scanf("%d",&pr.timeOfGroupTake);
			printf("������߼�¼��");
			scanf("%d",&pr.heighestRecord);
			printf("���������λ��");
			scanf("%s",&pr.unitOfMeasurement);
		}
	}
	fclose(fp);
}
//�˶�Ա��������
void playerJoin()
{
	FILE *fp;
	playerSignUp player;
	int numberOfJoin;
	if((fp=fopen("�˶�Ա������.txt","a"))==NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		printf("������������֣�");
		scanf("%s",&player.playerName);
		printf("����������Ա�");
		scanf("%s",&player.gender);
		printf("���������ѧԺ��");
		scanf("%s",&player.college);
		printf("��������Ҫ�μӵ���Ŀ����(������3��)��");
		scanf("%d",&numberOfJoin);
		for(int i=0;i<numberOfJoin;i++)
		{
			switch(i)
			{
				case 0:
					printf("��������Ŀ���ƣ�");
					scanf("%s",&player.projectName1);
					printf("��������Ŀ��ţ�");
					scanf("%d",&player.projectCode1);
					break;
				case 1:
					printf("��������Ŀ���ƣ�");
					scanf("%s",&player.projectName2);
					printf("��������Ŀ��ţ�");
					scanf("%d",&player.projectCode2);
					break;
				case 2:
					printf("��������Ŀ���ƣ�");
					scanf("%s",&player.projectName3);
					printf("��������Ŀ��ţ�");
					scanf("%d",&player.projectCode3);
					break;
				default:break;
			}
		}
		fwrite(&player,sizeof(playerSignUp),1,fp);
	}
	fclose(fp);
}
//���ɸ�����Ŀ���˶�Ա������
void createPlayerOfProject()
{
	char *fileName;
	FILE *fpOfPro;
	FILE *fpOfPlayer;
	FILE *tempFile;
	int proCode;
	project pro;
	playerSignUp player;
	fpOfPro=fopen("������Ŀ��.txt","r");
	fpOfPlayer=fopen("�˶�Ա������.txt","r");
	while(fread(&pro,sizeof(project),1,fpOfPro)!=EOF)
	{
		proCode=pro.projectCode;
		fileName=stringLink(pro.projectName,"������.txt");
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

