#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define TimeMaxNum 20

struct time T[TimeMaxNum];

void sortOut() { //����Ŀ���г��ط���
    //û���������򷵻�0,������ͬ�ĳ��أ���sortNum����
    printf("��Ŀ����%d\n", projectNum);
    for (int j = 0; j < projectNum ; j++) {
        int flag = 0;
        //printf("����%s\n", tempProject[j].name);
        for (int q = 0; q < sortNum; q++) {
            if (strcmp(tempProject[j].space, spaceGroup[q].space) == 0) {
                tempProject[j].timeRange.beginTime = 0;
                spaceGroup[q].p[spaceGroup[q].length++] = tempProject[j];
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            strcpy(spaceGroup[sortNum].space, tempProject[j].space);
            spaceGroup[sortNum].p[spaceGroup[sortNum].length++] = tempProject[j];
            sortNum++; //����Ŀʹ�����³���
        }
    }
    printf("���������У�%d\n", sortNum);
    //system("pause");

}


int judge(struct project p1, struct project p2) { //�ж���û��ͬһ���˶�Ա������������Ŀ
    //TODO ��ȡ��¼
    for (int i = 0; i < p1.num; i++) {
        for (int j = 0; j < p2.num; j++) {
            if (strcmp(p1.record[i].ID, p2.record[j].ID) == 0) { //����ѧ����ͬ�ı�����¼
                printf("����Ŀ����������ͻ��\n");
                return 0;
            }
        }
    }
    return 1;
}

//int beginX = 0; //spaceGroup��ʼ����
//int beginY = 0; //spaceGroup��ʼԪ����
//int beginZ = 0; //timeGroup��ʼ����
int getOrder(int beginX, int beginY, int beginZ) {
    int i = 0;
    int flag = 0;
    int beginW = 0; //timeGroup��ʼԪ����
    //spaceGroup[beginX].p[beginY].timeRange = T[times];
    if (spaceGroup[beginX].p[beginY].timeRange.beginTime != 0) return beginZ; //����Ŀ�Ѿ������,beginZ���ı�
    times++; //ʱ���鳤��+1
    spaceGroup[beginX].p[beginY].timeRange.beginTime = beginZ + SpaceNum;
    timeGroup[beginZ].p[beginW] = spaceGroup[beginX].p[beginY];
    timeGroup[beginZ].length++;
    printf("timeGroup:%s\n", timeGroup[beginZ].p[beginW].name);

    for (int j = beginX + 1; j < sortNum; j++) { //j��ʾ�������
        i = 0;
        while (i < spaceGroup[j].length) { //i��ʾ��Ŀ���
            flag = 0;
            printf("�����ж���Ŀ%s\n", spaceGroup[j].p[i].name);
            for (int m = 0; m < timeGroup[beginZ].length; m++) { //���ڱ���֮ǰ����Ŀ
                if (!judge(spaceGroup[j].p[i], timeGroup[beginZ].p[m]) ||
                    spaceGroup[j].p[i].timeRange.beginTime != 0) { //��Ŀ������ͻ,�����Ѿ�����ӵ�ǰ���ʱ����
                    i++;
                    flag = 1;
                    break;
                }
            }
            if (!flag) { //����һ��ѡȡ��Ŀû�з�����ͻ,����ӣ�������һ��ȥ��
                printf("û�з�����ͻ,���%s,���ڸ�ʱ���鳤��Ϊ��%d\n", spaceGroup[j].p[i].name, timeGroup[beginZ].length);
                spaceGroup[j].p[i].timeRange.beginTime = beginZ + SpaceNum; //����һ�ֱȽ�low�ķ�ʽ��ʾ����Ŀ�ѱ���ӹ�
                timeGroup[beginZ].p[timeGroup[beginZ].length] = spaceGroup[j].p[i];
                timeGroup[beginZ].length++;
//                printf("���:%s",timeGroup[beginZ].p[timeGroup[beginZ].length].name);
                break;
            }
        }
    }
//    printf("����ͬʱ���е���Ŀ�У�");
//    for (int q = 0; q < timeGroup[beginZ].length; q++) {
//        printf("�����%d��Ϊ%s\t", q, timeGroup[beginZ].p[q].name);
//        printf("beginZ = %d\n",beginZ);
//    }
//    system("pause");

    return beginZ + 1;
}

void showOrder(){
    printf("\n-------------------------------------------\n");
    for(int i = 0; i < times; i++){
        printf("��%dʱ��ξ���:",i+1);
        for (int q = 0; q < timeGroup[i].length; q++) { //��ӡ���Է��ڵ�һʱ��ε���Ŀ
            printf("%s\t" ,timeGroup[i].p[q].name);
        }
        printf("\n-------------------------------------------\n");
    }

}
void showOrderInDetail(){
    char hint[10];
    strcpy(hint,"Ů");

    printf("\n-------------------------------------------\n");
    for(int i = 0; i < times * 2; i++){
        if(strcmp(hint,"Ů")==0) strcpy(hint,"��");
            else strcpy(hint,"Ů");
        printf("��%dʱ��ξ���%s�ӱ���:\n",i+1,hint);
        printf("-------------------------------------------\n");
        for (int q = 0; q < timeGroup[i / 2 ].length; q++) {
            printf("   *%s*\n" ,timeGroup[i / 2].p[q].name);
            for(int j = 0; j < timeGroup[i / 2].p[q].num; j++){
                if(strcmp(getSex(timeGroup[i / 2].p[q].record[j].sex),hint) == 0) //�Ա�����Ŵ�ӡ
                    if(strcmp(timeGroup[i / 2].p[q].record[j].name,"")!=0)
                    printf("\t%s(%s)",timeGroup[i / 2].p[q].record[j].name,timeGroup[i/2].p[q].record[j].ID);
            }
            printf("\n");
        }
        printf("\n-------------------------------------------\n");
    }

}

void makeOrder() {
    //��ʼ��
    sortNum = 0;
    memset(spaceGroup,0,sizeof(spaceGroup));
    sortOut();
    times = 0;
    memset(timeGroup, 0, sizeof(timeGroup)); //��ʼ���ṹ������

    int q = 0;
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < spaceGroup[i].length; j++) {
            //printf("%s\n", spaceGroup[i].p[j].name);
            q = getOrder(i, j, q);
        }
    }
    system("pause");
    system("cls");
    //��ʾ�����
    showOrderInDetail();
    //��Low�ķ�ʽ��ȥ��ǻ�
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < spaceGroup[i].length; j++) {
            spaceGroup[i].p[j].timeRange.beginTime = 0;
        }
    }
    system("pause");
    viewMenu();


}


