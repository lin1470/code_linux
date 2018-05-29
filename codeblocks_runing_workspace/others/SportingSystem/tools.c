#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "data.h"

//����˵�����з�Χ�ж�
int getItemNum(int min,int max,char hint[]){
    int n;
    do{
        printf("%s",hint);
        scanf("%d",&n);
        if(n<min || n>max) fflush(stdin);
    }while(n<min || n>max);

    return n;
}
//����·��
FILE *getPath(char hint[],FILE *fp){
    static char path[50];

    do{
        printf("%s",hint);
        scanf("%s",path);
    }while((fp = fopen(path,"r"))==NULL);

    return fp;
}


char *getSex(int i){

    static char college[10];

    switch (i){
        case 0:
            strcpy(college,"��");
            return college;
        case 1:
            strcpy(college,"Ů");
            return college;
        default:
            strcpy(college,"Ů");
            return college;

    }
}

int checkID(char ID[]){ //����ID�Ƿ��Ѿ������ڱ������У������ش��ڵ�����
    int num = 0;
    for (int i = 0; i < itemNum; i++) {
        if (strcmp(ID, temp[i].ID)==0) {
            num ++;
        }
    }
    return  num;
}

int checkMessage(struct athlete *a){ //���ָ��ѧ�ŵ��˶�Ա��Ϣ�Ƿ�������б�������趨
    int t = -1;

    for (int i = 0; i < itemNum; i++) {
        if (strcmp(a->ID, temp[i].ID)==0) {
            t = i;
            if(strcmp(a->projectName,temp[i].projectName)==0) return 0; //�жϸ�ID������Ŀ�Ƿ��ظ�
        }
    }
    if(t < 0) return 0; //���������ID
    if(strcmp(a->name,temp[t].name)!=0) return 0;
    if(strcmp(a->college,temp[t].college)!=0) return 0;
    if(a->sex != temp[t].sex) return 0;

    return 1; //����ԭ��������Ϣ


}

void loadSerial(struct athlete data[],int length){
    for(int i = 0; i < length; i++){
        data[i].serial = i;
    }
}

int isProjectExit(char name[]){
    for(int i = 0; i < projectNum; i++){
        if(strcmp(name,tempProject[i].name)==0){ //������Ŀi���򷵻���Ŀ���±�+1
            return i+1;
        }
    }
    return 0;
}

int getSexNum(char *sex){
        char tempSex[2];
    if(strcmp(sex,"��") == 0) return 0;
    if(strcmp(sex,"Ů") == 0) return 1;

    return 2;
}

//��������ת��Ϊʱ��
char *getTime(int time){
    static char *s;
    char s1[10];
    char s2[10];
    sprintf(s,"%d",time/60);
    strcat(s1,":");
    sprintf(s2,"%d",time % 60);
    strcat(s1,s2);
    strcpy(s,s1);
    return s;
}

extern int projectNum;
extern struct project tempProject[50];

int isProject(char name[]){
    for(int i = 0; i < projectNum;i++){
        if(strcmp(tempProject[i].name,name)==0){
            return 0;
        }
    }
    return 1;
}

int ifGoOn(char editName[]){
    char c;
    printf("%s�ɹ�����Ҫ����%s�� y/n \n",editName,editName);
    do {
        c = (char) getchar();
    }
    while(c != 'y' & c != 'n' );

    if(c == 'y')return 0;
        else return 1;
}

char *getName(int length,char hint[]){
    int n;
    static char s[10];
    char c;
    int p = 0;

//    do{
//        printf("%s",hint);
//        scanf("%s",s);
//        if(n<length || n>) fflush(stdin);
//    }while(n<min || n>max);
//
    while((c = (char)getch()) !=  '\r'){
        if(c==8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
        {
            putchar('\b');
            putchar(' ');
            putchar('\b');
            if(p>0)//���ֻ��ɾ��û���ַ�
                p--;
        }
        if(c < 0x40 || c >= 0xFF)//�ж��Ƿ��Ǻ����ַ�������������
            continue;
        putchar(c);
        s[p++] = c;
    }
    s[p] = '\0';
    return s;
}