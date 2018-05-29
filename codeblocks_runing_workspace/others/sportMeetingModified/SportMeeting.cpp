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
    char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1);//��̬����ռ�����飬ע�����������Ҫ�ٺ�����
    //�ֶ��ͷŵ�
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

int printf_pro_data()
{
    FILE *fp;
	project  pro;
	int count = 0;
	fp = fopen("������Ŀ��.txt", "r");
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\n");
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
	printf("���\t����\t�Ա�\tѧԺ\t�μ���Ŀ\n");
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
	printf("�Ƿ��޸ġ�ɾ��YES(1)/NO(0): ");
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
		for (int i = modifyCode; i < proCount; i++)
		{
			if (i < proCount - 1)
			{
				proArr[i] = proArr[i + 1];
			}
		}
	}
	fp = fopen("������Ŀ��.txt", "w");
	fwrite(proArr, sizeof(project), proCount - 1, fp);
	fclose(fp);
}

void add_project()
{
	FILE *fp;
	project pro;
	int choice = 1;
	char c;
	printf("����Ҫ�����������е���Ŀ������Ҫ�����Ŀ��\n1.��������\t2.�����Ŀ\n�����룺");
    while((c=getchar(),fflush(stdin),c!='1'&&c!='2'))
    {
        printf("���벻��ȷ������������:");
    }
    if(c=='1')
        fp=fopen("������Ŀ��.txt","w");
    else fp=fopen("������Ŀ��.txt","a");

		do
		{
		    Sleep(1000);
		    system("cls");
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
			printf("�Ƿ���Ҫ�ٴ�����һ����ĿYES(1)/NO(0)");
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
	printf_pro_data();
	if ((fp = fopen("�˶�Ա������.txt", "a")) == NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		playerCode = count_playerCode();
		printf("���ǵ�%d���������˶�Ա\n",playerCode);
		player1.playerCode = playerCode;
		printf("������������֣�");
		scanf("%s", &player1.playerName);
		printf("���������ѧԺ��");
		scanf("%s", &player1.college);
		printf("����������Ա�\n1.��\t2.Ů\n");
		int c=0;
		while((scanf("%d",&c),fflush(stdin),c!=1&&c!=2))
            printf("������� ���������룺");
		if(c==1)
            strcpy(player1.gender,"��");
        else strcpy(player1.gender,"Ů");
		printf("��������Ҫ�μӵ���Ŀ����(������3��)��");
		scanf("%d", &numberOfJoin);
		for (int i = 0; i < 3; i++)
		{
			strcpy(player1.pro[i].name, "��");
			//strcpy(player1.pro[i].code)
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
		int playerNum=0;
		fileName = string_link(pro.name, "������.txt");//����Щ��Ŀ����˶�Ա���������ġ�
		tempFile = fopen(fileName, "w");
		fpOfPlayer = fopen("�˶�Ա������.txt", "r");//����һ������˶�Ա�ģ�Ȼ����δ��ڵĻ��Ͱ����Ǽӽ�����
		while (fread(&player1, sizeof(player), 1, fpOfPlayer) != NULL)
		{
			if (player1.pro[0].code == proCode || player1.pro[1].code == proCode || player1.pro[2].code == proCode)
			{
				//printf("%d", player1.playerCode);
				fwrite(&player1, sizeof(player), 1, tempFile);
				playerNum++;
			}
		}
		printf("�μ�%s��Ŀ���У�%d����\n",pro.name,playerNum);
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
	printf("������Ҫ¼��������Ŀ��ţ�");
	fp = fopen("������Ŀ��.txt","r");
	fread(pro, sizeof(project), count, fp);
	fclose(fp);
	scanf("%d", &  choice);
	file_name = string_link(pro[choice - 1].name, "������.txt");
	count = printf_playerList_data(file_name);
	fp = fopen(file_name, "r");
	fread(playerArr, sizeof(player), count, fp);
	fclose(fp);
	printf("�����������˶�Ա�ĳɼ�:");
	for (int i = 0; i < count; i++)
	{
		printf("��%d�˶�Ա�ĳɼ�:", i);
		scanf("%d\n",&score);
		for (int j = 0; j < 3; j++)
		{
			if (playerArr[i].pro[j].code==pro[i].code)
			{
				playerArr[i].pro[i].score = score;
			}
		}
	}
	file_name = string_link(pro[choice - 1].name, "�ɼ���");
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
	printf("��������ı�ţ�");
	scanf("%d", &player_code);
	fp = fopen("�˶�Ա������.txt", "r");
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
		if (q.pro[i].name != "��")
		{
			fileName = string_link(q.pro[i].name, "�ɼ���.txt");
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
		printf("\t\t\t\t\t6.�����ϼ�\n");
		bound('=', 30);
		printf("������ѡ�");
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

void main_surface()
{
	int choice;
	do
	{
		system("cls");
		printf("\t\t\t\t\t�˶������ϵͳ\n");
		bound('=',30);
		printf("\t\t\t\t\t1.����Ա��¼\n\t\t\t\t\t2.�˶�Ա����\n\t\t\t\t\t3.�ɼ���ѯ\n\t\t\t\t\t4.��Ϣ��ѯ\n\t\t\t\t\t5.�˳�ϵͳ\n");
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
