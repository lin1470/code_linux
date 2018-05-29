
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "data.h"

//添加运动员信息
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
        printf("请输入学号：\n");
        scanf("%s", ID);
        //验证学号
        for (int i = 0; i < itemNum; i++) {
            if (strcmp(ID, temp[i].ID) == 0) {
                mark++;
                t = i;
            }
        }
        if (mark > 0) {
            printf("已有记录：%s\t%s\t%s\n", temp[t].name, getSex(temp[t].sex), temp[t].college);
            if (mark >= 3) {
                printf("该学号已被注册且参加了%d个项目，(1)重新输入学号 (0)返回菜单\n", mark);
                switch (getItemNum(0, 1, "请输入序号：")) {
                    case 0:
                        viewMenu();
                        break;
                    case 1:
                        flag = 1;
                        break;
                }
            } else {
                printf("该学号已被注册，(1)使用该学号相关信息 (2)重新输入学号 (0)返回菜单\n");
                switch (getItemNum(0, 2, "请输入序号：")) {
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
            printf("请依次输入运动员基本信息：姓名 性别 学院(用一个空格隔开)\n");
            scanf("%s %s %s", name, sex, college);
            flag = 0;
        }
    } while (flag == 1);

    printf("\t\t\t****************************************************************\n");
    printf("\t\t\t序号\t\t项目\t\t\t场地\n");
    printf("\t\t\t————————————————————————————————\n");
    readProjectList();
    printf("\t\t\t****************************************************************\n");
    do {
        flag = 0;
        no = getItemNum(0, projectNum, "请输入参赛项目的对应序号：");
        for (int i = 0; i < tempProject[no].num; i++) {
            if (strcmp(ID, tempProject[no].record[i].ID) == 0) { //检测到被选取项目中有相同学号信息
                printf("被选取项目中存在相同的报名记录 (1)更换其他项目  (0)取消\n");
                int j = getItemNum(0, 1, "请输入序号：");
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
    printf("当前性别为：%d:%s\n", getSexNum(sex), sex);
    temp[itemNum].sex = getSexNum(sex);

    strcpy(tempProject[no].record[tempProject[no].num].name, temp[itemNum].name);
    strcpy(tempProject[no].record[tempProject[no].num].ID, temp[itemNum].ID);
    tempProject[no].record[tempProject[no].num].sex = temp[itemNum].sex;

    //该项目参与人数以及总人数加1
    tempProject[no].num++;
    itemNum++;

    view();
    if (ifGoOn("添加") == 0) {
        system("cls");
        view();
        add();
    } else viewMenu();
}

//单个删除
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

    printf("请输入要删除的运动员序号:");
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

    printf("请输入要删除的运动员姓名:（请以\\分割）\n");
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
            //printf("第%d项%s,比较%s\n", i,temp[i].name, Name[j]);
            if (strcmp(temp[i].name, Name[j]) == 0) {
                printf("删除第%d项\n,它符合%s\n", i, Name[j]);
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

    printf("请输入要删除的学院名:（请以\\分割）\n");
    scanf("%s", string);

    p = strtok(string, split);

    while (p != NULL) {
        name = p;
        strcpy(Name[length], name);
        length++;
        p = strtok(NULL, split);
    }
    //删除一个元素的同时
    for (int i = 0; i < *lengthOfData; i++) {
        printf("第%d号的学院为%s\n", i, temp[i].college);
        for (int j = 0; j < length; j++) {
            if (strcmp(temp[i].college, Name[j]) == 0) {
                printf("***************************\n");
                printf("删除第%d项\n,它符合%s\n", i, Name[j]);
                deleteSingle(data, i, lengthOfData);
                i--;
            }
        }
    }
}

void delete() {
    char id[30];
    int t = -1;
    printf("按 序号(1) 姓名(2)  学院(3)  学号(4) 删除，返回(0)\n");
    int n = getItemNum(0, 4, "请输入序号：");
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
                printf("请输入学号：(返回请输入n)");
                scanf("%s", id);
                if (strcmp(id, "n") == 0) break;
                for (int i = 0; i < itemNum; i++) {
                    if (strcmp(id, temp[i].ID) == 0) {
                        t = i;
                        break;
                    }
                }
                if (t < 0) printf("查无此号\n");
            } while (t < 0);
            deleteSingle(temp, t, &itemNum);
            break;
        case 0:
            viewMenu();
            return;
    }
    view();
    if (ifGoOn("删除") == 0) {
        delete();
    } else viewMenu();

}

void deleteSearchResult(struct athlete data[], int *lengthOfData) {
    printf("按 序号(1) 姓名(2)  学院(3) 删除，返回(0)\n");
    int n = getItemNum(0, 3, "请输入序号");
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
    printf("\t\t\t序号\t\t学号\t\t姓名\t\t性别\t\t学院\t\t项目\n");
    for (int i = 0; i < *lengthOfData; i++) {
        printf("\t\t\t%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n", data[i].serial, data[i].ID, data[i].name,
               getSex(data[i].sex), data[i].college,
               data[i].projectName);
    }
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t删除(1)\t修改(2)\t查找(3)\t返回(0)\n");
}

void editSearchResult(struct athlete data[], struct athlete oldData[],int *lengthOfData, int n) {


    switch (n) {
        case 0: //TODO 返回上一级
            viewMenu();
            break;
        case 1:
            deleteSearchResult(data, lengthOfData);
            break;
        case 2:
            change(data,lengthOfData); //修改结束后，比对数据的序号进行数据合并
            viewMenu();
            break;
        case 3:
            search(data, lengthOfData);
            break;
    }
}


//查询
void search(struct athlete data[], int *lengthOfData) {
    int deleteNum[100];
    int flag = 0;
    char key[20];
    int targetNum[100];
    int j = 0;
    int lengthOfTemp = 0;
    struct athlete tempForSearch[666];


    printf("请选择输入检索关键词（序号、学号、姓名、学院或者项目)\n");
    scanf("%s", key);

    for (int i = 0; i < *lengthOfData; i++) {

        char serial[20];
        //sprintf(serial, " %d", data[i].serial); //将数值转换为字符串
        itoa(data[i].serial, serial, 10);
//        printf("\n检索下标为：%d:%s\n",data[i].serial,serial);

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
                q++;//下次就不用再比较找到的数据了
                break;
            }
        }
    }
    viewSearchResult(tempForSearch, &lengthOfTemp);
    if (lengthOfTemp < 2) editSearchResult(tempForSearch,data, &lengthOfTemp, getItemNum(0, 2, "请输入序号："));
    else editSearchResult(tempForSearch,data ,&lengthOfTemp, getItemNum(0, 3, "请输入序号："));
    viewSearchResult(tempForSearch, &lengthOfTemp);

    system("pause");
    viewMenu();
}


//可以进行批量修改
void change(struct athlete data[], int *length) {

    char name[NAMELENGTH];

    printf("请选择修改属性 (1)姓名 (2)学号 (3)性别 (4)项目 (0)取消\n");
    switch (getItemNum(0,4,"请输入序号：")){
        case 0: return;
        case 1:
            printf("请输入要更改的姓名：");
            scanf("%s",name);

            for(int i = 0 ;i < *length;i++){
                strcpy(temp[data[i].serial].name,name); //姓名赋值
                for(int j = 0 ; j < itemNum; j++){
                    if(strcmp(temp[j].ID, temp[data[i].serial].ID)==0){ //对同学号的记录执行相同操作
                        strcpy(temp[j].name,name);
                    }
                }
            }
            loadRecords();
            printf("修改成功！");
            system("pause");
            break;

    }




}

void changeProject() {
    int i;
    char name[NAMELENGTH];
    char space[10];

    printf("请输入要修改的项目序号\n");
    i = getItemNum(0, projectNum, "请输入序号：");
    printf("请选择要修改的属性值 (1)名称 (2)性别限制 (3)使用场地 (0)取消\n");
    int j = getItemNum(0, projectNum, "请输入操作数：");

    switch (j) {
        case 1:
            printf("请输入新项目名：");
            scanf("%s", name);
            strcpy(tempProject[i].name, name);
            printf("修改成功！");
            system("pause");
            viewMenu();
            break;
        case 2:
            printf("请设置性别限制 (0)男 (1)女 (2)男女不限\n");
            tempProject[i].sex = getItemNum(0, 2, "请输入序号:");
            printf("修改成功！%s的性别限制为%d", tempProject[i].name, tempProject[i].sex);
            readProjectList();
            system("pause");
            viewMenu();
            break;
        case 3:
            printf("请输入新的场地：");
            scanf("%s", space);
            strcpy(tempProject[i].space, space);
            printf("修改成功！");
            system("pause");
            viewMenu();
            break;
        case 0:
            viewMenu();
            break;
    }

}

void addProject() {
    //篮球场、运动场
    printf("请依次输入项目信息：项目名 场地 (用一个空格隔开)\n");
    scanf("%s%s", tempProject[projectNum].name, tempProject[projectNum].space);
//    printf("%s，请设置该项目的性别要求：(0)男 (1)女 (2)男女不限\n", tempProject[projectNum].name);
//
//    tempProject[projectNum].sex = getItemNum(0, 2, "请输入序号：");
//    //scanf("%d",&tempProject[projectNum].sex);
    //创建项目专用文件
    char path[30] = "g:\\";
    char fileName[20];
    printf("请设置该项目的保存文件名\n");
    scanf("%s", fileName);
    strcat(path, fileName);
    strcat(path, ".txt");
    strcat(tempProject[projectNum].path, path);
    createProjectFile(path);

    projectNum++;

    system("cls");

    printf("\t\t\t*******************************************************************\n");
    printf("\t\t\t序号\t\t项目\t\t\t场地\t\t\n");
    printf("\t\t\t——————————————————————————————————\n");
    readProjectList();
    printf("\t\t\t*******************************************************************\n");
    //重复确认
    if (ifGoOn("添加") == 0) {
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
            loadSerial(temp,itemNum); //加载现有的序号
            for(int i = 0; i < itemNum; i++)
                printf("%d\t",temp[i].serial);
            printf("\n");
            search(temp, &itemNum);
            break;
    }
}

void deleteProject() {
    int no = getItemNum(0, projectNum, "请输入要删除的项目序号：");
    char c;
    printf("该项目共计%d名运动员报名，确认注销？ y/n \n", tempProject[no].num);
    do {
        c = (char) getchar();
    } while (c != 'y' & c != 'n');

    if (c == 'n') viewMenu();

    for (int i = 0; i < itemNum; i++) {   //删除该项目的所有报名信息
        printf("该项目名为%s\n", tempProject[no].name);
        printf("第%d位运动员%s报名%s\t", i,temp[i].name, temp[i].projectName);
        if (strcmp(tempProject[no].name, temp[i].projectName) == 0) {
            deleteSingle(temp, i, &itemNum);
            i--;
            printf("删除\n");
        } else printf("pass\n");
    }
    for (int i = no; i < projectNum; i++) {  //删除数组单个元素
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