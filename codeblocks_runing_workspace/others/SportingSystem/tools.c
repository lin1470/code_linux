#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "data.h"

//读入菜单项，进行范围判断
int getItemNum(int min,int max,char hint[]){
    int n;
    do{
        printf("%s",hint);
        scanf("%d",&n);
        if(n<min || n>max) fflush(stdin);
    }while(n<min || n>max);

    return n;
}
//读入路径
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
            strcpy(college,"男");
            return college;
        case 1:
            strcpy(college,"女");
            return college;
        default:
            strcpy(college,"女");
            return college;

    }
}

int checkID(char ID[]){ //检测该ID是否已经存在于报名表中，并返回存在的数量
    int num = 0;
    for (int i = 0; i < itemNum; i++) {
        if (strcmp(ID, temp[i].ID)==0) {
            num ++;
        }
    }
    return  num;
}

int checkMessage(struct athlete *a){ //检测指定学号的运动员信息是否符合已有报名表的设定
    int t = -1;

    for (int i = 0; i < itemNum; i++) {
        if (strcmp(a->ID, temp[i].ID)==0) {
            t = i;
            if(strcmp(a->projectName,temp[i].projectName)==0) return 0; //判断该ID报的项目是否重复
        }
    }
    if(t < 0) return 0; //不存在这个ID
    if(strcmp(a->name,temp[t].name)!=0) return 0;
    if(strcmp(a->college,temp[t].college)!=0) return 0;
    if(a->sex != temp[t].sex) return 0;

    return 1; //符合原报名表信息


}

void loadSerial(struct athlete data[],int length){
    for(int i = 0; i < length; i++){
        data[i].serial = i;
    }
}

int isProjectExit(char name[]){
    for(int i = 0; i < projectNum; i++){
        if(strcmp(name,tempProject[i].name)==0){ //存在项目i，则返回项目的下标+1
            return i+1;
        }
    }
    return 0;
}

int getSexNum(char *sex){
        char tempSex[2];
    if(strcmp(sex,"男") == 0) return 0;
    if(strcmp(sex,"女") == 0) return 1;

    return 2;
}

//将分钟数转换为时间
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
    printf("%s成功！还要继续%s吗？ y/n \n",editName,editName);
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
        if(c==8)//实现backspace键的功能，其中backspace键的ascii码是8
        {
            putchar('\b');
            putchar(' ');
            putchar('\b');
            if(p>0)//最多只能删到没有字符
                p--;
        }
        if(c < 0x40 || c >= 0xFF)//判断是否是汉字字符，不是则跳过
            continue;
        putchar(c);
        s[p++] = c;
    }
    s[p] = '\0';
    return s;
}