#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#define GENDER_NUMBER 2
#define MAX_PEOPLE_NUMBER 100
#define MAX_PROJECT_NUMBER 7
#define MAX_LENTH 20
#define account "123"
#define password "123"
#define SIZE_OF_PROJECT sizeof(project)
#define SIZE_OF_PLAYER sizeof(player_record)
typedef struct
{
    char projectName[20];
    int projectCode;
    float score;
}project_in_player;
typedef struct
{
	int  playerCode;
	char playerName[10];
	char gender[5];
	char college[20];
	project_in_player project_in[3];
} player_record;//创建一个学生的信息结构里面包含了学号，姓名，性别，学院。
player_record all_players[MAX_PEOPLE_NUMBER];

typedef struct
{
	int projectCode;
	char projectName[20];
	char projectPlace[20];
	int placeCode;
	int numberOfPlayerPerGroup;
	int timeOfGroupTake;
	int heighestRecord;
	char unitOfMeasurement[4];
	int isGroupProject;
	float beganTime,endedTime;
} proj;
typedef struct
{
    proj man;//男子项目eg如果要调用的话我们可以这样使用:project.man.run100.id[0];
    proj womman;//女子项目project.woman.run100.id[0].
}project;
project all_projects[MAX_PROJECT_NUMBER];
int check_account(void);
char* stringLink(char *str1,char *str2);////字符串拼接函数
void addProject(void);////管理员添加运动项目时调用
void login();//登陆时会用到的方法来的
void bound(char c,int a);//用来画分界线的方法
void mainmenu();//这个是手动打印那个界面的。
void admin_manage();//进入管理员管理的时候
void addProject(void);//管理员添加项目的时候需要用到。
int access_project(void);//读取项目文件里面的项目数
void udate_project(void);//更新项目
int show_project(void);//可以显示所有项目的名字用以选择
 project* get_project_from_input(void);//通过输入来来获得一个项目
 void join_project(void);//用以运动员参加项目
 void udapt_playerArray(int);//用以更新运动员数组
 void udapt_projectArray(int);//用以更新项目数组
 player_record* get_player_from_input(void);//通过输入来获得一个运动员的信息。
 player_record* get_player_from_rand(void);//通过随机数来获得一个运动员的信息。
 void show_player(void);//来显示运动员的报名情况，用以检测。
 void show_project_in_detail(void);//用来显示项目的输入情况用以检测
 void creat_project_file(void);//
#endif // STUDENT_H_INCLUDED
