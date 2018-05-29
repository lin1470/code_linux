// game.cpp : �������̨Ӧ�ó������ڵ㡣
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
//�ַ���ƴ�Ӻ���
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
	printf("��������Ŀ������");
	scanf("%d", &projectNumberFound);
	if ((fp = fopen("������Ŀ��.txt", "a")) == NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		do
		{
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
	fp = fopen("�˶�Ա������.txt", "r");
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
	if ((fp = fopen("�˶�Ա������.txt", "a")) == NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		playerCode = count_playerCode();
		player1.playerCode = playerCode;
		printf("������������֣�");
		scanf("%s", &player1.playerName);
		printf("���������ѧԺ��");
		scanf("%s", &player1.college);
		printf("����������Ա�");
		scanf("%s", &player1.gender);
		printf("��������Ҫ�μӵ���Ŀ����(������3��)��");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "��");
		}
		for (int i = 0;i < numberOfJoin;i++)
		{
			printf("��������Ŀ���ƣ�");
			scanf("%s", &player1.pro[i].name);
			printf("��������Ŀ��ţ�");
			scanf("%d", &player1.pro[i].code);
		}
		fwrite(&player1, sizeof(player), 1, fp);
	}
	fclose(fp);
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
		fileName = stringLink(pro.name, "������.txt");
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
														/*
														playerArrA�Լ�playerArrB���ڴ洢��Ŀ�˶�Ա�����������
														���ڶ�A��B������Ŀ���Ƿ���ͬһ���˶�Ա�ıȽ�
														*/
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
		printf("%s\n", proArr[i].name);
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
				printf("%s\n", fileName);
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
		printf("\n\t1.�˶���Ŀ����\n");
		printf("\t2.�˶���Ŀ�޸�\n");
		printf("\t3.�������¼��\n");
		printf("\t4.������һ��\n");
		printf("\t5.�˳�\n");
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
void main_surface()
{
	int choice;
	do
	{
		printf("\t\t\t\t�˶������ϵͳ\n");
		printf("\t\t\t________________________________\n");
		printf("\t\t\t\t1.����Ա��¼\n\t\t\t\t2.�˶�Ա����\n\t\t\t\t3.�ɼ���ѯ\n\t\t\t\t4.��Ϣ��ѯ\n\t\t\t\t5.�˳�ϵͳ\n");
		printf("\t\t\t________________________________\n");
		printf("��������ѡ��:");
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

