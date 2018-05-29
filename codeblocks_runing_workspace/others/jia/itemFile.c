#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "data.h"

int itemNum = 0;//��������
int projectNum = 0; //��Ŀ����
int sortNum = 0;
struct athlete temp[666];
struct project tempProject[50];

//���ر����������Լ���Ŀ����
void loadData() {
    FILE *file;
    // �ж��ļ��Ƿ��ܹ���ȷ����/��
    if ((file = fopen(DATAPATH, "r")) == NULL) {
        perror(DATAPATH);
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%s\t%s\t%d\t%s\t%s", temp[i].ID, temp[i].name, &temp[i].sex, temp[i].college,
                  temp[i].projectName) != EOF) {
        //printf("%d",i);
        i++;
    }
    itemNum = i;
    fclose(file);

    //��ȡ��Ŀ����
    if ((file = fopen(PROJECTPATH, "r")) == NULL) {
        perror(PROJECTPATH);
        exit(1);
    }
    projectNum = 0;
    while (fread(&tempProject[projectNum], sizeof(struct project), 1, file)) {
        projectNum++;
    }
    fclose(file);
    loadRecords();
}

//load records of each project from the entryForm.
void loadRecords(){
    int l = 0;
    for(int q = 0; q < projectNum; q++){ //initialization
        tempProject[q].record;
        memset(tempProject[q].record,0,sizeof(tempProject[q].record));
    }

    for(int q = 0; q < projectNum ; q++){
        for(int k = 0; k < tempProject[q].num; k++){
            l = 0;
           for(int j = 0; j < itemNum;j++){
               if(strcmp(temp[j].projectName,tempProject[q].name)==0){
                   strcpy(tempProject[q].record[l].name,temp[j].name);
                   strcpy(tempProject[q].record[l].ID,temp[j].ID);
                   tempProject[q].record[l].sex = temp[j].sex;
                   l++;
               }
           }
        }
    }
}

//���汨��������
void saveData() {
    FILE *file;
    if ((file = fopen(DATAPATH, "w+")) == NULL) {
        perror(DATAPATH);
        exit(1);
    }
    for (int i = 0; i < itemNum; i++) {
        fprintf(file, "%s\t%s\t%d\t%s\t%s", temp[i].ID, temp[i].name, temp[i].sex, temp[i].college,
                temp[i].projectName);
        //��ֹ�ļ��Իس�����β
        if (i != itemNum - 1) fprintf(file, "\n");
    }
    fclose(file);

    //������Ŀ����
    if ((file = fopen(PROJECTPATH, "w")) == NULL) {
        perror(PROJECTPATH);
        exit(2);
    }
    int temp;
    for (int i = 0; i < projectNum; i++) {
        temp = fwrite(&tempProject[i], sizeof(struct project), 1, file);
        //printf("temp = %d\n", temp);
    }
    fclose(file);

    //���浥���ļ��ı�������
    for (int i = 0; i < projectNum; i++) {
        if ((file = fopen(tempProject[i].path, "w")) == NULL) {
            perror(tempProject[i].path);
            exit(3);
        }
        printf("���ڱ���%s�ļ���%s��\n",tempProject[i].name,tempProject[i].path);
        for (int j = 0; j < tempProject[i].num; j++) {
            if(tempProject[i].record[j].grade == NULL)
                strcpy(tempProject[i].record[j].grade,"0") ;
            fprintf(file, "%s\t%s\t%s\t%s\n", tempProject[i].record[j].name,getSex(tempProject[i].record[j].sex),tempProject[i].record[j].ID, "0");
            printf("%s\t%s\t%s\n", tempProject[i].record[j].name,tempProject[i].record[j].ID,"0");
        }
        fclose(file);
    }
}

//�鿴�������
void view() {
    printf("\t\t\t****************************************************************************************\n");
    printf("\t\t\t*���\tѧ��\t\t����\t\t�Ա�\t\tѧԺ\t\t��Ŀ\t\t*\n");
    printf("\t\t\t����������������������������������������������������������������������������������������\n");

    for (int i = 0; i < itemNum; i++) {
        printf("\t\t\t* %-6d %-15s %-15s %-15s %-15s %-15s*\n", i, temp[i].ID, temp[i].name, getSex(temp[i].sex),
               temp[i].college, temp[i].projectName);
    }
    printf("\t\t\t*****************************************************************************************\n");
    printf("\t\t\t\t\t����(1)\tɾ��(2)\t�޸�(3)\t����(4)\t����(0)\n");

};

void readProjectList() {
    for (int i = 0; i < projectNum; i++) {
        printf("\t\t\t%-6d\t\t%-15s\t\t%-15s\n", i, tempProject[i].name, tempProject[i].space);
    }
}


//�鿴��Ŀ���
void viewProject() {
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t���\t\t��Ŀ\t\t\t����\n");
    printf("\t\t\t��������������������������������������������������������������������\n");
    readProjectList();
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t����(1)\tɾ��(2)\t�޸�(3)\t����(0)\n");
    editProject(getItemNum(0, 3, "��������ţ�"));
};

void import() {
    char importPath[50];
    FILE *fp = NULL;
    int invalidNum = 0;
    int totalNum = 0;
    int subscript = 0;

//    do{
//        printf("������Ҫ�����ļ��ľ���·����\n");
//
//        scanf("%s", importPath);
//
//    };
    fp = getPath("�����뵼���ļ��ľ���·��:",fp);

    char tempSex[10] ;
    while (fscanf(fp, "%s\t%s\t%d\t%s\t%s\n", temp[itemNum].ID,temp[itemNum].name,
                  &temp[itemNum].sex, temp[itemNum].college, temp[itemNum].projectName) != EOF) {
        totalNum++;
        //temp[itemNum].sex = getSexNum(tempSex);
        //TODO Ҫ����һ���˱������Ŀ�����
        if((subscript = isProjectExit(temp[itemNum].projectName))==0){
            invalidNum++;
        } else if(checkID(temp[itemNum].ID) >= 3){ //�����ѧ�ű��˳���3����Ŀ��ֱ�ӷ����
            invalidNum++;
        } else if(checkID(temp[itemNum].ID)>0){ //����ID������������Ŀ������3��Ҫ����̸��
            if(checkMessage(&temp[itemNum])==1) {
                subscript--;
                strcpy(tempProject[subscript].record[tempProject[subscript].num].ID,temp[itemNum].ID);
                strcpy(tempProject[subscript].record[tempProject[subscript].num].name,temp[itemNum].name);
                tempProject[subscript].record[tempProject[subscript].num].sex = temp[itemNum].sex;
                tempProject[subscript].num++;
                itemNum++;
            } else  invalidNum++;
        } else{ //��Ӧ��Ŀ��recordҪ����Ӧ�仯
            subscript--;
            strcpy(tempProject[subscript].record[tempProject[subscript].num].ID,temp[itemNum].ID);
            strcpy(tempProject[subscript].record[tempProject[subscript].num].name,temp[itemNum].name);
            tempProject[subscript].record[tempProject[subscript].num].sex = temp[itemNum].sex;
            tempProject[subscript].num++;
            itemNum++;
        }
    }
    fclose(fp);
    printf("�ļ�������ϣ�����%d�����ݣ�������%d����Ч���ݡ�\n",totalNum,invalidNum);
    system("pause");
    viewMenu();
}

//���ļ���ѡ��
void file(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            view();
            int i = getItemNum(0, 4, "������˵��");
            if (i == 1 && projectNum == 0) {
                printf("���Ƚ���������Ŀ��\n");
                system("pause");
                viewMenu();
                break;
            }
            if (i == 4) {
                loadSerial(temp,itemNum);
                search(temp,&itemNum);
                break;
            }
            edit(i);
            break;
        case 2:
            import();
            break;
        case 3:
            break;
        case 4:
            viewProject();
            break;
        case 5:
            saveData();
            printf("����ɹ��������������...");
            system("pause");
            viewMenu();
            break;
    }
}

void createProjectFile(char path[]) {
    FILE *file;
    if ((file = fopen(path, "w")) == NULL) {
        perror(path);
        exit(1);
    }
    fclose(file);
}