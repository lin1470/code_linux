#include <mem.h>
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

#define TimeMaxNum 20

struct time T[TimeMaxNum];

void sortOut() { //对项目进行场地分类
    //没读到数据则返回0,读到不同的场地，则sortNum增加
    printf("项目条数%d\n", projectNum);
    for (int j = 0; j < projectNum ; j++) {
        int flag = 0;
        //printf("加载%s\n", tempProject[j].name);
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
            sortNum++; //该项目使用了新场地
        }
    }
    printf("场地种类有：%d\n", sortNum);
    //system("pause");

}


int judge(struct project p1, struct project p2) { //判断有没有同一个运动员报名这两个项目
    //TODO 读取记录
    for (int i = 0; i < p1.num; i++) {
        for (int j = 0; j < p2.num; j++) {
            if (strcmp(p1.record[i].ID, p2.record[j].ID) == 0) { //出现学号相同的报名记录
                printf("两项目发生报名冲突！\n");
                return 0;
            }
        }
    }
    return 1;
}

//int beginX = 0; //spaceGroup起始组数
//int beginY = 0; //spaceGroup起始元素数
//int beginZ = 0; //timeGroup起始组数
int getOrder(int beginX, int beginY, int beginZ) {
    int i = 0;
    int flag = 0;
    int beginW = 0; //timeGroup起始元素数
    //spaceGroup[beginX].p[beginY].timeRange = T[times];
    if (spaceGroup[beginX].p[beginY].timeRange.beginTime != 0) return beginZ; //该项目已经被添加,beginZ不改变
    times++; //时间组长度+1
    spaceGroup[beginX].p[beginY].timeRange.beginTime = beginZ + SpaceNum;
    timeGroup[beginZ].p[beginW] = spaceGroup[beginX].p[beginY];
    timeGroup[beginZ].length++;
    printf("timeGroup:%s\n", timeGroup[beginZ].p[beginW].name);

    for (int j = beginX + 1; j < sortNum; j++) { //j表示场地序号
        i = 0;
        while (i < spaceGroup[j].length) { //i表示项目序号
            flag = 0;
            printf("正在判定项目%s\n", spaceGroup[j].p[i].name);
            for (int m = 0; m < timeGroup[beginZ].length; m++) { //用于遍历之前的项目
                if (!judge(spaceGroup[j].p[i], timeGroup[beginZ].p[m]) ||
                    spaceGroup[j].p[i].timeRange.beginTime != 0) { //项目发生冲突,或者已经被添加到前面的时间组
                    i++;
                    flag = 1;
                    break;
                }
            }
            if (!flag) { //与上一个选取项目没有发生冲突,则添加，并到下一组去找
                printf("没有发生冲突,添加%s,现在该时间组长度为：%d\n", spaceGroup[j].p[i].name, timeGroup[beginZ].length);
                spaceGroup[j].p[i].timeRange.beginTime = beginZ + SpaceNum; //用了一种比较low的方式表示该项目已被添加过
                timeGroup[beginZ].p[timeGroup[beginZ].length] = spaceGroup[j].p[i];
                timeGroup[beginZ].length++;
//                printf("检测:%s",timeGroup[beginZ].p[timeGroup[beginZ].length].name);
                break;
            }
        }
    }
//    printf("可以同时进行的项目有：");
//    for (int q = 0; q < timeGroup[beginZ].length; q++) {
//        printf("该组第%d项为%s\t", q, timeGroup[beginZ].p[q].name);
//        printf("beginZ = %d\n",beginZ);
//    }
//    system("pause");

    return beginZ + 1;
}

void showOrder(){
    printf("\n-------------------------------------------\n");
    for(int i = 0; i < times; i++){
        printf("第%d时间段举行:",i+1);
        for (int q = 0; q < timeGroup[i].length; q++) { //打印可以放在第一时间段的项目
            printf("%s\t" ,timeGroup[i].p[q].name);
        }
        printf("\n-------------------------------------------\n");
    }

}
void showOrderInDetail(){
    char hint[10];
    strcpy(hint,"女");

    printf("\n-------------------------------------------\n");
    for(int i = 0; i < times * 2; i++){
        if(strcmp(hint,"女")==0) strcpy(hint,"男");
            else strcpy(hint,"女");
        printf("第%d时间段举行%s子比赛:\n",i+1,hint);
        printf("-------------------------------------------\n");
        for (int q = 0; q < timeGroup[i / 2 ].length; q++) {
            printf("   *%s*\n" ,timeGroup[i / 2].p[q].name);
            for(int j = 0; j < timeGroup[i / 2].p[q].num; j++){
                if(strcmp(getSex(timeGroup[i / 2].p[q].record[j].sex),hint) == 0) //性别相符才打印
                    if(strcmp(timeGroup[i / 2].p[q].record[j].name,"")!=0)
                    printf("\t%s(%s)",timeGroup[i / 2].p[q].record[j].name,timeGroup[i/2].p[q].record[j].ID);
            }
            printf("\n");
        }
        printf("\n-------------------------------------------\n");
    }

}

void makeOrder() {
    //初始化
    sortNum = 0;
    memset(spaceGroup,0,sizeof(spaceGroup));
    sortOut();
    times = 0;
    memset(timeGroup, 0, sizeof(timeGroup)); //初始化结构体数组

    int q = 0;
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < spaceGroup[i].length; j++) {
            //printf("%s\n", spaceGroup[i].p[j].name);
            q = getOrder(i, j, q);
        }
    }
    system("pause");
    system("cls");
    //显示秩序册
    showOrderInDetail();
    //很Low的方式，去标记化
    for (int i = 0; i < sortNum; i++) {
        for (int j = 0; j < spaceGroup[i].length; j++) {
            spaceGroup[i].p[j].timeRange.beginTime = 0;
        }
    }
    system("pause");
    viewMenu();


}


