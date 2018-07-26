#ifndef SPORTMEETING_H_INCLUDED
#define SPORTMEETING_H_INCLUDED
typedef struct
{
	char name[20];
	int code;
	float score;
}project_player;//运动员参加的其中一个运动，里面有该项运动的名字，运动编码，成绩。区别下面定义的具体的运动项目的种类，
//这个是在我们计算运动员成绩的时候会用到的。加油

typedef struct
{
	int	 playerCode;
	char playerName[10];
	char  gender[4];
	char  college[20];
	project_player pro[3];
}player;//定义运动员具体信息，里面有他的编码，他的名字，性别，学院，参加的三项的运动。//运动员成绩录入的时候回
//用到的。加油

typedef struct
{
	int code;
	char name[20];
	int placeCode;
	char place[20];
	int numberOfPlayerPerGroup;
	int timeOfGroup;
	char unitOfMeasureMent[4];
}project;//运动的项目，在我们录入运动项目的时候会用到的。加油。

typedef struct
{
	int		projectCode;
	char		projectName[20];
	int		countOfPlayer;
	int		 estimatedTime;
} time_take;//这个在计算时间分配的时候需要用到的。

typedef struct
{
	int  projectCode;
	char projectName[20];
	int  isConflict;
} conflict;//计算时间冲突的时候需要用到

typedef struct
{
	int projectCode;
	char projectName[20];
	int timeCode;
} distribution;//时间分配的时候需要用到的
void bound(char ch, int n);//单纯的就是用来画一整条横线的。
void main_surface();//主界面；
char* string_link(char *str1, char *str2);//用来连接两个字符串的，其实这个连接的可以用那个来直接连接，不过添加了
//自动检查的功能
int printf_pro_data();//打开一个项目表目录，并且逐一来查看这些项目。最后返回项目数
int printf_playerList_data(char *fileName);
int did_delete_or_modify();//来提示是否删除或者更新的。
void delete_project();//删除一个项目用于在管理员删除项目的时候用的。
void add_project();//用于管理员来添加其中的一个项目。
int  count_playerCode();//计算一个运动员
void player_join();//运动员报名的时候要用。
void modify_project();//用于运动员修改项目。
void create_player_of_project();//各个项目的运动员的目录。
void create_time_of_estimation();//生成每个项目的时间估算表。
void create_conflict_of_project();//生成项目冲突表。
void create_time_of_distribution();
void query_score();
void enter_result();
void query_dirtribution();
void main_menu();
int check_account();
void main_surface();

#endif // SPORTMEETING_H_INCLUDED
