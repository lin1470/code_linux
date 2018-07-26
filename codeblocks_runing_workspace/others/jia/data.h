//
// Created by 10388 on 2017/3/4.
//
#ifndef SPORTINGSYSTEM_DATA_H
#define DATAPATH "g:\\entryForm.txt"
#define PASSPATH "g:\\password.txt"
#define PROJECTPATH "g:\\projectForm.bat"
#define NAMELENGTH  10
#define SPACELENGTH 10
#define SpaceNum 10
#endif //SPORTINGSYSTEM_DATA_H


struct athlete{
    char name[NAMELENGTH];
    //char sex[2];
    int sex;
    char college[20];
    char projectName[NAMELENGTH];
    int score;
    char ID[30];
    int serial;
}temp[666];

struct time{
    int beginTime;
    int endTime;
};

struct project{
    char name[NAMELENGTH];
    char space[SPACELENGTH];
    //文件保存路径
    char path[50];
    //保存成绩
    struct { char ID[30]; char name[NAMELENGTH];char grade[10]; int sex; }record[100]; //
    struct time timeRange;
    int sex;
    int num;//
}tempProject[50];

struct {
    struct project p[100];
    int length;
    char space[SPACELENGTH];
}spaceGroup[SpaceNum];

int times; //时间组的长度

struct Tgroup{
    struct project p[100];
    int length;
    struct time;
}timeGroup[SpaceNum];

int sortNum;
int getState();
void check();

int itemNum;
int projectNum; //项目条数
int getSexNum(char *i);

//tools
int getItemNum(int min, int max, char hint[]);
int checkID(char ID[]);
int isProjectExit(char name[]);
FILE *getPath(char hint[],FILE *fp);
int checkMessage(struct athlete *a);
int ifGoOn(char i[]);
char *getSex(int i);
void loadSerial(struct athlete data[],int length);

//Edit
void editProject(int n);
void edit(int n);
void search(struct athlete data[],int *lengthOfData);

//File
void file(int n);
void view();
void saveData();
void loadData();
void createProjectFile(char path[]);
void readProjectList();
void viewProject();
void viewMenu();
void loadRecords();

//Manage
int state;
char password[20];
int getState();
void saveState();
void changeState();
void setPassword();

//control
void makeOrder();
