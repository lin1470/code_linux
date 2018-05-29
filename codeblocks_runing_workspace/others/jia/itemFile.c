#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include "data.h"

int itemNum = 0;//数据条数
int projectNum = 0; //项目条数
int sortNum = 0;
struct athlete temp[666];
struct project tempProject[50];

//加载报名表资料以及项目资料
void loadData() {
    FILE *file;
    // 判断文件是否能够正确创建/打开
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

    //读取项目数据
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

//保存报名表资料
void saveData() {
    FILE *file;
    if ((file = fopen(DATAPATH, "w+")) == NULL) {
        perror(DATAPATH);
        exit(1);
    }
    for (int i = 0; i < itemNum; i++) {
        fprintf(file, "%s\t%s\t%d\t%s\t%s", temp[i].ID, temp[i].name, temp[i].sex, temp[i].college,
                temp[i].projectName);
        //防止文件以回车键结尾
        if (i != itemNum - 1) fprintf(file, "\n");
    }
    fclose(file);

    //保存项目数组
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

    //保存单个文件的报名数据
    for (int i = 0; i < projectNum; i++) {
        if ((file = fopen(tempProject[i].path, "w")) == NULL) {
            perror(tempProject[i].path);
            exit(3);
        }
        printf("正在保存%s文件到%s中\n",tempProject[i].name,tempProject[i].path);
        for (int j = 0; j < tempProject[i].num; j++) {
            if(tempProject[i].record[j].grade == NULL)
                strcpy(tempProject[i].record[j].grade,"0") ;
            fprintf(file, "%s\t%s\t%s\t%s\n", tempProject[i].record[j].name,getSex(tempProject[i].record[j].sex),tempProject[i].record[j].ID, "0");
            printf("%s\t%s\t%s\n", tempProject[i].record[j].name,tempProject[i].record[j].ID,"0");
        }
        fclose(file);
    }
}

//查看报名情况
void view() {
    printf("\t\t\t****************************************************************************************\n");
    printf("\t\t\t*序号\t学号\t\t姓名\t\t性别\t\t学院\t\t项目\t\t*\n");
    printf("\t\t\t————————————————————————————————————————————\n");

    for (int i = 0; i < itemNum; i++) {
        printf("\t\t\t* %-6d %-15s %-15s %-15s %-15s %-15s*\n", i, temp[i].ID, temp[i].name, getSex(temp[i].sex),
               temp[i].college, temp[i].projectName);
    }
    printf("\t\t\t*****************************************************************************************\n");
    printf("\t\t\t\t\t增加(1)\t删除(2)\t修改(3)\t查找(4)\t返回(0)\n");

};

void readProjectList() {
    for (int i = 0; i < projectNum; i++) {
        printf("\t\t\t%-6d\t\t%-15s\t\t%-15s\n", i, tempProject[i].name, tempProject[i].space);
    }
}


//查看项目情况
void viewProject() {
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t序号\t\t项目\t\t\t场地\n");
    printf("\t\t\t——————————————————————————————————\n");
    readProjectList();
    printf("\t\t\t********************************************************************\n");
    printf("\t\t\t\t\t增加(1)\t删除(2)\t修改(3)\t返回(0)\n");
    editProject(getItemNum(0, 3, "请输入序号："));
};

void import() {
    char importPath[50];
    FILE *fp = NULL;
    int invalidNum = 0;
    int totalNum = 0;
    int subscript = 0;

//    do{
//        printf("请输入要导入文件的绝对路径：\n");
//
//        scanf("%s", importPath);
//
//    };
    fp = getPath("请输入导入文件的绝对路径:",fp);

    char tempSex[10] ;
    while (fscanf(fp, "%s\t%s\t%d\t%s\t%s\n", temp[itemNum].ID,temp[itemNum].name,
                  &temp[itemNum].sex, temp[itemNum].college, temp[itemNum].projectName) != EOF) {
        totalNum++;
        //temp[itemNum].sex = getSexNum(tempSex);
        //TODO 要考虑一个人报多个项目的情况
        if((subscript = isProjectExit(temp[itemNum].projectName))==0){
            invalidNum++;
        } else if(checkID(temp[itemNum].ID) >= 3){ //如果该学号报了超过3个项目就直接否掉啦
            invalidNum++;
        } else if(checkID(temp[itemNum].ID)>0){ //存在ID且其所报的项目不超过3，要分类谈论
            if(checkMessage(&temp[itemNum])==1) {
                subscript--;
                strcpy(tempProject[subscript].record[tempProject[subscript].num].ID,temp[itemNum].ID);
                strcpy(tempProject[subscript].record[tempProject[subscript].num].name,temp[itemNum].name);
                tempProject[subscript].record[tempProject[subscript].num].sex = temp[itemNum].sex;
                tempProject[subscript].num++;
                itemNum++;
            } else  invalidNum++;
        } else{ //对应项目的record要做相应变化
            subscript--;
            strcpy(tempProject[subscript].record[tempProject[subscript].num].ID,temp[itemNum].ID);
            strcpy(tempProject[subscript].record[tempProject[subscript].num].name,temp[itemNum].name);
            tempProject[subscript].record[tempProject[subscript].num].sex = temp[itemNum].sex;
            tempProject[subscript].num++;
            itemNum++;
        }
    }
    fclose(fp);
    printf("文件导入完毕，共有%d条数据，其中有%d条无效数据。\n",totalNum,invalidNum);
    system("pause");
    viewMenu();
}

//“文件”选项
void file(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            view();
            int i = getItemNum(0, 4, "请输入菜单项：");
            if (i == 1 && projectNum == 0) {
                printf("请先建立参赛项目！\n");
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
            printf("保存成功，按任意键继续...");
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