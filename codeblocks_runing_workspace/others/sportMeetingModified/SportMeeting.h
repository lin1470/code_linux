#ifndef SPORTMEETING_H_INCLUDED
#define SPORTMEETING_H_INCLUDED
typedef struct
{
	char name[20];
	int code;
	float score;
}project_player;//�˶�Ա�μӵ�����һ���˶��������и����˶������֣��˶����룬�ɼ����������涨��ľ�����˶���Ŀ�����࣬
//����������Ǽ����˶�Ա�ɼ���ʱ����õ��ġ�����

typedef struct
{
	int	 playerCode;
	char playerName[10];
	char  gender[4];
	char  college[20];
	project_player pro[3];
}player;//�����˶�Ա������Ϣ�����������ı��룬�������֣��Ա�ѧԺ���μӵ�������˶���//�˶�Ա�ɼ�¼���ʱ���
//�õ��ġ�����

typedef struct
{
	int code;
	char name[20];
	int placeCode;
	char place[20];
	int numberOfPlayerPerGroup;
	int timeOfGroup;
	char unitOfMeasureMent[4];
}project;//�˶�����Ŀ��������¼���˶���Ŀ��ʱ����õ��ġ����͡�

typedef struct
{
	int		projectCode;
	char		projectName[20];
	int		countOfPlayer;
	int		 estimatedTime;
} time_take;//����ڼ���ʱ������ʱ����Ҫ�õ��ġ�

typedef struct
{
	int  projectCode;
	char projectName[20];
	int  isConflict;
} conflict;//����ʱ���ͻ��ʱ����Ҫ�õ�

typedef struct
{
	int projectCode;
	char projectName[20];
	int timeCode;
} distribution;//ʱ������ʱ����Ҫ�õ���
void bound(char ch, int n);//�����ľ���������һ�������ߵġ�
void main_surface();//�����棻
char* string_link(char *str1, char *str2);//�������������ַ����ģ���ʵ������ӵĿ������Ǹ���ֱ�����ӣ����������
//�Զ����Ĺ���
int printf_pro_data();//��һ����Ŀ��Ŀ¼��������һ���鿴��Щ��Ŀ����󷵻���Ŀ��
int printf_playerList_data(char *fileName);
int did_delete_or_modify();//����ʾ�Ƿ�ɾ�����߸��µġ�
void delete_project();//ɾ��һ����Ŀ�����ڹ���Աɾ����Ŀ��ʱ���õġ�
void add_project();//���ڹ���Ա��������е�һ����Ŀ��
int  count_playerCode();//����һ���˶�Ա
void player_join();//�˶�Ա������ʱ��Ҫ�á�
void modify_project();//�����˶�Ա�޸���Ŀ��
void create_player_of_project();//������Ŀ���˶�Ա��Ŀ¼��
void create_time_of_estimation();//����ÿ����Ŀ��ʱ������
void create_conflict_of_project();//������Ŀ��ͻ��
void create_time_of_distribution();
void query_score();
void enter_result();
void query_dirtribution();
void main_menu();
int check_account();
void main_surface();

#endif // SPORTMEETING_H_INCLUDED
