
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "data.h"

//����˶�Ա��Ϣ
void add() {
    char name[NAMELENGTH], project[10];
    char college[10];
    char sex[10];
    char ID[30];
    int no, tempSex;
    int flag;
    int mark;
    int t;

    do {
        t = 0;
        mark = 0;
        flag = 0;
        printf("������ѧ�ţ�\n");
        scanf("%s", ID);
        //��֤ѧ��
        for (int i = 0; i < itemNum; i++) {
            if (strcmp(ID, temp[i].ID) == 0) {
                mark++;
                t = i;
            }
        }
        if (mark > 0) {
            printf("���м�¼��%s\t%s\t%s\n", temp[t].name, getSex(temp[t].sex), temp[t].college);
            if (mark >= 3) {
                printf("��ѧ���ѱ�ע���Ҳμ���%d����Ŀ��(1)��������ѧ�� (0)���ز˵�\n", mark);
                switch (getItemNum(0, 1, "��������ţ�")) {
                    case 0:
                        viewMenu();
                        break;
                    case 1:
                        flag = 1;
                        break;
                }
            } else {
                printf("��ѧ���ѱ�ע�ᣬ(1)ʹ�ø�ѧ�������Ϣ (2)��������ѧ�� (0)���ز˵�\n");
                switch (getItemNum(0, 2, "��������ţ�")) {
                    case 0:
                        viewMenu();
                        break;
                    case 1:
                        strcpy(name, temp[t].name);
                        strcpy(sex, getSex(temp[t].sex));
                        strcpy(college, temp[t].college);
                        break;
                    case 2:
                        flag = 1;
                        break;
                }
                break;
            }
        } else {
            printf("�����������˶�Ա������Ϣ������ �Ա� ѧԺ(��һ���ո����)\n");
            scanf("%s %s %s", name, sex, college);
            flag = 0;
        }
    } while (flag == 1);

    printf("\t\t\t****************************************************************\n");
    printf("\t\t\t���\t\t��Ŀ\t\t\t����\n");
    printf("\t\t\t����������������������������������������������������������������\n");
    readProjectList();
    printf("\t\t\t****************************************************************\n");
    do {
        flag = 0;
        no = getItemNum(0, projectNum, "�����������Ŀ�Ķ�Ӧ��ţ�");
        for (int i = 0; i < tempProject[no].num; i++) {
            if (strcmp(ID, tempProject[no].record[i].ID) == 0) { //��⵽��ѡȡ��Ŀ������ͬѧ����Ϣ
                printf("��ѡȡ��Ŀ�д�����ͬ�ı�����¼ (1)����������Ŀ  (0)ȡ��\n");
                int j = getItemNum(0, 1, "��������ţ�");
                if (j == 0) {
                    viewMenu();
                    break;
                } else {
                    flag = 1;
                    break;
                }
            }
        }
    } while (flag);

    strcpy(temp[itemNum].projectName, tempProject[no].name);
    strcpy(temp[itemNum].ID, ID);
    strcpy(temp[itemNum].name, name);
    strcpy(temp[itemNum].college, college);
    printf("��ǰ�Ա�Ϊ��%d:%s\n", getSexNum(sex), sex);
    temp[itemNum].sex = getSexNum(sex);

    strcpy(tempProject[no].record[tempProject[no].num].name, temp[itemNum].name);
    strcpy(tempProject[no].record[tempProject[no].num].ID, temp[itemNum].ID);
    tempProject[no].record[tempProject[no].num].sex = temp[itemNum].sex;

    //����Ŀ���������Լ���������1
    tempProject[no].num++;
    itemNum++;

    view();
    if (ifGoOn("���") == 0) {
        system("cls");
        view();
        add();
    } else viewMenu();
}

//����ɾ��
void deleteSingle(struct athlete data[], int num, int *lengthOfData) {

    for (int i = 0; i < projectNum; i++) {
        for (int j = 0; j < tempProject[i].num; j++) {
            if (strcmp(data[num].ID, tempProject[i].record[j].ID) == 0) {
                for (int q = j; q < tempProject[i].num; q++) {
                    data[q] = data[q + 1];
                }
                tempProject[i].num--;
                break;
            }
        }
    }
    for (int i = num; i < *lengthOfData; i++) {
        data[i] = data[i + 1];
    }
    --*lengthOfData;
}

void deleteAtNum(struct athlete data[], int *lengthOfData) {
    int num;

    printf("������Ҫɾ�����˶�Ա���:");
    scanf("%d", &num);
    deleteSingle(data, num, lengthOfData);
}

void deleteAtName(struct athlete data[], int *lengthOfData) {
    char *name = NULL;
    char Name[20][NAMELENGTH];
    const char *split = "\\";
    char *p;
    int length = 0;
    char string[20];

    printf("������Ҫɾ�����˶�Ա����:������\\�ָ\n");
    scanf("%s", string);

    p = strtok(string, split);

    while (p != NULL) {
        name = p;
        strcpy(Name[length], name);
        length++;
        p = strtok(NULL, split);
    }

    for (int i = 0; i < *lengthOfData; i++) {
        for (int j = 0; j < length; j++) {
            //printf("��%d��%s,�Ƚ�%s\n", i,temp[i].name, Name[j]);
            if (strcmp(temp[i].name, Name[j]) == 0) {
                printf("ɾ����%d��\n,������%s\n", i, Name[j]);
                deleteSingle(data, i, lengthOfData);
                i--;
            }
        }
    }
}

void deleteAtCollege(struct athlete data[], int *lengthOfData) {
    char *name = NULL;
    char Name[20][20];
    const char *split = "\\";
    char *p;
    int length = 0;
    char string[20];

    printf("������Ҫɾ����ѧԺ��:������\\�ָ\n");
    scanf("%s", string);

    p = strtok(string, split);

    while (p != NULL) {
        name = p;
        strcpy(Name[length], name);
        length++;
        p = strtok(NULL, split);
    }
    //ɾ��һ��Ԫ�ص�ͬʱ
    for (int i = 0; i < *lengthOfData; i++) {
        printf("��%d�ŵ�ѧԺΪ%s\n", i, temp[i].college);
        for (int j = 0; j < length; j++) {
            if (strcmp(temp[i].college, Name[j]) == 0) {
                printf("***************************\n");
                printf("ɾ����%d��\n,������%s\n", i, Name[j]);
                deleteSingle(data, i, lengthOfData);
                i--;
            }
        }
    }
}

void delete() {
    char id[30];
    int t = -1;
    printf("�� ���(1) ����(2)  ѧԺ(3)  ѧ��(4) ɾ��������(0)\n");
    int n = getItemNum(0, 4, "��������ţ�");
    switch (n) {
        case 1:
            deleteAtNum(temp, &itemNum);
            break;
        case 2:
            deleteAtName(temp, &itemNum);
            break;
        case 3:
            deleteAtCollege(temp, &itemNum);
            break;
        case 4:
            do {
                printf("������ѧ�ţ�(����������n)");
                scanf("%s", id);
                if (strcmp(id, "n") == 0) break;
                for (int i = 0; i < itemNum; i++) {
                    if (strcmp(id, temp[i].ID) == 0) {
                        t = i;
                        break;
                    }
                }
                if (t < 0) printf("���޴˺�\n");
            } while (t < 0);
            deleteSingle(temp, t, &itemNum);
            break;
        case 0:
            viewMenu();
            return;
    }
    view();
    if (ifGoOn("ɾ��") == 0) {
        delete();
    } else viewMenu();

}

void deleteSearchResult(struct athlete data[], int *lengthOfData) {
    printf("�� ���(1) ����(2)  ѧԺ(3) ɾ��������(0)\n");
    int n = getItemNum(0, 3, "���������");
    switch (n) {
        case 1:
            deleteAtNum(data, lengthOfData);
            break;
        case 2:
            deleteAtName(data, lengthOfData);
            break;
        case 3:
            deleteAtCollege(data, lengthOfData);
            break;
        case 0:
            viewMenu();
            return;
    }
}

void viewSearchResult(struct athlete data[], int *lengthOfData) {

    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t���\t\tѧ��\t\t����\t\t�Ա�\t\tѧԺ\t\t��Ŀ\n");
    for (int i = 0; i < *lengthOfData; i++) {
        printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", data[i].serial, data[i].ID, data[i].name,
               getSex(data[i].sex), data[i].college,
               data[i].projectName);
    }
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t\t\tɾ��(1)\t�޸�(2)\t����(3)\t����(0)\n");
}

void editSearchResult(struct athlete data[], struct athlete oldData[],int *lengthOfData, int n) {


    switch (n) {
        case 0: //TODO ������һ��
            viewMenu();
            break;
        case 1:
            deleteSearchResult(data, lengthOfData);
            break;
        case 2:
            change(data,lengthOfData); //�޸Ľ����󣬱ȶ����ݵ���Ž������ݺϲ�
            viewMenu();
            break;
        case 3:
            search(data, lengthOfData);
            break;
    }
}


//��ѯ
void search(struct athlete data[], int *lengthOfData) {
    int deleteNum[100];
    int flag = 0;
    char key[20];
    int targetNum[100];
    int j = 0;
    int lengthOfTemp = 0;
    struct athlete tempForSearch[666];


    printf("��ѡ����������ؼ��ʣ���š�ѧ�š�������ѧԺ������Ŀ)\n");
    scanf("%s", key);

    for (int i = 0; i < *lengthOfData; i++) {

        char serial[20];
        //sprintf(serial, " %d", data[i].serial); //����ֵת��Ϊ�ַ���
        itoa(data[i].serial, serial, 10);
//        printf("\n�����±�Ϊ��%d:%s\n",data[i].serial,serial);

        if (strcmp(key, data[i].name) == 0) {
            targetNum[j] = i;
            lengthOfTemp++;
            j++;
        } else if (strcmp(key, data[i].college) == 0) {
            targetNum[j] = i;
            lengthOfTemp++;
            j++;
        } else if (strcmp(key, data[i].projectName) == 0) {
            targetNum[j] = i;
            lengthOfTemp++;
            j++;
        } else if (strcmp(key, data[i].ID) == 0) {
            targetNum[j] = i;
            lengthOfTemp++;
            j++;
        } else if (strcmp(key, serial) == 0) {
            targetNum[j] = i;
            lengthOfTemp++;
            j++;
        }
    }
    int q = 0;
    int l = 0;
    for (int i = 0; i < *lengthOfData; i++) {
        for (int k = q; k < j; k++) {
            if (i == targetNum[k]) {
                tempForSearch[l] = data[i];
                tempForSearch[l].serial = data[i].serial;
                l++;
//                printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\n",i,temp[i].name,getSex(temp[i].sex),temp[i].college,temp[i].projectName);
                q++;//�´ξͲ����ٱȽ��ҵ���������
                break;
            }
        }
    }
    viewSearchResult(tempForSearch, &lengthOfTemp);
    if (lengthOfTemp < 2) editSearchResult(tempForSearch,data, &lengthOfTemp, getItemNum(0, 2, "��������ţ�"));
    else editSearchResult(tempForSearch,data ,&lengthOfTemp, getItemNum(0, 3, "��������ţ�"));
    viewSearchResult(tempForSearch, &lengthOfTemp);

    system("pause");
    viewMenu();
}


//���Խ��������޸�
void change(struct athlete data[], int *length) {

    char name[NAMELENGTH];

    printf("��ѡ���޸����� (1)���� (2)ѧ�� (3)�Ա� (4)��Ŀ (0)ȡ��\n");
    switch (getItemNum(0,4,"��������ţ�")){
        case 0: return;
        case 1:
            printf("������Ҫ���ĵ�������");
            scanf("%s",name);

            for(int i = 0 ;i < *length;i++){
                strcpy(temp[data[i].serial].name,name); //������ֵ
                for(int j = 0 ; j < itemNum; j++){
                    if(strcmp(temp[j].ID, temp[data[i].serial].ID)==0){ //��ͬѧ�ŵļ�¼ִ����ͬ����
                        strcpy(temp[j].name,name);
                    }
                }
            }
            loadRecords();
            printf("�޸ĳɹ���");
            system("pause");
            break;

    }




}

void changeProject() {
    int i;
    char name[NAMELENGTH];
    char space[10];

    printf("������Ҫ�޸ĵ���Ŀ���\n");
    i = getItemNum(0, projectNum, "��������ţ�");
    printf("��ѡ��Ҫ�޸ĵ�����ֵ (1)���� (2)�Ա����� (3)ʹ�ó��� (0)ȡ��\n");
    int j = getItemNum(0, projectNum, "�������������");

    switch (j) {
        case 1:
            printf("����������Ŀ����");
            scanf("%s", name);
            strcpy(tempProject[i].name, name);
            printf("�޸ĳɹ���");
            system("pause");
            viewMenu();
            break;
        case 2:
            printf("�������Ա����� (0)�� (1)Ů (2)��Ů����\n");
            tempProject[i].sex = getItemNum(0, 2, "���������:");
            printf("�޸ĳɹ���%s���Ա�����Ϊ%d", tempProject[i].name, tempProject[i].sex);
            readProjectList();
            system("pause");
            viewMenu();
            break;
        case 3:
            printf("�������µĳ��أ�");
            scanf("%s", space);
            strcpy(tempProject[i].space, space);
            printf("�޸ĳɹ���");
            system("pause");
            viewMenu();
            break;
        case 0:
            viewMenu();
            break;
    }

}

void addProject() {
    //���򳡡��˶���
    printf("������������Ŀ��Ϣ����Ŀ�� ���� (��һ���ո����)\n");
    scanf("%s%s", tempProject[projectNum].name, tempProject[projectNum].space);
//    printf("%s�������ø���Ŀ���Ա�Ҫ��(0)�� (1)Ů (2)��Ů����\n", tempProject[projectNum].name);
//
//    tempProject[projectNum].sex = getItemNum(0, 2, "��������ţ�");
//    //scanf("%d",&tempProject[projectNum].sex);
    //������Ŀר���ļ�
    char path[30] = "g:\\";
    char fileName[20];
    printf("�����ø���Ŀ�ı����ļ���\n");
    scanf("%s", fileName);
    strcat(path, fileName);
    strcat(path, ".txt");
    strcat(tempProject[projectNum].path, path);
    createProjectFile(path);

    projectNum++;

    system("cls");

    printf("\t\t\t*******************************************************************\n");
    printf("\t\t\t���\t\t��Ŀ\t\t\t����\t\t\n");
    printf("\t\t\t��������������������������������������������������������������������\n");
    readProjectList();
    printf("\t\t\t*******************************************************************\n");
    //�ظ�ȷ��
    if (ifGoOn("���") == 0) {
        addProject();
    } else viewMenu();

}

void edit(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            add();
            break;
        case 2:
            delete();
            break;
        case 3:
            change(temp,&itemNum);
            break;
        case 4:
            addProject();
            break;
        case 5:
            loadSerial(temp,itemNum); //�������е����
            for(int i = 0; i < itemNum; i++)
                printf("%d\t",temp[i].serial);
            printf("\n");
            search(temp, &itemNum);
            break;
    }
}

void deleteProject() {
    int no = getItemNum(0, projectNum, "������Ҫɾ������Ŀ��ţ�");
    char c;
    printf("����Ŀ����%d���˶�Ա������ȷ��ע���� y/n \n", tempProject[no].num);
    do {
        c = (char) getchar();
    } while (c != 'y' & c != 'n');

    if (c == 'n') viewMenu();

    for (int i = 0; i < itemNum; i++) {   //ɾ������Ŀ�����б�����Ϣ
        printf("����Ŀ��Ϊ%s\n", tempProject[no].name);
        printf("��%dλ�˶�Ա%s����%s\t", i,temp[i].name, temp[i].projectName);
        if (strcmp(tempProject[no].name, temp[i].projectName) == 0) {
            deleteSingle(temp, i, &itemNum);
            i--;
            printf("ɾ��\n");
        } else printf("pass\n");
    }
    for (int i = no; i < projectNum; i++) {  //ɾ�����鵥��Ԫ��
        tempProject[i] = tempProject[i + 1];
    }
    projectNum--;
    system("pause");
    viewMenu();
}

void editProject(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            addProject();
            break;
        case 2:
            deleteProject();
            break;
        case 3:
            changeProject();
            break;
    }
}