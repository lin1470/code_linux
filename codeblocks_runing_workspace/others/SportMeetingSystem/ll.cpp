// haha

#define TRUE 1
#define FALSE 0

#define OPENING_TIME_HOUR 9
#define OPENING_TIME_MIN 0
#define ITEM_INTERVAL 15
#define NUM_OF_GROUP 5

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

void menu();

// Publish
void publishMatchItem();

// Register
void registerStudent();

// MatchInfo
void inquireMatchInfo();

// Order
void order();
void inquireOrder();

//
void inquireMatchScore();

// Property
void setSystemProperty();

// Admin
void setNewPassword();
void InputPassword();
void resetPassword();
void ForgotPassword();
void ForgotPassword2();


// Item
void setItem();
void addItem();
void editItem();
void deleteItem();

// Rule
void setMinForItem();
void setScoreRule();
void setSchoolName();

// Unit
void setUnit();
void printAllUnit();
void addUnit();
void deleteUnit();

// MaxItemPerAth
void setMaxItemPerAth();

// Student
void addStudent();
void editStudent();
void deleteStudent();
void lookupStudent();

// Score
void setScore();
void setPersonalScore();
void setItemScore();

void inquireWholeScore();
void inquireIndividualScore();


FILE *fp;
FILE *fp2;

typedef struct Item{
    char name[10];
    int span;  // min
    char time[10];
    char place[10];
    int type; // 0 - ����   1 - ����
}Item;

typedef struct Unit{
    char name[30];
}Unit;

typedef struct Rule{
    char school_name[20];
    int minPeople;
    int score[5];
    int MaxItemPerAth; //ÿ���˶�Ա���μӵ���Ŀ��
}Rule;

typedef struct Student{
    char name[20];
    char number[10];
    int gender; // 0 - ��   1 - Ů
    char unit[30];
    char item[10];
}Student;

typedef struct Player{
    char name[20];
    char number[10];
    int gender; // 0 - ��   1 - Ů
    char school[20];
    char item[10];
    float score;
}Player;

typedef struct Password{
    char pass_word[20];
}Password;


// ----------------------------------------- �˵����� ----------------------------------------

//ѡ�ֱ���
void registerStudent()
{
    int a;
    printf("\n");
    printf("********* ����ѡ�ֱ��� *********\n");
    printf("������������������������������������\n");

    lookupStudent();
    printf("\n");
    printf("1�����ѧ����Ϣ  ");
    printf("2���޸�ѧ����Ϣ  ");
    printf("3��ɾ��ѧ����Ϣ  ");
    printf("4������\n");
    printf("��ѡ����: ");
    scanf("%d", &a);
    printf("������������������������������������\n");

    if (a == 1) {
        addStudent();
    } else if (a == 2) {
        editStudent();
    } else if (a == 3) {
        deleteStudent();
    } else if (a == 4) {
        menu();

    }
}

//������Ŀ����
void publishMatchItem()
{
    Item *item;
    fp = fopen("item.dat","r");
    if (fp == NULL) {
        printf("��ûȷ��������Ŀ!\n");
    } else {

        printf("\n");
        printf("********* ������Ŀ���� *********\n");
        printf("��������������������������������������������������������\n");
        printf("%-25s%-25s%-25s%-25s\n", "����", "����", "�ص�", "ʱ��(����)");

        int tmp = 0;
        item = (Item *)malloc(sizeof(Item));
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp) != 0) {
                char *typeStr;
                if (item->type == 0) {
                    typeStr = "����";
                } else {
                    typeStr = "����";
                }

                //
                if (strcmp(item->place, "") == 0)
                {
                    strcpy(item->place, "E403");
                }

                printf("%-25s%-25s%-25s%-25d\n", item->name, typeStr, item->place, item->span);
                tmp = tmp + 1;
            }

            if (tmp == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp);

    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    menu();
}

void setSystemProperty()
{
    int a;
    printf("\n");
    printf("********* ϵͳ��Ϣ���� *********\n");
    printf("��������������������������������������������������������\n");
    printf("1����Ŀ����\n");
    printf("2����������\n");
    printf("3�������������\n");
    printf("4������ѧУ����\n");
    printf("5��������λ����\n");
    printf("6���ɼ�¼��\n");
    printf("7�����ù���Ա������\n");
//    printf("6��ÿ�����μӵ���Ŀ��\n");
    printf("8������\n");
    printf("��ѡ����: ");
    scanf("%d", &a);
    printf("��������������������������������������������������������\n");

    if (a == 1) {
        // ��Ŀ����
        setItem();
    } else if (a == 2) {
        // ��������
        setScoreRule();
    } else if (a == 3) {
        // �����������
        setMinForItem();
    } else if (a == 4) {
        // ����ѧУ�����֣������ӡ�����˵����϶�
        setSchoolName();
    } else if (a == 5) {
        //���ò�����λ
        setUnit();
    } else if (a == 6) {
        // �ɼ�¼��
        setScore();
    } else if (a == 7) {
        // ����������
        setNewPassword();
    } else if (a == 8) {
        menu();
    }
}

void order()
{
    FILE *fp3;
    int item_num[50] = {0};
    char item_name[50][10] = {""};
    int item_span[50] = {0};
    Item *item = (Item *)malloc(sizeof(Item));
    FILE *fp_item = fopen("item.dat","rb");
    FILE *fp_item_update = fopen("item_tmp.dat", "wb");
    Student *student = (Student *)malloc(sizeof(Student));
    fp2 = fopen("student.dat", "r");
    Player *player = (Player *)malloc(sizeof(Player));
    fp3 = fopen("player.dat", "w+");

    if ((fp_item == NULL) || (fp2 == NULL)) {
        printf("��û��������!\n");
    } else {
        //����item.dat������item�����Ʒŵ��ַ�������item_name��
        int i = 0;
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if ((fread(item, sizeof(Item), 1, fp_item) != 0)) {
                strcpy(item_name[i], item->name);
                item_span[i] = item->span;
                i = i + 1;
            }
        }

        //����student.dat�õ�ÿ����Ŀ������item_num[i]
        while (!feof(fp2)) {
            memset(student, 0, sizeof(Student));
            if ((fread(student, sizeof(Student), 1, fp2) != 0)) {
                for (int j = 0; j < 50; j++) {

                    if (strcmp(student->item, item_name[j]) == 0) {
                        // equal
                        item_num[j]++;
                    }
                }
            }
        }

        //����ÿ����Ŀ������item_num[i]��������Ŀ�������������student���Ƶ�player
        FILE *fp4;
        Rule *rule = (Rule *)malloc(sizeof(Rule));
        fp4 = fopen("rule.dat", "r");
        if (fp4 == NULL) {
            printf("������ÿ����Ŀ����������!\n");
        } else {
            int min = 0;
            rewind(fp4);
            memset(rule, 0, sizeof(Rule));     //�ڴ�ռ��ʼ��
            fread(rule, sizeof(Rule), 1, fp4);
            min = rule->minPeople;
            if (rule != NULL) {
                free(rule);
                rule = NULL;
            }
            fclose(fp4);

            // ����ÿ����Ŀ
            for (int i = 0; i < 50; i++) {
                // �����Ŀ����Ҫ��(��>=min����)
                if (item_num[i] >= min) {
                    // ���player
                    rewind(fp2);
                    while (!feof(fp2)) {
                        memset(student, 0, sizeof(Student));
                        // ����ÿ��ѧ��(�ҵ����и���Ŀ��ѧ��)
                        if ((fread(student, sizeof(Student), 1, fp2) != 0)) {
                            if (strcmp(student->item, item_name[i]) == 0) {
                                // ��Ŀ����
                                strcpy(player->name, student->name);
                                strcpy(player->number, student->number);
                                player->gender = student->gender;
                                strcpy(player->school, student->unit);
                                strcpy(player->item, student->item);
                                fwrite(player, sizeof(Player), 1, fp3);
                            }
                        }
                    }
                }
            }





            // ����ʱ��

            rewind(fp_item);
            rewind(fp_item_update);


            // ������Ŀʱ��

            // ������Ŀ����ʱ��
            rewind(fp_item);
            rewind(fp_item_update);
            int last_time_flag = 0;
            Item *it = (Item *)malloc(sizeof(Item));
            while (!feof(fp_item)) {
                memset(it, 0, sizeof(Item));     //�ڴ�ռ��ʼ��
                if ((fread(it, sizeof(Item), 1, fp_item) != 0)) {
                    // ����ĳһ����Ŀ  Ȼ������Ƿ���Ч������

                    for (int i = 0; i < 50; i++) {

                        if (strcmp(item_name[i], it->name) == 0) {
                            // �ҵ���
                            if (item_num[i] >= min) {
                                // ��Ч

                                int hour = OPENING_TIME_HOUR + last_time_flag / 60;

                                int tMin = OPENING_TIME_MIN + last_time_flag % 60;

                                int min = 0;

                                if (tMin >= 60) {
                                    hour++;
                                    min = tMin % 60;
                                } else {
                                    min = tMin;
                                }

                                sprintf(it->time, "%dʱ%d��", hour, min);
                                fwrite(it, sizeof(Item), 1, fp_item_update);
                                last_time_flag += (item_span[i] + ITEM_INTERVAL);
                                break;
                            } else {
                                // ��Ч
                                sprintf(it->time, "");
                                fwrite(it, sizeof(Item), 1, fp_item_update);
                                break;
                            }
                        }
                    }
                }
            }
        }
        printf("������������!\n");

    }

    // �ͷ�student
    if (student != NULL) {
        free(student);     //free�ͷ���malloc��������ڴ�
        student = NULL;    //��ָ��ָ��NULL
    }

    if (item != NULL) {
        free(item);
        item = NULL;
    }
    if (player != NULL) {
        free(player);
        player = NULL;
    }

    remove("item.dat");
    rename("item_tmp.dat","item.dat");

    fclose(fp_item);
    fclose(fp2);
    fclose(fp3);
    fclose(fp_item_update);

    // test   big bug  -- fixed
//    Item *it = (Item *)malloc(sizeof(Item));
//    FILE *fp6 = fopen("item.dat","r");
//    while (!feof(fp6)) {
//        memset(it, 0, sizeof(Item));     //�ڴ�ռ��ʼ��
//        if ((fread(it, sizeof(Item), 1, fp6) != 0)) {
//            printf("--- --- %s\n", it->time);
//        }
//    }
//    fclose(fp6);
    //


    //*********���ϵó�player.dat

    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    menu();
}

void inquireOrder()
{
    printf("\n");
    printf("********* ����� *********\n");
    printf("������������������������������������\n");

    // �Ȼ�ȡ��Ŀ��Ϣ
    FILE *fp_item = fopen("item.dat", "r");
    int item_span[50] = {0};
    char item_name[50][15] = {""};
    char item_place[50][15] = {""};
    char item_time[50][15] = {""};
    int item_num[50] = {0};  // Ҫ��֪����Щ�������ܾ���

    if (fp_item == NULL) {
        printf("��ûȷ��������Ŀ!\n");
        menu();
        return;
    } else {
        int j = 0;
        rewind(fp_item);
        Item *item = (Item *)malloc(sizeof(Item));
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp_item) != 0) {
                strcpy(item_name[j], item->name);
                strcpy(item_place[j], item->place);
                strcpy(item_time[j], item->time);
                item_span[j] = item->span;
                j++;
            }

            if (j == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");
                menu();
                return;
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp_item);


    Player *player;
    FILE *fp_player = fopen("player.dat","r");

    // ��ȡ������Ŀ
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {
                // item
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->item, item_name[j]) == 0) {
                        item_num[j]++;
                        break;
                    }
                }
                k++;
            }
            if (k == 0) {
                printf("\n");
                printf("��û�в���ѡ����Ϣ!\n");
                menu();
                return;
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }




    // ��ȡ�����Ϣ  �������߼�����
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
        menu();
        return;
    } else {

        // ����������Ϣ
        for (int i = 0; i < 50; i++) {
            if (strcmp("", item_name[i]) == 0) {
                continue;
            }
            if (item_num[i] > 0) {
                // �����ǿձ�����Ϣ ��Ҫ����
                if (strcmp(item_place[i], "") == 0)
                {
                    // item_place[i] = "E403";
                    strcpy(item_place[i], "E403");
                }
                printf("\n��������: %s    ����ʱ��: %s    ʱ��: %d����    �����ص�: %s\n\n", item_name[i], item_time[i], item_span[i], item_place[i]);

                player = (Player *)malloc(sizeof(Player));
                // ����ÿ�����
                int flag = 0; // ��¼�Ѿ����˶��ٸ����
                int round = 1;
                char room[NUM_OF_GROUP][10] = {""};  // ����ÿһ�ֵı�����Ա����ʱ����
                rewind(fp_player);
                while (!feof(fp_player)) {
                    memset(player, 0, sizeof(Player));
                    if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                        // ��ȡ�������Ϣ��
                        if (strcmp(player->item, item_name[i]) == 0) {
                            //                            printf("------------- %s\n", player->name);
                            // �ҵ��μӸ���Ŀ�����
                            for (int j = 0; j < NUM_OF_GROUP; j++) {
                                // ����ҷ������λ��
                                if (strcmp("", room[j]) == 0) {
                                    // �п�λ�Ϳ��Է���
                                    flag++;
                                    strcpy(room[j], player->name);
                                    break;
                                }
                            }
                            // �����һ���Ƿ����
                            if (strcmp(room[NUM_OF_GROUP - 1], "") != 0 || flag >= item_num[i]) {
                                // ������
                                // ��ʾ�������
                                printf("           - �� %d �� -           \n", round);
                                for (int k = 0; k < NUM_OF_GROUP; k++) {
                                    printf("%d��         ", k + 1);
                                }
                                printf("\n");
                                // ��ӡ��������
                                for (int k = 0; k < NUM_OF_GROUP; k++) {
                                    printf("%-15s", room[k]);
                                    strcpy(room[k], "");
                                }
                                printf("\n\n");
                                round++;
                            }
                        }

                    }
                }
                printf("\n");
            }
        }
    }

    fclose(fp_player);

    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    menu();

}

void inquireMatchInfo()
{
    printf("\n");
    printf("********* ����ѡ�ֹ��� *********\n");
    printf("������������������������������������\n");

    printf("%-18s%-18s%-18s%-18s%-18s\n", "ѧ��", "����", "�Ա�", "ѧԺ", "��Ŀ");

    Player *player;
    FILE *fp_player = fopen("player.dat","r");

    FILE *fp_item = fopen("item.dat", "r");

    // item
    int item_num[50] = {0};
    char item_name[50][10] = {""};
    // school
    int school_num[50] = {0};
    char school_name[50][30] = {""};


    if (fp_item == NULL) {
        printf("��ûȷ��������Ŀ!\n");
        menu();
        return;
    } else {
        int j = 0;
        Item *item = (Item *)malloc(sizeof(Item));
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp_item) != 0) {
                strcpy(item_name[j], item->name);
                j++;
            }

            if (j == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");
                menu();
                return;
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    rewind(fp_player);
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
        menu();
        return;
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                // item
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->item, item_name[j]) == 0) {
                        item_num[j]++;
                        break;
                    }
                }

                // school
                // ���Ƿ���ڸ�ѧԺ����������
                bool exist = FALSE;
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->school, school_name[j]) == 0) {
                        // ����
                        school_num[j]++;
                        exist = TRUE;
                        break;
                    }
                }
                // �����ڵĻ�
                if (!exist) {
                    for (int j = 0; j < 50; j++) {
                        // ��ѧԺ��ӵ���������
                        if (strcmp("", school_name[j]) == 0) {
                            strcpy(school_name[j], player->school);
                            school_num[j]++;
                            break;
                        }
                    }
                }

                // player
                char *genderStr;
                if (player->gender == 0) {
                    genderStr = "��";
                } else {
                    genderStr = "Ů";
                }

                printf("%-20s%-20s%-20s%-20s%-20s\n", player->number, player->name, genderStr, player->school, player->item);

                // ���Բ鿴�ɼ���
                //                printf("%-20s%-20s%-20s%-20s%-20s%1.2f\n", player->number, player->name, genderStr, player->school, player->item, player->score);

                k++;
            }

            if (k == 0) {
                printf("\n");
                printf("��û�в���ѡ����Ϣ!\n");
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }

    printf("�����ǲμӸ���������Ŀ������:\n");
    printf("������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        if (item_num[i] > 0) {
            printf("%-15s%d��\n", item_name[i], item_num[i]);
        }
    }

    printf("�����Ǹ���ѧԺ�μӱ�����Ŀ������:\n");
    printf("������������������������������������\n");
    for (int i = 0; i < 50; i++) {
        if (school_num[i] > 0) {
            printf("%-15s%d��\n", school_name[i], school_num[i]);
        }
    }

    fclose(fp_player);
    fclose(fp_item);

    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    menu();
}

void inquireWholeScore()
{
    printf("\n");
    printf("********* ����ɼ����� *********\n");
    printf("������������������������������������\n");

    // �Ȼ�ȡ��Ŀ��Ϣ
    FILE *fp_item = fopen("item.dat", "r");

    char item_name[50][10] = {""};
    char item_place[50][10] = {""};
    int item_type[50] = {0};
    char item_time[50][10]= {""};
    int item_num[50] = {0};  // Ҫ��֪����Щ�������ܾ���

    if (fp_item == NULL) {
        printf("��ûȷ��������Ŀ!\n");
        inquireMatchScore();
        return;
    } else {
        int j = 0;
        Item *item = (Item *)malloc(sizeof(Item));
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp_item) != 0) {
                strcpy(item_name[j], item->name);
                strcpy(item_place[j], item->place);
                strcpy(item_time[j], item->time);
//                item_time[j] = item->time;
                item_type[j] = item->type;
                j++;
            }

            if (j == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");
                inquireMatchScore();
                return;
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp_item);


    Player *player;
    FILE *fp_player = fopen("player.dat","r");

    // ��ȡ������Ŀ
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {
                // item
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->item, item_name[j]) == 0) {
                        item_num[j]++;
                        break;
                    }
                }
                k++;
            }
            if (k == 0) {
                printf("\n");
                printf("��û�в���ѡ����Ϣ!\n");
                inquireMatchScore();
                return;
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }


    Player *rankList[50][50] = {NULL};   // fucking important

    // ��ȡ�����Ϣ  �������߼�����
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
        inquireMatchScore();
        return;
    } else {

        // ����������Ϣ
        int currentItem = 0;
        for (int i = 0; i < 50; i++) {
            if (strcmp("", item_name[i]) == 0) {
                continue;
            }
            if (item_num[i] > 0) {
                // �����ǿձ�����Ϣ ��Ҫ����
                printf("\n��������: %s    ����ʱ��: %s    �����ص�: %s\n\n", item_name[i], item_time[i], item_place[i]);

                player = (Player *)malloc(sizeof(Player));
                // ����ÿ�����
                rewind(fp_player);
                while (!feof(fp_player)) {
                    memset(player, 0, sizeof(Player));
                    if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                        // ��ȡ�������Ϣ��
                        if (strcmp(player->item, item_name[i]) == 0) {
                            //                            printf("------------- %s\n", player->name);
                            // �ҵ��μӸ���Ŀ�����
                            for (int m = 0; m < 50; m++) {
                                if (rankList[currentItem][m] == NULL) {
                                    rankList[currentItem][m] = (Player *)malloc(sizeof(Player));
                                    strcpy(rankList[currentItem][m]->name, player->name);
                                    strcpy(rankList[currentItem][m]->number, player->number);
                                    strcpy(rankList[currentItem][m]->item, player->item);
                                    rankList[currentItem][m]->gender = player->gender;
                                    strcpy(rankList[currentItem][m]->school, player->school);
                                    rankList[currentItem][m]->score = player->score;
                                    break;
                                }
                            }
                        }

                    }
                }

                // ���ǿ�Ԫ�ص�ð������
                for (int n = 0; n < 50 - 1; n++) {
                    if (rankList[currentItem][n] == NULL) {
                        //                        printf("%-13s", rankList[currentItem][n]->name);
                        continue;
                    }
                    for (int k = 0; k < 50 - 1 - n; k++) {
                        if (rankList[currentItem][n] == NULL) {
                            continue;
                        }
                        int flag = 0;
                        for (int f = 1; f < 50 - 1 - n - k; f++) {
                            if (rankList[currentItem][k + f] == NULL) {
                                continue;
                            }
                            flag = f;
                            break;
                        }
                        if (flag == 0) {
                            continue;
                        }
                        // ����type
                        if (item_type[i] == 0) {
                            // ����
                            if(rankList[currentItem][k]->score > rankList[currentItem][k + flag]->score) {
                                Player *temp_player = (Player *)malloc(sizeof(Player));

                                // 1
                                strcpy(temp_player->name, rankList[currentItem][k]->name);
                                strcpy(temp_player->number, rankList[currentItem][k]->number);
                                strcpy(temp_player->item, rankList[currentItem][k]->item);
                                strcpy(temp_player->school, rankList[currentItem][k]->school);
                                temp_player->gender = rankList[currentItem][k]->gender;
                                temp_player->score = rankList[currentItem][k]->score;

                                // 2
                                strcpy(rankList[currentItem][k]->name, rankList[currentItem][k + flag]->name);
                                strcpy(rankList[currentItem][k]->number, rankList[currentItem][k + flag]->number);
                                strcpy(rankList[currentItem][k]->item, rankList[currentItem][k + flag]->item);
                                strcpy(rankList[currentItem][k]->school, rankList[currentItem][k + flag]->school);
                                rankList[currentItem][k]->gender = rankList[currentItem][k + flag]->gender;
                                rankList[currentItem][k]->score = rankList[currentItem][k + flag]->score;

                                // 3
                                strcpy(rankList[currentItem][k + flag]->name, temp_player->name);
                                strcpy(rankList[currentItem][k + flag]->number, temp_player->number);
                                strcpy(rankList[currentItem][k + flag]->item, temp_player->item);
                                strcpy(rankList[currentItem][k + flag]->school, temp_player->school);
                                rankList[currentItem][k + flag]->gender = temp_player->gender;
                                rankList[currentItem][k + flag]->score = temp_player->score;

                                memset(temp_player, 0, sizeof(Player));
                            }
                        } else {
                            // ����
                            if(rankList[currentItem][k]->score < rankList[currentItem][k + flag]->score) {
                                Player *temp_player = (Player *)malloc(sizeof(Player));

                                // 1
                                strcpy(temp_player->name, rankList[currentItem][k]->name);
                                strcpy(temp_player->number, rankList[currentItem][k]->number);
                                strcpy(temp_player->item, rankList[currentItem][k]->item);
                                strcpy(temp_player->school, rankList[currentItem][k]->school);
                                temp_player->gender = rankList[currentItem][k]->gender;
                                temp_player->score = rankList[currentItem][k]->score;

                                // 2
                                strcpy(rankList[currentItem][k]->name, rankList[currentItem][k + flag]->name);
                                strcpy(rankList[currentItem][k]->number, rankList[currentItem][k + flag]->number);
                                strcpy(rankList[currentItem][k]->item, rankList[currentItem][k + flag]->item);
                                strcpy(rankList[currentItem][k]->school, rankList[currentItem][k + flag]->school);
                                rankList[currentItem][k]->gender = rankList[currentItem][k + flag]->gender;
                                rankList[currentItem][k]->score = rankList[currentItem][k + flag]->score;

                                // 3
                                strcpy(rankList[currentItem][k + flag]->name, temp_player->name);
                                strcpy(rankList[currentItem][k + flag]->number, temp_player->number);
                                strcpy(rankList[currentItem][k + flag]->item, temp_player->item);
                                strcpy(rankList[currentItem][k + flag]->school, temp_player->school);
                                rankList[currentItem][k + flag]->gender = temp_player->gender;
                                rankList[currentItem][k + flag]->score = temp_player->score;

                                memset(temp_player, 0, sizeof(Player));
                            }
                        }
                    }
                }

                // display
                printf("%-16s%-16s%-16s%-16s%-16s\n", "��һ��", "�ڶ���", "������", "������", "������");
                for (int n = 0; n < 5; n++) {
                    if (rankList[currentItem][n] != NULL) {
                        printf("%-16s", rankList[currentItem][n]->name);
                    }
                }
                printf("\n");
                for (int n = 0; n < 5; n++) {
                    if (rankList[currentItem][n] != NULL) {
                        char *typeStr = "";
                        if (item_type[i] == 0) {
                            typeStr = "��";
                        } else {
                            typeStr = "��";
                        }
                        printf("%1.2f%s       ", rankList[currentItem][n]->score, typeStr);
                    }
                }

                printf("\n\n����������Ա����: \n");
                for (int n = 5; n < 50; n++) {
                    if (rankList[currentItem][n] != NULL) {
                        char *typeStr = "";
                        if (item_type[i] == 0) {
                            typeStr = "��";
                        } else {
                            typeStr = "��";
                        }
                        printf("%s / %1.2f%s    ", rankList[currentItem][n]->name, rankList[currentItem][n]->score, typeStr);

                        if ((n - 4) % 5 == 0) {
                            printf("\n");
                        }
                    }
                }

                printf("\n");
                currentItem++;
            }
        }
    }

    // �õ�ѧԺ�ܷ�

    // �Ȼ�ȡ��������
    FILE *fp_rule = fopen("rule.dat", "r");

    int score_rule[5] = {0};

    rewind(fp_rule);
    if (fp_rule == NULL) {
        printf("��û�з���������Ϣ!\n");
    } else {
        int k = 0;
        Rule *rule = (Rule *)malloc(sizeof(Rule));
        while (!feof(fp_rule)) {
            memset(rule, 0, sizeof(Rule));
            if (fread(rule, sizeof(Rule), 1, fp_rule) != 0) {
                for (int i = 0 ; i < 5; i++) {
                    score_rule[i] = rule->score[i];
                }
                break;
            }
            if (k == 0) {
                printf("\n");
                printf("��û�з���������Ϣ!\n");
                inquireMatchScore();
                return;
            }
        }
        if (rule != NULL) {
            free(rule);
            rule = NULL;
        }
    }
    fclose(fp_rule);

    // ��ȡѧԺ��Ϣ
    int school_score[50] = {0};
    char school_name[50][20] = {""};

    rewind(fp_player);
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                // school
                // ���Ƿ���ڸ�ѧԺ����������
                bool exist = FALSE;
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->school, school_name[j]) == 0) {
                        // ����
                        exist = TRUE;
                        break;
                    }
                }
                // �����ڵĻ�
                if (!exist) {
                    for (int j = 0; j < 50; j++) {
                        // ��ѧԺ��ӵ���������
                        if (strcmp("", school_name[j]) == 0) {
                            strcpy(school_name[j], player->school);
                            break;
                        }
                    }
                }
                k++;
            }

            if (k == 0) {
                printf("\n");
                printf("��û�в���ѡ����Ϣ!\n");
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }

    fclose(fp_player);

    printf("\n�����Ǹ���ѧԺ�ĵ÷�����: \n");

    for (int i = 0; i < 50; i++) {
        // ����ĳһ�����
        //        printf("----- %d\n", i);
        int rank = 0;
        for (int j = 0; j < 50; j++) {
            // ��ȡ��ѧ����ѧԺ
            //            printf("-- %d %s\n", j, rankList[i][j]->name);
            if (rankList[i][j] != NULL) {
                rank = 0;
                for (int m = 0; m < 50; m++) {
                    if (strcmp(school_name[m], rankList[i][j]->school) == 0) {
                        school_score[m] += score_rule[rank];
                        rank++;
                        break;
                    }
                }
            }
        }
    }

    // ��ʾ
    printf("ѧԺ       �÷�\n");
    for (int i = 0; i < 50; i++) {
        if (strcmp("", school_name[i]) == 0) {
            continue;
        }
        printf("%s      %d��\n", school_name[i], school_score[i]);
    }


    printf("\n������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    inquireMatchScore();
}

void inquireIndividualScore()
{
    printf("\n");
    printf("********* ���˳ɼ���ѯ *********\n");
    printf("������������������������������������\n");

    // �Ȼ�ȡ��Ŀ��Ϣ
    FILE *fp_item = fopen("item.dat", "r");

    char item_name[50][10] = {""};
    int item_type[50] = {0};

    if (fp_item == NULL) {
        printf("��ûȷ��������Ŀ!\n");
        inquireMatchScore();
        return;
    } else {
        int j = 0;
        Item *item = (Item *)malloc(sizeof(Item));
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp_item) != 0) {
                strcpy(item_name[j], item->name);
                item_type[j] = item->type;
                j++;
            }

            if (j == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");
                inquireMatchScore();
                return;
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp_item);

    char number[10] = "";
    printf("����������ߵ�ѧ��: ");
    scanf("%s", number);

    Player *player;
    FILE *fp_player = fopen("player.dat","r");

    // ��ȡ������Ŀ
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("��û�в���ѡ����Ϣ!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {
                if (strcmp(player->number, number) == 0) {
                    // �ҵ����������

                    // ȷ������
                    char *typeStr = "";

                    for (int i = 0; i < 50; i++) {
                        if (strcmp(item_name[i], player->item) == 0) {
                            if (item_type[i] == 0) {
                                typeStr = "��";
                            } else {
                                typeStr = "��";
                            }
                        }
                    }

                    // ��ʾ
                    printf("ѧ��: %s   ����: %s   ����: %s   �ɼ�: %1.2f%s", player->number, player->name, player->item, player->score, typeStr);
                }
                k++;
            }
            if (k == 0) {
                printf("\n");
                printf("��û�в���ѡ����Ϣ!\n");
                inquireMatchScore();
                return;
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }

    fclose(fp_player);

    printf("\n������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    inquireMatchScore();
}




void inquireMatchScore()
{
    int a;
    printf("\n");
    printf("********* �����ɼ���ѯ *********\n");
    printf("������������������������������������\n");
    printf("1�������ѯ\n");
    printf("2�����˲�ѯ\n");
    printf("3������\n");
    printf("��ѡ����: ");
    scanf("%d", &a);
    printf("������������������������������������\n");

    if (a == 1) {
        inquireWholeScore();
    } else if (a == 2) {
        inquireIndividualScore();
    } else if (a == 3) {
        menu();
    }
}

void menu()
{

    struct tm *ptr;
    time_t it;
    it=time(NULL);
    ptr=localtime(&it);
    printf("\n          ��ǰʱ��: %4d��%02d��%02d�� %d:%d",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min);
    char school_name[20];
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if ((fp = fopen("rule.dat", "rb")) == NULL) {
        strcpy(school_name,"");
    } else {
        rewind(fp); //����
        memset(rule, 0, sizeof(Rule));
        fread(rule, sizeof(Rule), 1, fp);
        strcpy(school_name, rule->school_name);
    }

    fclose(fp);

    printf("\n");
    printf("��������������������������������������������������������������������������������������������������\n");
    printf("         ****** %s�˶������ϵͳ ******          \n", school_name);
    printf("��������������������������������������������������������������������������������������������������\n");

    for (int i = 0; i < 8; ++i) {
        char *title;
        switch (i) {
            case 0:
                title = "������Ŀ����";
                break;
            case 1:
                title = "����ѡ�ֱ���";
                break;
            case 2:
                title = "���������";
                break;
            case 3:
                title = "�鿴�����";
                break;
            case 4:
                title = "������Ϣ��ѯ";
                break;
            case 5:
                title = "�����ɼ���ѯ";
                break;
            case 6:
                title = "ϵͳ��Ϣ����";
                break;
            case 7:
                title = "�˳�����ϵͳ";
                break;
            default:
                break;
        }

        printf("%18.d��%s\n", i + 1, title);
    }

    printf("��������������������������������������������������������������������������������������������������\n");

    printf("��ѡ����: ");
    int c;
    scanf("%d", &c);

    switch (c) {
        case 1:
            publishMatchItem();
            break;
        case 2:
            registerStudent();
            break;
        case 3:
            order();
            break;
        case 4:
            inquireOrder();
            break;
        case 5:
            inquireMatchInfo();
            break;
        case 6:
            inquireMatchScore();
            break;
        case 7:
            // setSystemProperty();
            InputPassword();
            break;
        case 8:
            exit(0);
            break;
        default:
            break;
    }
}

// ----------------------------------------- Main ----------------------------------------

int main(int argc, const char * argv[])
{
    menu();
    return 0;
}


// ----------------------------------------- ��Ŀ���� ----------------------------------------
//�鿴������Ŀ
void setItem()
{
    Item *item;
    int tmp = 0;
    fp = fopen("item.dat","r");
    if (fp == NULL) {
        printf("��ûȷ��������Ŀ!\n");
        fp = fopen("item.dat","wb+");
    } else {
        printf("\n");
        printf("������Ŀ\n");
        printf("��������������������������������\n");
        printf("%-25s%-25s%-25s%-25s\n", "����", "����", "ʱ��(����)", "�ص�");

        item = (Item *)malloc(sizeof(Item));
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp) != 0) {
                char *typeStr;
                if (item->type == 0) {
                    typeStr = "����";
                } else {
                    typeStr = "����";
                }

                if (strcmp("", item->place) == 0) {
                    strcpy(item->place, "E403");
                }

                printf("%-25s%-25s%-25d%-25s\n", item->name, typeStr, item->span, item->place);
                tmp = tmp + 1;
            }

            if (tmp == 0) {
                printf("\n");
                printf("��ûȷ��������Ŀ!\n");


            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp);


    int b;
    printf("\n");
    printf("1�������Ŀ  ");
    printf("2���޸���Ŀ  ");
    printf("3��ɾ����Ŀ  ");
    printf("4������\n");
    printf("��ѡ���� :");
    scanf("%d", &b);
    if (b == 1) {
        addItem();
    } else if (b == 2) {
        editItem();
    } else if (b == 3) {
        deleteItem();
    } else if (b == 4) {
        setSystemProperty();
    }



}
// �����Ŀ
void addItem()
{
    bool same = false;
    Item *item = (Item *)malloc(sizeof(Item));
    if((fp = fopen("item.dat","rb+")) == NULL) {     //�Զ�/д��ʽ��һ���������ļ�����׷��
        fp = fopen("item.dat", "wb+");   //�����ھʹ���
    }

    printf("��������Ŀ����: ");
    scanf("%s", item->name);
    printf("��������Ŀ����(0 - ����  1 - ����): ");
    scanf("%d", &item->type);
    printf("��������Ŀ����ʱ��(����): ");
    scanf("%d", &item->span);
    printf("��������Ŀ�ص�: ");
    scanf("%s", item->place);

    // ����Ƿ����
    rewind(fp); // <!-�ǳ��ؼ�-!> ���÷����ļ���ָ��
    Item *local_item = (Item *)malloc(sizeof(Item));
    while (!feof(fp)) {
        memset(local_item, 0, sizeof(Item));     //�ڴ�ռ��ʼ��
        // ����һ�鿴��û���Ѿ����ڵ���ͬ����Ŀ����
        if (fread(local_item, sizeof(Item), 1, fp) != 0) {

            if (strcmp(local_item->name, item->name) == 0) {
                // ������ͬ Ҫ���ٴ�����
                same = TRUE;
                printf("����Ŀ�Ѵ��ڣ����������룡\n");
            }
        }
    }


    // д��
    fwrite(item, sizeof(Item), 1, fp);
    memset(item, 0, sizeof(Item));     //�ڴ�ռ��ʼ��

    if (item != NULL) {
        free(item);     //free�ͷ���malloc��������ڴ�
        item = NULL;    //��ָ��ָ��NULL
    }

    fclose(fp);
    printf("\n");
    printf("��ӳɹ�!\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setItem();
}

// �޸���Ŀ
void editItem()
{

    Item *item = (Item *)malloc(sizeof(Item));
    Item update_item;

    fp = fopen("item.dat", "r");
    fp2 = fopen("item_tmp.dat", "w");
    if (fp == NULL) {
        printf("û���κ���Ŀ!");
    } else {
        char update_item_name[10];
        printf("������Ҫ�޸ĵ���Ŀ������: ");
        scanf("%s", update_item_name);
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));     //�ڴ�ռ��ʼ��
            if ((fread(item, sizeof(Item), 1, fp) != 0)) {
                if (strcmp(item->name, update_item_name) != 0)
                    fwrite(item, sizeof(Item), 1, fp2);     //ֻҪ����Ҫ�޸ĵ��Ǹ���Ŀ����д��fp2��
                else if (strcmp(item->name, update_item_name) == 0) {
                    //�ҵ������ͬ��
                    printf("������Ҫ�޸ĵ���Ŀ������: (0 - ����  1 - ����)");
                    scanf("%d", &update_item.type);
                    printf("������Ҫ�޸ĵ���Ŀ��ʱ��(����): ");
                    scanf("%d", &update_item.span);
                    printf("������Ҫ�޸ĵ���Ŀ�ĵص�: ");
                    scanf("%s", update_item.place);
                    strcpy(item->name, update_item_name);    //����
//                    item->time = update_item.time;
                    strcpy(item->time, update_item.time);
                    strcpy(item->place, update_item.place);
                    item->type = update_item.type;
                    fwrite(item, sizeof(Item), 1, fp2);
                }

            }
        }
        if(item!=NULL) {
            free(item);
            item=NULL;
        }
        fclose(fp);
        fclose(fp2);
    }

    remove("item.dat");
    rename("item_tmp.dat","item.dat");
    printf("\n");
    printf("�޸ĳɹ�!\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setItem();
}

// ɾ����Ŀ
void deleteItem()
{
    bool same = 0;
    Item *item = (Item *)malloc(sizeof(Item));
    fp = fopen("item.dat", "r");
    fp2 = fopen("item_tmp.dat", "w");

    char delete_item_name[10];
    printf("������Ҫɾ������Ŀ������: ");
    scanf("%s", delete_item_name);

    while (!feof(fp)) {
        memset(item, 0, sizeof(Item));     //�ڴ�ռ��ʼ��
        if ((fread(item, sizeof(Item), 1, fp) != 0) && (strcmp(item->name, delete_item_name) != 0)) {
            fwrite(item, sizeof(Item), 1, fp2);     //ֻҪ����Ҫɾ�����Ǹ���Ŀ����д��fp2��
        } else if (strcmp(item->name, delete_item_name) == 0) {
            same = 1;
        }
    }

    if (item != NULL) {
        free(item);
        item = NULL;
    }

    fclose(fp2);
    fclose(fp);
    remove("item.dat");
    rename("item_tmp.dat", "item.dat");    //��fp2�ĳ�fp

    if (same == 0) {
        printf("û�������Ŀ��\n");
    } else {
        printf("ɾ���ɹ�!\n");
    }

    printf("\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setItem();
}


// ��������
void setMinForItem()
{
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if((fp = fopen("rule.dat","rb+")) == NULL) {     //�Զ�/д��ʽ��һ���������ļ�
        fp = fopen("rule.dat", "wb+");   //�����ھʹ���
    }

    // ����
    rewind(fp);
    // ��ȡ
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //����
    int minNum = 0;
    printf("������ÿ����Ŀ����������: ");
    scanf("%d", &minNum);

    rule->minPeople = minNum;

    // д��
    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));     //�ڴ�ռ��ʼ��

    if (rule != NULL) {
        free(rule);     //free�ͷ���malloc��������ڴ�
        rule = NULL;    //��ָ��ָ��NULL
    }

    fclose(fp);
    printf("\n");
    printf("���óɹ�!  <��ǰ��������Ϊ%d��>\n", minNum);
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setSystemProperty();
}


// ���÷���
void setScoreRule()
{
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if((fp = fopen("rule.dat","rb+")) == NULL) {     //�Զ�/д��ʽ��һ���������ļ�
        fp = fopen("rule.dat", "wb+");   //�����ھʹ���
    }

    // ��ʱ
    int temp[5] = {0};

    // ����
    rewind(fp);

    // ��ȡ
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //����


    for (int i = 0; i < 5; i++) {

        char *str;
        switch (i) {
            case 0:
                str = "һ";
                break;
            case 1:
                str = "��";
                break;
            case 2:
                str = "��";
                break;
            case 3:
                str = "��";
                break;
            case 4:
                str = "��";
                break;
            default:
                break;
        }
        printf("�������%s���ɻ�õķ���: ", str);
        int score = 0;
        scanf("%d", &score);
        rule->score[i] = score;
        temp[i] = score;
    }

    // д��
    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));     //�ڴ�ռ��ʼ��


    if (rule != NULL) {
        free(rule);     //free�ͷ���malloc��������ڴ�
        rule = NULL;    //��ָ��ָ��NULL
    }

    fclose(fp);

    printf("\n");
    printf("���óɹ�!   <");
    for (int i = 0; i < 5; i++) {
        char *str;
        switch (i) {
            case 0:
                str = "һ";
                break;
            case 1:
                str = "��";
                break;
            case 2:
                str = "��";
                break;
            case 3:
                str = "��";
                break;
            case 4:
                str = "��";
                break;

            default:
                break;
        }
        printf("��%s�� %d��", str, temp[i]);
        if (i < 4) {
            printf("   ");
        }
    }
    printf(">\n");
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setSystemProperty();
}

void setSchoolName()
{
    Rule *rule = (Rule*)malloc(sizeof(Rule));
    if ((fp = fopen("rule.dat", "rb+")) == NULL) { //�Զ�/д��ʽ��һ���������ļ�
        fp = fopen("rule.dat", "wb+");      //�����ھʹ���
    }

    rewind(fp);  //����
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //����
    char school_name[20];
    printf("������ѧУ(������λ)������: ");
    scanf("%s", school_name);

    strcpy(rule->school_name, school_name);

    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));  //�ڴ�ռ��ʼ��

    if (rule != NULL) {
        free(rule);   //free�ͷ���malloc��������ڴ�
        rule = NULL;    //��ָ��ָֻ��NULL
    }

    fclose(fp);
    printf("\n");
    printf("���óɹ�!\n");
    printf("��������������������������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setSystemProperty();
}

void printAllUnit()
{
    Unit *unit;
    int tmp = 0;
    if ((fp = fopen("unit.dat", "rb+")) == NULL) {
        fp = fopen("unit.dat", "wb+");
        printf("��û���κβ�����λ!\n");
    } else {
        printf("\n");
        printf("������λ\n");
        printf("��������������������������������\n");

        unit = (Unit*)malloc(sizeof(Unit));
        while (!feof(fp)) {
            memset(unit, 0, sizeof(Unit));
            if ((fread(unit, sizeof(Unit), 1, fp) != 0)) {
                printf("%s\n", unit->name);
                tmp = tmp + 1;
            }

            if (tmp == 0) {
                printf("��û�κβ�����λ!\n");

            }
        }

        if (unit != NULL) {
            free(unit);
            unit = NULL;
        }
    }

    fclose(fp);
};

void setUnit()
{
    printAllUnit();
    int b;
    printf("\n");
    printf("1����Ӳ�����λ   ");
    printf("2��ɾ��������λ   ");
    printf("3������\n");
    printf("��ѡ���� :");
    scanf("%d", &b);
    if (b == 1) {
        addUnit();
    } else if (b == 2) {
        deleteUnit();
    } else if (b == 3) {
        setSystemProperty();
    }


}

void addUnit()
{
    Unit *unit = (Unit*)malloc(sizeof(Unit));
    if((fp = fopen("unit.dat","rb+")) == NULL) {     //�Զ�/д��ʽ��һ���������ļ�����׷��
        fp = fopen("unit.dat", "wb+");   //�����ھʹ���
    }

    char temp_name[30];
    printf("�����������λ����: ");
    scanf("%s", temp_name);

    bool same = false;
    rewind(fp);
    while (!feof(fp)) {
        memset(unit, 0, sizeof(Unit));
        if ((fread(unit, sizeof(Unit), 1, fp) != 0)) {
            if ((strcmp(unit->name, temp_name)) == 0) {
                same = true;
            }
        }

    }

    if (same == true) {
        printf("\n");
        printf("�Ѵ��ڴ˲�����λ!\n");

    } else if (same == false) {
        strcpy(unit->name, temp_name);
        fwrite(unit, sizeof(Unit), 1, fp);
        memset(unit, 0, sizeof(Unit));
        printf("��ӳɹ�!\n");
    }

    if (unit != NULL) {
        free(unit);
        unit = NULL;
    }

    fclose(fp);
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setUnit();

};

void deleteUnit()
{
    bool same = false;
    Unit *unit = (Unit *)malloc(sizeof(Unit));
    fp = fopen("unit.dat", "r");
    fp2 = fopen("unit_tmp.dat", "w");

    char delete_unit_name[30];
    printf("������Ҫɾ���Ĳ�����λ������: ");
    scanf("%s", delete_unit_name);

    while (!feof(fp)) {
        memset(unit, 0, sizeof(Unit));
        if ((fread(unit, sizeof(Unit), 1, fp) != 0) && (strcmp(unit->name, delete_unit_name) != 0)) {
            fwrite(unit, sizeof(Unit), 1, fp2);
        } else if (strcmp(unit->name, delete_unit_name) == 0) {
            same = true;
        }
    }

    if (unit != NULL) {
        free(unit);
        unit = NULL;
    }

    fclose(fp2);
    fclose(fp);
    remove("unit.dat");
    rename("unit_tmp.dat", "unit.dat");

    if (same == false) {
        printf("û�������Ŀ! \n");
    } else {
        printf("ɾ���ɹ�!\n");
    }

    printf("\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setUnit();

};

void setMaxItemPerAth()
{
    Rule *rule = (Rule*)malloc(sizeof(Rule));
    if ((fp = fopen("rule.dat", "rb+")) == NULL) {
        fp = fopen("rule.dat", "wb+");
    }
    rewind(fp);
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);
    int maxItemPerAth;
    printf("������ÿλ�˶�Ա���μӵ���Ŀ��: ");
    scanf("%d", &maxItemPerAth);
    rule->MaxItemPerAth = maxItemPerAth;
    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));

    if (rule != NULL) {
        free(rule);
        rule = NULL;
    }

    fclose(fp);
    printf("\n");
    printf("���óɹ�!\n");
    printf("������������������������������������\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setSystemProperty();

}

// ----------------------------------------- �������� ----------------------------------------




void addStudent()
{
    //��������λ����������
    char unit_tmp[20][30];
    int num_unit = 0;
    {
        Unit *unit;
        if ((fp = fopen("unit.dat", "rb+")) == NULL) {
            fp = fopen("unit.dat", "wb+");
            printf("��û���κβ�����λ!\n");
            printf("�����ò�����λ�������ѧ��!\n");
            printf("����������ز˵�..\n");

            system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
            menu();
        } else {
            unit = (Unit *)malloc(sizeof(Unit));
            while (!feof(fp)) {
                memset(unit, 0, sizeof(Unit));
                if ((fread(unit, sizeof(Unit), 1, fp) != 0)) {
                    strcpy(unit_tmp[num_unit], unit->name);
                    num_unit = num_unit + 1;
                }
            }
        }

        if (unit != NULL) {
            free(unit);
            unit = NULL;
        }

        fclose(fp);
    }

    //����Ŀ�Ž�������
    char item_tmp[20][20];
    int num_item = 0;
    {
        Item *item;
        if ((fp = fopen("item.dat", "rb+")) == NULL) {
            fp = fopen("item.dat", "wb+");
            printf("��û���κα�����Ŀ!\n");
            printf("�����ñ�����Ŀ�������ѧ��!\n");
            printf("����������ز˵�..\n");
            system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
            menu();
        } else {
            item = (Item *)malloc(sizeof(Item));
            while (!feof(fp)) {
                memset(item, 0, sizeof(Item));
                if ((fread(item, sizeof(Item), 1, fp) != 0)) {
                    strcpy(item_tmp[num_item], item->name);
                    num_item = num_item + 1;
                }
            }
        }

        if (item != NULL) {
            free(item);
            item = NULL;
        }
        fclose(fp);
    }


    bool same = FALSE;
    Student *student = (Student *)malloc(sizeof(Student));

    if((fp = fopen("student.dat","rb+")) == NULL) {     //�Զ�/д��ʽ��һ���������ļ�����׷��
        fp = fopen("student.dat", "wb+");   //�����ھʹ���
    }

    //����rule->maxItemPerAth
    int max = 0;
    Rule *rule = (Rule*)malloc(sizeof(Rule));
    fp2 = fopen("rule.dat", "r");
    if (fp2 == NULL) {
        printf("Ĭ��ÿ���˶�Ա����ܲμ�3�����\n");
        max = 3;
    } else {
        rewind(fp2);
        memset(rule, 0, sizeof(Rule));
        fread(rule, sizeof(Rule), 1, fp2);
        max = rule->MaxItemPerAth;
        if (rule != NULL) {
            free(rule);
            rule = NULL;
        }
        fclose(fp2);
    }


    printf("������ѧ��: ");
    scanf("%s", student->number);
    printf("����������: ");
    scanf("%s", student->name);
    printf("(0 - ��   1 - Ů)�������Ա�: ");
    scanf("%d", &student->gender);

    { //�г�������λ������
        printf("(");
        for (int j = 0; j < num_unit; j++) {
            printf("%s ", unit_tmp[j]);
        }
        printf(")");
        printf(" �����������λ: ");
        scanf("%s", student->unit);
    }

    { //�г�������Ŀ��������
        printf("(");
        for (int j = 0; j < num_item; j++) {
            printf("%s ", item_tmp[j]);
        }
        printf(")");
        printf("��������Ŀ����: ");
        scanf("%s", student->item);
    }




    int tmp = 0;
    // ����Ƿ����
    rewind(fp); // <!-�ǳ��ؼ�-!> ���÷����ļ���ָ��
    Student *local_student = (Student *)malloc(sizeof(Student));
    while (!feof(fp)) {
        memset(local_student, 0, sizeof(Student));     //�ڴ�ռ��ʼ��
        // ����һ�鿴��û���Ѿ����ڵ���ͬ����Ŀ����
        if (fread(local_student, sizeof(Student), 1, fp) != 0) {

            if (strcmp(local_student->number, student->number) == 0) {
                // ѧ����ͬ
                tmp = tmp + 1;
                //ѧ�ź���Ŀ����ͬ
                if (strcmp(local_student->item, student->item) == 0) {
                    same = true;
                }
            }
        }
    }

    if (same == true) {
        // ���ܱ���
        printf("���ʧ��!���ѱ�������Ŀ!");
    } else if (tmp >= max) {
        printf("���ʧ��!ÿ�������ֻ�ܱ�%d��!\n", max);
    } else if ((same == false) && (tmp < max)) {
        // ����
        fwrite(student, sizeof(Student), 1, fp);
        memset(student, 0, sizeof(Student));     //�ڴ�ռ��ʼ��
        printf("��ӳɹ�!\n");
    }

    if (student != NULL) {
        free(student);     //free�ͷ���malloc��������ڴ�
        student = NULL;    //��ָ��ָ��NULL
    }

    fclose(fp);
    printf("\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    registerStudent();
}

void editStudent()
{
    Student *student;
    Student update_student;
    student = (Student *)malloc(sizeof(Student));

    fp = fopen("student.dat", "r");
    fp2 = fopen("student_tmp.dat", "w");
    if (fp == NULL) {
        printf("û���κα�������Ϣ!\n");
    } else {
        char update_student_number[10];
        printf("������Ҫ�޸ĵ�ѧ����ѧ��: \n");
        scanf("%s", update_student_number);
        while (!feof(fp)) {
            memset(student, 0, sizeof(Student));     //�ڴ�ռ��ʼ��
            if ((fread(student, sizeof(Student), 1, fp) != 0)) {
                if (strcmp(student->number, update_student_number) != 0)
                    fwrite(student, sizeof(Student), 1, fp2);     //ֻҪ����Ҫ�޸ĵ��Ǹ�ѧ������д��fp2��
                else if (strcmp(student->number, update_student_number) == 0) {
                    //�ҵ������ͬ��
                    printf("������Ҫ�޸ĵ�����: ");
                    scanf("%s", update_student.name);
                    printf("������Ҫ�޸ĵ��Ա�(0 - ��  1 - Ů): ");
                    scanf("%d", &update_student.gender);
                    printf("������Ҫ�޸ĵ�ѧԺ: ");
                    scanf("%s", update_student.unit);
                    printf("������Ҫ�޸ĵ���Ŀ: ");
                    scanf("%s", update_student.item);

                    strcpy(student->name, update_student.name);    //����
                    student->gender = update_student.gender;
                    strcpy(student->unit, update_student.unit);
                    strcpy(student->item, update_student.item);

                    fwrite(student, sizeof(Student), 1, fp2);
                }

            }
        }
        if(student!=NULL) {
            free(student);
            student=NULL;
        }
        fclose(fp);
        fclose(fp2);
    }

    remove("student.dat");
    rename("student_tmp.dat","student.dat");
    printf("\n");
    printf("�޸ĳɹ�!\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    registerStudent();
}


void deleteStudent()
{
    bool same = 0;
    Student *student;
    student = (Student *)malloc(sizeof(Student));
    fp = fopen("student.dat", "r");
    fp2 = fopen("student_tmp.dat", "w");

    char delete_student_number[10];
    char delete_student_item[10];
    printf("������Ҫɾ����ѧ��ѧ��: ");
    scanf("%s", delete_student_number);
    printf("�������ѧ��Ҫɾ������Ŀ: ");
    scanf("%s", delete_student_item);

    while (!feof(fp)) {
        memset(student, 0, sizeof(Student));     //�ڴ�ռ��ʼ��
        if ((fread(student, sizeof(Student), 1, fp) != 0) && (strcmp(student->number, delete_student_number) != 0) && (strcmp(student->item, delete_student_item) != 0)) {
            fwrite(student, sizeof(Student), 1, fp2);     //ֻҪ����Ҫɾ�����Ǹ�ѧ�����Ǹ���Ŀ����д��fp2��
        } else if ((strcmp(student->number, delete_student_number) == 0) && (strcmp(student->item, delete_student_item) == 0)) {
            same = 1;
        }
    }

    if (student != NULL) {
        free(student);
        student = NULL;
    }

    fclose(fp2);
    fclose(fp);
    remove("student.dat");
    rename("student_tmp.dat", "student.dat");    //��fp2�ĳ�fp

    if (same == 0) {
        printf("û�����ѧ����\n");
    } else {
        printf("ɾ���ɹ�!\n");
    }

    printf("\n");
    printf("������������������������������������\n");
    printf("�����������..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    registerStudent();
}

void lookupStudent()
{

    Student *student;
    int tmp = 0;
    fp = fopen("student.dat","r");
    if (fp == NULL) {
        printf("��û��ѧ������!\n");
    } else {
        printf("\n");
        printf("******* �ѱ���ѧ���������� *******\n");
        printf("������������������������������������\n");
        printf("%-18s%-18s%-18s%-18s%-18s\n", "ѧ��", "����", "�Ա�", "ѧԺ", "��Ŀ");
        student = (Student *)malloc(sizeof(Student));
        while (!feof(fp)) {
            memset(student, 0, sizeof(Student));
            if (fread(student, sizeof(Student), 1, fp) != 0) {
                char *genderStr;
                if (student->gender == 0) {
                    genderStr = "��";
                } else {
                    genderStr = "Ů";
                }
                printf("%-18s%-18s%-18s%-18s%-18s\n", student->number, student->name, genderStr, student->unit, student->item);
                tmp = tmp + 1;
            }
            if (tmp == 0) {
                printf("\n");
                printf("��û��ѧ������!\n");
            }

        }

        if (student != NULL) {
            free(student);
            student = NULL;
        }
    }

    fclose(fp);
    printf("������������������������������������\n");
}


void setScore()
{
    int a;
    printf("\n");
    printf("********* ѧ���ɼ����� *********\n");
    printf("��������������������������������������������������������\n");
    printf("1�����óɼ�(ѧ��)\n");
    printf("2�����óɼ�(��Ŀ)\n");
    printf("3������\n");
    printf("��ѡ����: ");
    scanf("%d", &a);
    printf("��������������������������������������������������������\n");

    if (a == 1) {
        setPersonalScore();
    } else if (a == 2) {
        setItemScore();
    } else if (a == 3) {
        setSystemProperty();
    }
}



// score

void setPersonalScore()
{
    Player *player;
    //    Player update_player;
    player = (Player *)malloc(sizeof(Player));

    fp = fopen("player.dat", "r");
    fp2 = fopen("player_tmp.dat", "w");
    if (fp == NULL) {
        printf("û���κβ�������Ϣ!\n");
        setSystemProperty();
        return;
    } else {
        char update_player_number[10];
        float score = 0.0;
        printf("����������ߵ�ѧ��: ");
        scanf("%s", update_player_number);
        printf("����������ߵĳɼ�: ");
        scanf("%f", &score);

        while (!feof(fp)) {
            memset(player, 0, sizeof(Player));     //�ڴ�ռ��ʼ��
            if ((fread(player, sizeof(Player), 1, fp) != 0)) {
                if (strcmp(player->number, update_player_number) != 0)
                    fwrite(player, sizeof(Player), 1, fp2);     //ֻҪ����Ҫ�޸ĵ��Ǹ�ѧ������д��fp2��
                else if (strcmp(player->number, update_player_number) == 0) {
                    //�ҵ������ͬ��
                    player->score = score;
                    fwrite(player, sizeof(Player), 1, fp2);
                }

            }
        }
        if(player != NULL) {
            free(player);
            player = NULL;
        }
        fclose(fp);
        fclose(fp2);
    }

    remove("player.dat");
    rename("player_tmp.dat","player.dat");
    printf("\n");
    printf("�ɼ����óɹ�!\n");
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setScore();
}



void setItemScore()
{
    char item_name[50][10] = {""};

    Item *item = (Item *)malloc(sizeof(Item));
    FILE *fp_item = fopen("item.dat","rb");
    Player *player = (Player *)malloc(sizeof(Player));
    FILE *fp_player = fopen("player.dat", "rb");
    FILE *fp_player_update = fopen("player_tmp.dat", "wb");

    // data
    char player_name[50][10] = {""};
    float player_score[50] = {0.0};

    if ((fp_item == NULL) || (fp_player == NULL)) {
        printf("��û��������!\n");
    } else {
        int i = 0;
        char lItem[10] = "";
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if ((fread(player, sizeof(Player), 1, fp_player) != 0)) {
                if (strcmp(lItem, player->item) != 0) {
                    // ����Ŀ
                    strcpy(item_name[i], player->item);
                    i++;
                    strcpy(lItem, player->item);
                }
            }
        }
    }

    printf("��������Ŀ����( ");
    for (int i = 0; i < 50; i++) {
        if (i == 49) {
            if (strcmp(item_name[i], "") != 0)
                printf("%s", item_name[i]);
        } else {
            if (strcmp(item_name[i], "") != 0)
                printf("%s ", item_name[i]);
        }
    }
    printf("): ");
    char inputItem[10] = "";
    scanf("%s", inputItem);

    bool flag = 0;
    for (int i = 0; i < 50; i++) {
        if (strcmp(inputItem, item_name[i]) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag) {
        // �������Ŀ

    } else {
        // û�����Ŀ
        printf("\n�����������Ŀ!\n");
    }

    // �г����
    if (flag) {
        rewind(fp_player);
        int num = 0;
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if ((fread(player, sizeof(Player), 1, fp_player) != 0)) {
                if (strcmp(inputItem, player->item) == 0) {
                    // �ҵ�����Ŀ�����
                    strcpy(player_name[num], player->name);
                    num++;
                }
            }
        }

        // test
//        for (int i = 0; i < 50; i++) {
//            if (strcmp(player_name[i], "") != 0) {
//                printf("------  %s\n", player_name[i]);
//            }
//        }

        printf("\n��������: %s\n\n", inputItem);
//        int round = 1;
//        int numberOfPlayers = 0;

//        for (int i = 0; i < 50; i++) {
//            if (strcmp(player_name[i], "") == 0) {
//                break;
//            }
//
//            if (numberOfPlayers % NUM_OF_GROUP == 0) {
//                printf("           - �� %d �� -           \n", round);
//                round++;
//            }
//
//            for (int j = 0; j < NUM_OF_GROUP; j++) {
//                printf("%d��            ", j + 1);
//            }
//            printf("\n");
//
//            for (int j = 0; j < NUM_OF_GROUP; j++) {
//                printf("%-15s", player_name[i]);
//            }
//
//        }

        // ͳ��
        int numberOfPlayers = 0;
        for (int i = 0; i < 50; i++) {
            if (strcmp(player_name[i], "") == 0) {
                break;
            }
            numberOfPlayers++;
        }

        int row = numberOfPlayers / NUM_OF_GROUP + 1;
        for (int r = 0; r < row; r++) {
            // ����ÿһ��
            printf("           - �� %d �� -           \n", r + 1);

            int inputIndex = NUM_OF_GROUP;
            if (r == (row - 1)) {
                inputIndex = numberOfPlayers % NUM_OF_GROUP;
            }

            for (int j = 0; j < inputIndex; j++) {
                printf("%d��         ", j + 1);
            }
            printf("\n");
            for (int j = 0; j < inputIndex; j++) {
                printf("%-15s", player_name[r * NUM_OF_GROUP + j]);
            }
            printf("\n\n����ɼ�(�ո����ÿ���˵ĳɼ�): ");
            // ����
            for (int j = 0; j < inputIndex; j++) {
                if ((r * NUM_OF_GROUP + j) < 50) {
                    scanf("%f", &player_score[r * NUM_OF_GROUP + j]);
                }
            }

            printf("\n\n");
        }
    }





    // test
//    for (int i = 0; i < 50; i++) {
//        if (strcmp("", player_name[i]) != 0) {
//            printf("%s", player_name[i]);
//            printf(" - %.2f   ", player_score[i]);
//            if ((i+1) % 5 == 0) {
//                printf("\n");
//            }
//        }
//    }



    // ��������

    rewind(fp_player);
    rewind(fp_player_update);

    if (fp_player == NULL) {
        printf("û���κβ�������Ϣ!\n");
    } else {
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));     //�ڴ�ռ��ʼ��
            if ((fread(player, sizeof(Player), 1, fp_player) != 0)) {

                for (int i = 0; i < 50; i++) {

                    if (strcmp(player_name[i], "") == 0) {
                        break;
                    }

                    if (strcmp(player->name, player_name[i]) == 0) {
                        player->score = player_score[i];
                    }
                }

                fwrite(player, sizeof(Player), 1, fp_player_update);
            }
        }
    }


    // close
    fclose(fp_player);
    fclose(fp_player_update);
    fclose(fp_item);

    remove("player.dat");
    rename("player_tmp.dat","player.dat");


    printf("\n");
    if (flag) {
        printf("�ɼ����óɹ�!\n");
    } else {
        printf("�ɼ�����ʧ��!\n");
    }
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    setScore();
}


// Password
void setNewPassword()
{
    //free(fp3);
    // ֻ��Ҫ���û�����������  ��ȷ�϶Ա�һ�ο�����  ���þ����� ��Ϊ��ȥϵͳ�����Ѿ�����һ����
    printf("*****************************\n");

    Password *password;
    Password update_password;
    password = (Password *)malloc(sizeof(Password));

    FILE *fp4 = fopen("password.dat", "rb");
    FILE *fp2 = fopen("password_tmp.dat", "wb");
    if (fp4 == NULL) {
        printf("û��������!\n");
    } else {
        char pass_word_tmp[20];
        printf("������������: \n");
        scanf("%s", pass_word_tmp);
        while (!feof(fp4)) {
            memset(password, 0, sizeof(Password));     //�ڴ�ռ��ʼ��
            if ((fread(password, sizeof(struct Password), 1, fp4) != 0)) {
                printf("�ٴ�����������\n");
                scanf("%s", update_password.pass_word);

                if (strcmp(update_password.pass_word, pass_word_tmp) == 0) {
                    strcpy(password->pass_word, update_password.pass_word);    //����
                    fwrite(password, sizeof(struct Password), 1, fp2);
                    printf("�����޸ĳɹ�����\n");
                } else {
                    printf("������������벻һ��\n");
                    rewind(fp4); //����
                    while(!feof(fp4))    //��password.dat������븴�Ƶ�password_tmp.dat��
                        fputc(fgetc(fp4),fp2);
                    break;
                }
            }
        }
    }
    if(password!=NULL) {
        free(password);
        password=NULL;
    }
    fclose(fp4);
    fclose(fp2);
    remove("password.dat");
    rename("password_tmp.dat","password.dat");
    printf("\n");
    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();
    menu();
}

void InputPassword()
{
    //�������룬�Խ���ϵͳ���ý���
    printf("\n");
    printf("*****************************\n");
    printf("��û�����ù����룬��ע���ʼ����Ϊ0000\n");
    int a;
    Password *password;
    password = (Password *)malloc(sizeof(Password));

    FILE *fp4 = fopen("password.dat", "rb");
    if (fp4 == NULL) {
        printf("û��������!\n");
    } else {
        char pass_word_tmp[20];
        printf("����������: \n");
        scanf("%s", pass_word_tmp);
        while (!feof(fp4)) {
            memset(password, 0, sizeof(Password));     //�ڴ�ռ��ʼ��
            if ((fread(password, sizeof(struct Password), 1, fp4) != 0)) {
                if (strcmp(password->pass_word, pass_word_tmp) != 0) {
                    printf("������󣡣�\n");      //������󣬷������˵�
                    fclose(fp4);     //�ȹر��ļ����ٵ���menu����
                    printf("1.��������\n");
                    printf("2.�������˵�\n");
                    scanf("%d",&a);
                    if(a == 1) {
                        ForgotPassword();
                    } else {
                        menu();
                    }
                } else if (strcmp(password->pass_word, pass_word_tmp) == 0) {
                    //������ȷ����
                    printf("������ȷ����\n");
                    fclose(fp4);          //�ȹر��ļ����ٵ�����������
                    setSystemProperty();
                }

            }
        }
    }
    if (password!=NULL) {
        free(password);
        password=NULL;
    }
}


void ForgotPassword()
{
    //�������룬�жϹ���Ա����
    printf("********* �������� *********\n");
    printf("������������������������������������\n");

    Password *phoneNumber;
    phoneNumber = (Password *)malloc(sizeof(Password));
    FILE *fp2 = fopen("phoneNumber.dat","rb");
    char phone_tmp[20];

    printf("���������Ա֮һ�Ʒ���ֻ����룺\n");
    scanf("%s", phone_tmp);
    while (!feof(fp2)) {
        memset(phoneNumber, 0, sizeof(Password));     //�ڴ�ռ��ʼ��
        if ((fread(phoneNumber, sizeof(struct Password), 1, fp2) != 0)) {
            if (strcmp(phoneNumber->pass_word, phone_tmp) != 0) {
                printf("������󣡣�\n");      //������󣬷������˵�
                fclose(fp2);     //�ȹر��ļ����ٵ���menu����
                menu();
            } else if (strcmp(phoneNumber->pass_word, phone_tmp) == 0) {
                //������ȷ����
                printf("������ȷ����\n");
                printf("\n");
                fclose(fp2);          //�ȹر��ļ����ٵ�����������
                ForgotPassword2();
            }
        }
    }
}

void ForgotPassword2()
{
    //�������
    Password *showPassword;
    FILE *fp3 = fopen("password.dat","rb");
    if (fp3 == NULL) {
        printf("û������!\n");
    } else {
        int tmp = 0;
        showPassword = (Password *)malloc(sizeof(Password));
        while (!feof(fp3)) {
            memset(showPassword, 0, sizeof(Password));
            if (fread(showPassword, sizeof(struct Password), 1, fp3) !=0) {
                printf("����Ϊ��%s\n", showPassword->pass_word);
                tmp = tmp + 1;
            }
            if (tmp == 0) {
                printf("\n");
                printf("û������!\n");
            }
        }
        if (showPassword != NULL) {
            free(showPassword);
            showPassword = NULL;
        }
    }

    fclose(fp3);

    printf("������������������������������������\n");
    printf("����������ز˵�..\n");
    system("read -n1 -p '' key");  //����ʾ���ء��൱��windows�µ�getch();

    menu();
}
