// gameSystem.cpp : �������̨Ӧ�ó������ڵ㡣
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
//���������˶�Ա�ı��
void countPlayerCode()
{
	FILE *fp;
	playerSignUp player;
	fp=fopen("�˶�Ա������.txt","r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		playerCode++;
	}
	printf("%d",playerCode);
}
//����Ա����˶���Ŀʱ����
void addProject()
{
	FILE *fp;
	FILE *fileFound;
	project pro;
	int projectNumberFound;
	printf("��������Ŀ������");
	scanf("%d",&projectNumberFound);
	if((fp=fopen("������Ŀ��.txt","a"))==NULL)
	{
		printf("�򿪴���");
	}
	else
	{
		for(int i = 0; i < projectNumberFound;i++)
		{
			printf("��������Ŀ���ƣ�");
			scanf("%s",&pro.projectName);
			printf("��������Ŀ��ţ�");
			scanf("%d",&pro.projectCode);
			printf("��������Ŀ���أ�");
			scanf("%s",&pro.projectPlace);
			printf("�����볡�ر�ţ�");
			scanf("%d",&pro.placeCode);
			printf("�����������λ��");
			scanf("%s",&pro.unitOfMeasurement);
			printf("������ÿ��������");
			scanf("%d",&pro.numberOfPlayerPerGroup);	
			printf("������ÿ��ʱ�䣺");
			scanf("%d",&pro.timeOfGroupTake);
			printf("��������߼�¼��");
			scanf("%d",&pro.heighestRecord);	
			fwrite(&pro,sizeof(project),1,fp);
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
		countPlayerCode();
		player.playerCode = playerCode;
		printf("������������֣�");
		scanf("%s",&player.playerName);
		printf("���������ѧԺ��");
		scanf("%s",&player.college);
		printf("����������Ա�");
		scanf("%s",&player.gender);
		printf("��������Ҫ�μӵ���Ŀ����(������3��)��");
		scanf("%d",&numberOfJoin);
		 strcpy(player.projectName1,"��");
		 strcpy(player.projectName2,"��");
		 strcpy(player.projectName3,"��");
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
			}		
		}
		fwrite(&player,sizeof(playerSignUp),1,fp);
	}
	fclose(fp);	
}
//������Ŀ�˶�Ա������
void createPlayerOfProject()
{
	char *fileName;		//������ʱ���ļ���
	FILE *fpOfPro;			//ָ�������Ŀ����ļ�ָ�����
	FILE *fpOfPlayer;		//ָ���˶�Ա��������ļ�ָ�����
	FILE *tempFile;		//��ʱ�ļ�ָ�����
	int proCode;			//��Ŀ���
	project pro;
	playerSignUp player;
	fpOfPro=fopen("������Ŀ��.txt","r");
	
	while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL)
	{                                                     
		proCode=pro.projectCode;
		fileName=stringLink(pro.projectName,"������.txt");
		tempFile=fopen(fileName,"w");
		fpOfPlayer=fopen("�˶�Ա������.txt","r");
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
//������Ŀʱ������
void createTimeOfEstimation()
{
	char *fileName;			//��ʱ�ļ���
	FILE *fpOfPro;			//ָ�򡰱�����Ŀ����ָ�����
	FILE *fpOfPlayerList;	//ָ����Ŀ�˶�Ա��������ָ�����
	FILE *fpOfTemp;			//��ʱ�ļ�ָ�����
	project pro;
	playerSignUp player;
	time ti;
	int baseTime =0;			//ÿ�黨��ʱ�䣬��������λʱ��
	int count;
	fpOfPro = fopen("������Ŀ��.txt","r");
	fpOfTemp =fopen("��Ŀʱ������.txt","w");
	while(fread(&pro,sizeof(project),1,fpOfPro) != NULL)
	{
		fileName=stringLink(pro.projectName,"������.txt");
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
//������Ŀ��ͻ��
void createConflictOfProject()
{
	char *fileName,*fileName1,*fileName2;
	FILE *fpOfPro;													//ָ�򡰱�����Ŀ����ָ�����
	FILE *fpOfPlayerListA,*fpOfPlayerListB;			//ָ����Ŀ�˶�Ա��������ָ�����
	FILE *fpOfTemp;												//������ͻ��ʹ�õ�ָ�����
	int countOfPro = 0;
	project proArr[PROJECTMAX],pro;					//proArr���ڴ洢���е���Ŀ
	/*
	playerArrA�Լ�playerArrB���ڴ洢��Ŀ�˶�Ա�����������
	���ڶ�A��B������Ŀ���Ƿ���ͬһ���˶�Ա�ıȽ�
	*/
	playerSignUp player,playerArrA[PLAYERMAX],playerArrB[PLAYERMAX];
	conflict con;
	fpOfPro=fopen("������Ŀ��.txt","r");
	while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL)
	{
		proArr[countOfPro]=pro;		
		countOfPro++;
	}
	fclose(fpOfPro);
	for(int i=0;i<countOfPro;i++)
	{
		fileName = stringLink(proArr[i].projectName,"��ͻ��.txt");
		fileName1 = stringLink(proArr[i].projectName,"������.txt");
		fpOfTemp=fopen(fileName,"w");
		printf("%s\n",proArr[i].projectName);
		fpOfPlayerListA = fopen(fileName1,"r");
		int countOfPlayerA = 0;
		//��Ҫ���Ƚϵ��˶�Ա�������ݴ洢��A��
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
				fileName2 = stringLink(proArr[j].projectName,"������.txt");
				fpOfPlayerListB=fopen(fileName2,"r");
				//��Ҫ�Ƚϵ��˶�Ա�������ݴ洢��B��
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
					/*����˶���Ŀ�ĳ�����ͬ�����߲�ͬ����Ŀ���������к�����ͬ���˶�Ա
					��˵����������Ŀʱ��ͻ��*/
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
//����ʱ������
void createTimeOfDistribution()
{
		FILE *fpOfTemp;											//�򿪻��ߴ�����Ŀʱ�������ָ�����
		FILE *fpOfPro;												//ָ�������Ŀ���ָ�����
		FILE *fpOfCon;												//ָ���ͻ���ָ�����
		char *fileName;												//�򿪸�����Ŀ�ĳ�ͻ�����ʱָ�����
		int	 countOfPro = 0;									//��Ŀ����
		int	timeOfSegment = 0;								//ʱ��κ���
		int	 count=0;
		int    weipai = 0;											//δ��ʱ��κŵ���Ŀ����
		project pro,proArr[PROJECTMAX];					//�洢��Ŀ�����ݵ�����
		conflict con,conArr[PROJECTMAX];				//�洢��ͻ�����ݵ�����
		distribution distriArr[PROJECTMAX];				//�洢ʱ���������ݵ�����
		fpOfPro = fopen("������Ŀ��.txt","r");
		//��ʼ��ʱ������
		while(fread(&pro,sizeof(project),1,fpOfPro)!=NULL )
		{	
			proArr[countOfPro] = pro;
			countOfPro ++;
			weipai++;
		}
		fclose(fpOfPro);
		//��ʼ��ʱ������Ŀ��ͻ�ȶԱ������
		for(int i =0;i<countOfPro;i++)
		{
			distriArr[i].projectCode = proArr[i].projectCode;
			strcpy(distriArr[i].projectName,proArr[i].projectName);
			distriArr[i].timeCode = 0;
			conArr[i].projectCode = proArr[i].projectCode;
			strcpy(conArr[i].projectName,proArr[i].projectName);
			conArr[i].isConflict=0;
		}
		fpOfTemp = fopen("��Ŀʱ������.txt","w");
		//��δ����Ŀ��������0ʱ
		while(weipai>0)
		{
			if(distriArr[count].timeCode==0)//�����Ŀ��ʱ��κ�Ϊ0������Ŀ��ʱ��κŻ�û�з���
			{
				timeOfSegment++;
				distriArr[count].timeCode=timeOfSegment;
				weipai --;
				while(count<countOfPro)
				{
					here:fileName=stringLink(distriArr[count].projectName,"��ͻ��.txt");
					printf("%s\n",fileName);
					fpOfCon =fopen(fileName,"r");
					//���³�ͻ�ȶԱ�
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
//��ѯ�˶�Ա�����������
void queryPlayer()
{ 
	playerSignUp player;
	FILE *fp;
	fp = fopen("�˶�Ա������.txt","r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		printf("%s\t%s\t%d\t%s\t%s\t%s\t%s\n",player.college,player.gender,player.playerCode,player.playerName,player.projectName1,player.projectName2,player.projectName3);
	}
	fclose(fp);
}
//��ѯ��Ŀ�������
int queryProject()
{
	project pro,proArr[PROJECTMAX];
	int proCount = 0;
	FILE *fp;
	fp = fopen("������Ŀ��.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\t��߼�¼\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	return proCount;
}
//��ѯ��Ŀ�˶�Ա�����������
void queryPlayerList(char *projectName)
{
	FILE *fp;
	char *fileName;
	playerSignUp player;
	fileName=stringLink(projectName,"������.txt");
	fp = fopen(fileName,"r");
	while(fread(&player,sizeof(playerSignUp),1,fp)!=NULL)
	{
		printf("%d  %s  %s  %s\n",player.playerCode,player.playerName,player.college,player.gender);
	}
	fclose(fp);
}
//��ѯ��Ŀʱ�����������
void queryTime()
{
	FILE *fp;
	time ti;
	fp = fopen("��Ŀʱ������.txt","r");
	while(fread(&ti,sizeof(time),1,fp)!=NULL)
	{
		printf("%s\t",ti.projectName);
		printf("%d\t%d\t%d\n",ti.projectCode,ti.countOfPlayer,ti.estimatedTime);
	}
	fclose(fp);
}
//��ѯ��Ŀ��ͻ�������
void queryConflict(char *projectName)
{
	FILE *fp;
	char *fileName;
	conflict con;
	fileName=stringLink(projectName,"��ͻ��.txt");
	fp =fopen(fileName,"r");
	while(fread(&con,sizeof(conflict),1,fp)!=NULL)
	{
		printf("%d\t%s\t%d\n",con.projectCode,con.projectName,con.isConflict);
	}
	fclose(fp);
}
//��ѯ��Ŀʱ�����������
void queryDistribution()
{
	distribution distri;
	FILE *fp;
	fp=fopen("��Ŀʱ������.txt","r");
	while(fread(&distri,sizeof(distribution),1,fp)!=NULL)
	{
		printf("\n%d,%s,%d\n",distri.projectCode,distri.projectName,distri.timeCode);
	}
	fclose(fp);
}
//�ж��Ƿ��޸ĺ�ɾ��
int didDeleteOrModify()
{
	int choice;
	printf("ȷ���޸ġ�ɾ�� YES(1)/NO(0):");
	scanf("%d", &choice);
	return choice;

}
//�޸ı�����Ŀ�������
void modifyProject()
{
	FILE *fp;
	project pro,proArr[PROJECTMAX];
	int proCount = 0;
	int modifyProCode;
	int modifyCode;
	char *modifyStrData;
	int modifyIntData;
	fp = fopen("������Ŀ��.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\t��߼�¼\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	printf("������Ҫ�޸ĵ���Ŀ�ı��");
	scanf("%d", &modifyProCode);
	printf("��ѡ��Ҫ�޸ĵ�ѡ�\n1. ��Ŀ����\n2. ��������\n3. ������λ\n4. ÿ������\n5. ÿ��ʱ��\n 6. ��߼�¼\n");
	scanf("%d",&modifyCode);
	printf("������ĺ����ݣ�");
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
	fp = fopen("������Ŀ��.txt", "w");
	fwrite(proArr, sizeof(project), proCount, fp);
	fclose(fp);

}
//ɾ��������Ŀ���ĳ�����ݣ�
void deleteProject()
{
	FILE *fp;
	project  pro, proArr[PROJECTMAX];
	int modifyCode;
	int proCount = 0;
	fp = fopen("������Ŀ��.txt", "r");
	while (fread(&pro, sizeof(project), 1, fp) != NULL)
	{
		proArr[proCount] = pro;
		proCount++;
	}
	fclose(fp);
	printf("���\t��Ŀ����\t���ر��\t��������\t������λ\tÿ������\tÿ��ʱ��\t��߼�¼\n");
	for (int i = 0; i < proCount; i++)
	{
		printf("%d\t%s\t%d\t%s", proArr[i].projectCode, proArr[i].projectName, proArr[i].placeCode, proArr[i].projectPlace);
		printf("%s\t%d\t%d\t%d\n", proArr[i].unitOfMeasurement, proArr[i].numberOfPlayerPerGroup, proArr[i].timeOfGroupTake, proArr[i].heighestRecord);
	}
	printf("������Ҫɾ����Ϣ�����");
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
		fp = fopen("������Ŀ��.txt", "w");
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
	printf("����������˶�Ա���");
	scanf("%d", playerCode);
	if (fp = fopen("�˶�Ա������.txt","r"))
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
	//queryPlayerList("����100��");
	//createTimeOfEstimation();
	//queryTime();
	//createConflictOfProject();
	//queryConflict("����100��");
	//createTimeOfDistribution();
	//createTimeOfDistribution();
	//queryDistribution();
	//countPlayerCode();
	deleteProject();
	scanf("%d",choice);
	
	return 0;
}

