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
} player_record;//����һ��ѧ������Ϣ�ṹ���������ѧ�ţ��������Ա�ѧԺ��
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
    proj man;//������Ŀeg���Ҫ���õĻ����ǿ�������ʹ��:project.man.run100.id[0];
    proj womman;//Ů����Ŀproject.woman.run100.id[0].
}project;
project all_projects[MAX_PROJECT_NUMBER];
int check_account(void);
char* stringLink(char *str1,char *str2);////�ַ���ƴ�Ӻ���
void addProject(void);////����Ա����˶���Ŀʱ����
void login();//��½ʱ���õ��ķ�������
void bound(char c,int a);//�������ֽ��ߵķ���
void mainmenu();//������ֶ���ӡ�Ǹ�����ġ�
void admin_manage();//�������Ա�����ʱ��
void addProject(void);//����Ա�����Ŀ��ʱ����Ҫ�õ���
int access_project(void);//��ȡ��Ŀ�ļ��������Ŀ��
void udate_project(void);//������Ŀ
int show_project(void);//������ʾ������Ŀ����������ѡ��
 project* get_project_from_input(void);//ͨ�������������һ����Ŀ
 void join_project(void);//�����˶�Ա�μ���Ŀ
 void udapt_playerArray(int);//���Ը����˶�Ա����
 void udapt_projectArray(int);//���Ը�����Ŀ����
 player_record* get_player_from_input(void);//ͨ�����������һ���˶�Ա����Ϣ��
 player_record* get_player_from_rand(void);//ͨ������������һ���˶�Ա����Ϣ��
 void show_player(void);//����ʾ�˶�Ա�ı�����������Լ�⡣
 void show_project_in_detail(void);//������ʾ��Ŀ������������Լ��
 void creat_project_file(void);//
#endif // STUDENT_H_INCLUDED
