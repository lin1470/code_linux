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
    int type; // 0 - 径赛   1 - 田赛
}Item;

typedef struct Unit{
    char name[30];
}Unit;

typedef struct Rule{
    char school_name[20];
    int minPeople;
    int score[5];
    int MaxItemPerAth; //每个运动员最多参加的项目数
}Rule;

typedef struct Student{
    char name[20];
    char number[10];
    int gender; // 0 - 男   1 - 女
    char unit[30];
    char item[10];
}Student;

typedef struct Player{
    char name[20];
    char number[10];
    int gender; // 0 - 男   1 - 女
    char school[20];
    char item[10];
    float score;
}Player;

typedef struct Password{
    char pass_word[20];
}Password;


// ----------------------------------------- 菜单函数 ----------------------------------------

//选手报名
void registerStudent()
{
    int a;
    printf("\n");
    printf("********* 参赛选手报名 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    lookupStudent();
    printf("\n");
    printf("1、添加学生信息  ");
    printf("2、修改学生信息  ");
    printf("3、删除学生信息  ");
    printf("4、返回\n");
    printf("请选择功能: ");
    scanf("%d", &a);
    printf("━━━━━━━━━━━━━━━━━━\n");

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

//比赛项目公布
void publishMatchItem()
{
    Item *item;
    fp = fopen("item.dat","r");
    if (fp == NULL) {
        printf("还没确定比赛项目!\n");
    } else {

        printf("\n");
        printf("********* 比赛项目公布 *********\n");
        printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
        printf("%-25s%-25s%-25s%-25s\n", "名称", "类型", "地点", "时长(分钟)");

        int tmp = 0;
        item = (Item *)malloc(sizeof(Item));
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp) != 0) {
                char *typeStr;
                if (item->type == 0) {
                    typeStr = "径塞";
                } else {
                    typeStr = "田塞";
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
                printf("还没确定比赛项目!\n");
            }
        }
        if (item != NULL) {
            free(item);
            item = NULL;
        }
    }

    fclose(fp);

    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    menu();
}

void setSystemProperty()
{
    int a;
    printf("\n");
    printf("********* 系统信息设置 *********\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("1、项目设置\n");
    printf("2、分数规则\n");
    printf("3、最低人数设置\n");
    printf("4、设置学校名字\n");
    printf("5、参赛单位设置\n");
    printf("6、成绩录入\n");
    printf("7、设置管理员新密码\n");
//    printf("6、每人最多参加的项目数\n");
    printf("8、返回\n");
    printf("请选择功能: ");
    scanf("%d", &a);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

    if (a == 1) {
        // 项目设置
        setItem();
    } else if (a == 2) {
        // 分数规则
        setScoreRule();
    } else if (a == 3) {
        // 最低人数设置
        setMinForItem();
    } else if (a == 4) {
        // 设置学校的名字，将会打印在主菜单最上端
        setSchoolName();
    } else if (a == 5) {
        //设置参数单位
        setUnit();
    } else if (a == 6) {
        // 成绩录入
        setScore();
    } else if (a == 7) {
        // 设置新密码
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
        printf("还没结束报名!\n");
    } else {
        //遍历item.dat把所有item的名称放到字符串数组item_name里
        int i = 0;
        while (!feof(fp_item)) {
            memset(item, 0, sizeof(Item));
            if ((fread(item, sizeof(Item), 1, fp_item) != 0)) {
                strcpy(item_name[i], item->name);
                item_span[i] = item->span;
                i = i + 1;
            }
        }

        //遍历student.dat得到每个项目的人数item_num[i]
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

        //分析每个项目的人数item_num[i]，并将项目满足最低人数的student复制到player
        FILE *fp4;
        Rule *rule = (Rule *)malloc(sizeof(Rule));
        fp4 = fopen("rule.dat", "r");
        if (fp4 == NULL) {
            printf("请设置每个项目的最少人数!\n");
        } else {
            int min = 0;
            rewind(fp4);
            memset(rule, 0, sizeof(Rule));     //内存空间初始化
            fread(rule, sizeof(Rule), 1, fp4);
            min = rule->minPeople;
            if (rule != NULL) {
                free(rule);
                rule = NULL;
            }
            fclose(fp4);

            // 遍历每个项目
            for (int i = 0; i < 50; i++) {
                // 如果项目符合要求(即>=min人数)
                if (item_num[i] >= min) {
                    // 添加player
                    rewind(fp2);
                    while (!feof(fp2)) {
                        memset(student, 0, sizeof(Student));
                        // 遍历每个学生(找到具有该项目的学生)
                        if ((fread(student, sizeof(Student), 1, fp2) != 0)) {
                            if (strcmp(student->item, item_name[i]) == 0) {
                                // 项目名称
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





            // 设置时间

            rewind(fp_item);
            rewind(fp_item_update);


            // 生成项目时间

            // 设置项目具体时间
            rewind(fp_item);
            rewind(fp_item_update);
            int last_time_flag = 0;
            Item *it = (Item *)malloc(sizeof(Item));
            while (!feof(fp_item)) {
                memset(it, 0, sizeof(Item));     //内存空间初始化
                if ((fread(it, sizeof(Item), 1, fp_item) != 0)) {
                    // 读到某一个项目  然后遍历是否有效的数组

                    for (int i = 0; i < 50; i++) {

                        if (strcmp(item_name[i], it->name) == 0) {
                            // 找到了
                            if (item_num[i] >= min) {
                                // 有效

                                int hour = OPENING_TIME_HOUR + last_time_flag / 60;

                                int tMin = OPENING_TIME_MIN + last_time_flag % 60;

                                int min = 0;

                                if (tMin >= 60) {
                                    hour++;
                                    min = tMin % 60;
                                } else {
                                    min = tMin;
                                }

                                sprintf(it->time, "%d时%d分", hour, min);
                                fwrite(it, sizeof(Item), 1, fp_item_update);
                                last_time_flag += (item_span[i] + ITEM_INTERVAL);
                                break;
                            } else {
                                // 无效
                                sprintf(it->time, "");
                                fwrite(it, sizeof(Item), 1, fp_item_update);
                                break;
                            }
                        }
                    }
                }
            }
        }
        printf("秩序册生成完毕!\n");

    }

    // 释放student
    if (student != NULL) {
        free(student);     //free释放了malloc所申请的内存
        student = NULL;    //将指针指向NULL
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
//        memset(it, 0, sizeof(Item));     //内存空间初始化
//        if ((fread(it, sizeof(Item), 1, fp6) != 0)) {
//            printf("--- --- %s\n", it->time);
//        }
//    }
//    fclose(fp6);
    //


    //*********以上得出player.dat

    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    menu();
}

void inquireOrder()
{
    printf("\n");
    printf("********* 秩序册 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    // 先获取项目信息
    FILE *fp_item = fopen("item.dat", "r");
    int item_span[50] = {0};
    char item_name[50][15] = {""};
    char item_place[50][15] = {""};
    char item_time[50][15] = {""};
    int item_num[50] = {0};  // 要来知道哪些比赛不能举行

    if (fp_item == NULL) {
        printf("还没确定比赛项目!\n");
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
                printf("还没确定比赛项目!\n");
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

    // 获取可用项目
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
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
                printf("还没有参赛选手信息!\n");
                menu();
                return;
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }




    // 获取玩家信息  并进行逻辑处理
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
        menu();
        return;
    } else {

        // 遍历比赛信息
        for (int i = 0; i < 50; i++) {
            if (strcmp("", item_name[i]) == 0) {
                continue;
            }
            if (item_num[i] > 0) {
                // 遇到非空比赛信息 需要呈现
                if (strcmp(item_place[i], "") == 0)
                {
                    // item_place[i] = "E403";
                    strcpy(item_place[i], "E403");
                }
                printf("\n比赛名称: %s    比赛时间: %s    时长: %d分钟    比赛地点: %s\n\n", item_name[i], item_time[i], item_span[i], item_place[i]);

                player = (Player *)malloc(sizeof(Player));
                // 遍历每个玩家
                int flag = 0; // 记录已经放了多少个玩家
                int round = 1;
                char room[NUM_OF_GROUP][10] = {""};  // 存着每一轮的比赛人员的临时变量
                rewind(fp_player);
                while (!feof(fp_player)) {
                    memset(player, 0, sizeof(Player));
                    if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                        // 获取到玩家信息了
                        if (strcmp(player->item, item_name[i]) == 0) {
                            //                            printf("------------- %s\n", player->name);
                            // 找到参加该项目的玩家
                            for (int j = 0; j < NUM_OF_GROUP; j++) {
                                // 将玩家放入就绪位置
                                if (strcmp("", room[j]) == 0) {
                                    // 有空位就可以放了
                                    flag++;
                                    strcpy(room[j], player->name);
                                    break;
                                }
                            }
                            // 检查这一轮是否放完
                            if (strcmp(room[NUM_OF_GROUP - 1], "") != 0 || flag >= item_num[i]) {
                                // 放完了
                                // 显示房间情况
                                printf("           - 第 %d 轮 -           \n", round);
                                for (int k = 0; k < NUM_OF_GROUP; k++) {
                                    printf("%d号         ", k + 1);
                                }
                                printf("\n");
                                // 打印并清理房间
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

    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    menu();

}

void inquireMatchInfo()
{
    printf("\n");
    printf("********* 参赛选手公布 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    printf("%-18s%-18s%-18s%-18s%-18s\n", "学号", "姓名", "性别", "学院", "项目");

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
        printf("还没确定比赛项目!\n");
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
                printf("还没确定比赛项目!\n");
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
        printf("还没有参赛选手信息!\n");
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
                // 看是否存在该学院在数组里了
                bool exist = FALSE;
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->school, school_name[j]) == 0) {
                        // 存在
                        school_num[j]++;
                        exist = TRUE;
                        break;
                    }
                }
                // 不存在的话
                if (!exist) {
                    for (int j = 0; j < 50; j++) {
                        // 将学院添加到数组里面
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
                    genderStr = "男";
                } else {
                    genderStr = "女";
                }

                printf("%-20s%-20s%-20s%-20s%-20s\n", player->number, player->name, genderStr, player->school, player->item);

                // 调试查看成绩用
                //                printf("%-20s%-20s%-20s%-20s%-20s%1.2f\n", player->number, player->name, genderStr, player->school, player->item, player->score);

                k++;
            }

            if (k == 0) {
                printf("\n");
                printf("还没有参赛选手信息!\n");
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }

    printf("以下是参加各个比赛项目的人数:\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    for (int i = 0; i < 50; i++) {
        if (item_num[i] > 0) {
            printf("%-15s%d人\n", item_name[i], item_num[i]);
        }
    }

    printf("以下是各个学院参加比赛项目的人数:\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    for (int i = 0; i < 50; i++) {
        if (school_num[i] > 0) {
            printf("%-15s%d人\n", school_name[i], school_num[i]);
        }
    }

    fclose(fp_player);
    fclose(fp_item);

    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    menu();
}

void inquireWholeScore()
{
    printf("\n");
    printf("********* 总体成绩公布 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    // 先获取项目信息
    FILE *fp_item = fopen("item.dat", "r");

    char item_name[50][10] = {""};
    char item_place[50][10] = {""};
    int item_type[50] = {0};
    char item_time[50][10]= {""};
    int item_num[50] = {0};  // 要来知道哪些比赛不能举行

    if (fp_item == NULL) {
        printf("还没确定比赛项目!\n");
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
                printf("还没确定比赛项目!\n");
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

    // 获取可用项目
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
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
                printf("还没有参赛选手信息!\n");
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

    // 获取玩家信息  并进行逻辑处理
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
        inquireMatchScore();
        return;
    } else {

        // 遍历比赛信息
        int currentItem = 0;
        for (int i = 0; i < 50; i++) {
            if (strcmp("", item_name[i]) == 0) {
                continue;
            }
            if (item_num[i] > 0) {
                // 遇到非空比赛信息 需要呈现
                printf("\n比赛名称: %s    比赛时间: %s    比赛地点: %s\n\n", item_name[i], item_time[i], item_place[i]);

                player = (Player *)malloc(sizeof(Player));
                // 遍历每个玩家
                rewind(fp_player);
                while (!feof(fp_player)) {
                    memset(player, 0, sizeof(Player));
                    if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                        // 获取到玩家信息了
                        if (strcmp(player->item, item_name[i]) == 0) {
                            //                            printf("------------- %s\n", player->name);
                            // 找到参加该项目的玩家
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

                // 考虑空元素的冒泡排序
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
                        // 根据type
                        if (item_type[i] == 0) {
                            // 径赛
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
                            // 田赛
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
                printf("%-16s%-16s%-16s%-16s%-16s\n", "第一名", "第二名", "第三名", "第四名", "第五名");
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
                            typeStr = "秒";
                        } else {
                            typeStr = "米";
                        }
                        printf("%1.2f%s       ", rankList[currentItem][n]->score, typeStr);
                    }
                }

                printf("\n\n其他参赛人员排名: \n");
                for (int n = 5; n < 50; n++) {
                    if (rankList[currentItem][n] != NULL) {
                        char *typeStr = "";
                        if (item_type[i] == 0) {
                            typeStr = "秒";
                        } else {
                            typeStr = "米";
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

    // 拿到学院总分

    // 先获取分数规则
    FILE *fp_rule = fopen("rule.dat", "r");

    int score_rule[5] = {0};

    rewind(fp_rule);
    if (fp_rule == NULL) {
        printf("还没有分数规则信息!\n");
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
                printf("还没有分数规则信息!\n");
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

    // 获取学院信息
    int school_score[50] = {0};
    char school_name[50][20] = {""};

    rewind(fp_player);
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {

                // school
                // 看是否存在该学院在数组里了
                bool exist = FALSE;
                for (int j = 0; j < 50; j++) {
                    if (strcmp(player->school, school_name[j]) == 0) {
                        // 存在
                        exist = TRUE;
                        break;
                    }
                }
                // 不存在的话
                if (!exist) {
                    for (int j = 0; j < 50; j++) {
                        // 将学院添加到数组里面
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
                printf("还没有参赛选手信息!\n");
            }
        }
        if (player != NULL) {
            free(player);
            player = NULL;
        }
    }

    fclose(fp_player);

    printf("\n以下是各个学院的得分总数: \n");

    for (int i = 0; i < 50; i++) {
        // 其中某一项比赛
        //        printf("----- %d\n", i);
        int rank = 0;
        for (int j = 0; j < 50; j++) {
            // 获取该学生的学院
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

    // 显示
    printf("学院       得分\n");
    for (int i = 0; i < 50; i++) {
        if (strcmp("", school_name[i]) == 0) {
            continue;
        }
        printf("%s      %d分\n", school_name[i], school_score[i]);
    }


    printf("\n━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    inquireMatchScore();
}

void inquireIndividualScore()
{
    printf("\n");
    printf("********* 个人成绩查询 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    // 先获取项目信息
    FILE *fp_item = fopen("item.dat", "r");

    char item_name[50][10] = {""};
    int item_type[50] = {0};

    if (fp_item == NULL) {
        printf("还没确定比赛项目!\n");
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
                printf("还没确定比赛项目!\n");
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
    printf("请输入参赛者的学号: ");
    scanf("%s", number);

    Player *player;
    FILE *fp_player = fopen("player.dat","r");

    // 获取可用项目
    rewind(fp_player);
    if (fp_player == NULL) {
        printf("还没有参赛选手信息!\n");
    } else {
        int k = 0;
        player = (Player *)malloc(sizeof(Player));
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if (fread(player, sizeof(Player), 1, fp_player) != 0) {
                if (strcmp(player->number, number) == 0) {
                    // 找到这个参赛者

                    // 确定类型
                    char *typeStr = "";

                    for (int i = 0; i < 50; i++) {
                        if (strcmp(item_name[i], player->item) == 0) {
                            if (item_type[i] == 0) {
                                typeStr = "米";
                            } else {
                                typeStr = "秒";
                            }
                        }
                    }

                    // 显示
                    printf("学号: %s   姓名: %s   比赛: %s   成绩: %1.2f%s", player->number, player->name, player->item, player->score, typeStr);
                }
                k++;
            }
            if (k == 0) {
                printf("\n");
                printf("还没有参赛选手信息!\n");
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

    printf("\n━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    inquireMatchScore();
}




void inquireMatchScore()
{
    int a;
    printf("\n");
    printf("********* 比赛成绩查询 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("1、总体查询\n");
    printf("2、个人查询\n");
    printf("3、返回\n");
    printf("请选择功能: ");
    scanf("%d", &a);
    printf("━━━━━━━━━━━━━━━━━━\n");

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
    printf("\n          当前时间: %4d年%02d月%02d日 %d:%d",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday,ptr->tm_hour,ptr->tm_min);
    char school_name[20];
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if ((fp = fopen("rule.dat", "rb")) == NULL) {
        strcpy(school_name,"");
    } else {
        rewind(fp); //重置
        memset(rule, 0, sizeof(Rule));
        fread(rule, sizeof(Rule), 1, fp);
        strcpy(school_name, rule->school_name);
    }

    fclose(fp);

    printf("\n");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("         ****** %s运动会管理系统 ******          \n", school_name);
    printf("┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");

    for (int i = 0; i < 8; ++i) {
        char *title;
        switch (i) {
            case 0:
                title = "比赛项目公布";
                break;
            case 1:
                title = "参赛选手报名";
                break;
            case 2:
                title = "生成秩序册";
                break;
            case 3:
                title = "查看秩序册";
                break;
            case 4:
                title = "参赛信息查询";
                break;
            case 5:
                title = "比赛成绩查询";
                break;
            case 6:
                title = "系统信息设置";
                break;
            case 7:
                title = "退出管理系统";
                break;
            default:
                break;
        }

        printf("%18.d、%s\n", i + 1, title);
    }

    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    printf("请选择功能: ");
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


// ----------------------------------------- 项目设置 ----------------------------------------
//查看所有项目
void setItem()
{
    Item *item;
    int tmp = 0;
    fp = fopen("item.dat","r");
    if (fp == NULL) {
        printf("还没确定比赛项目!\n");
        fp = fopen("item.dat","wb+");
    } else {
        printf("\n");
        printf("比赛项目\n");
        printf("━━━━━━━━━━━━━━━━\n");
        printf("%-25s%-25s%-25s%-25s\n", "名称", "类型", "时长(分钟)", "地点");

        item = (Item *)malloc(sizeof(Item));
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));
            if (fread(item, sizeof(Item), 1, fp) != 0) {
                char *typeStr;
                if (item->type == 0) {
                    typeStr = "径赛";
                } else {
                    typeStr = "田赛";
                }

                if (strcmp("", item->place) == 0) {
                    strcpy(item->place, "E403");
                }

                printf("%-25s%-25s%-25d%-25s\n", item->name, typeStr, item->span, item->place);
                tmp = tmp + 1;
            }

            if (tmp == 0) {
                printf("\n");
                printf("还没确定比赛项目!\n");


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
    printf("1、添加项目  ");
    printf("2、修改项目  ");
    printf("3、删除项目  ");
    printf("4、返回\n");
    printf("请选择功能 :");
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
// 添加项目
void addItem()
{
    bool same = false;
    Item *item = (Item *)malloc(sizeof(Item));
    if((fp = fopen("item.dat","rb+")) == NULL) {     //以读/写方式打开一个二进制文件进行追加
        fp = fopen("item.dat", "wb+");   //不存在就创建
    }

    printf("请输入项目名称: ");
    scanf("%s", item->name);
    printf("请输入项目类型(0 - 径赛  1 - 田赛): ");
    scanf("%d", &item->type);
    printf("请输入项目比赛时长(分钟): ");
    scanf("%d", &item->span);
    printf("请输入项目地点: ");
    scanf("%s", item->place);

    // 检查是否存在
    rewind(fp); // <!-非常关键-!> 重置访问文件的指针
    Item *local_item = (Item *)malloc(sizeof(Item));
    while (!feof(fp)) {
        memset(local_item, 0, sizeof(Item));     //内存空间初始化
        // 遍历一遍看有没有已经存在的相同的项目名字
        if (fread(local_item, sizeof(Item), 1, fp) != 0) {

            if (strcmp(local_item->name, item->name) == 0) {
                // 名字相同 要求再次输入
                same = TRUE;
                printf("该项目已存在，请重新输入！\n");
            }
        }
    }


    // 写入
    fwrite(item, sizeof(Item), 1, fp);
    memset(item, 0, sizeof(Item));     //内存空间初始化

    if (item != NULL) {
        free(item);     //free释放了malloc所申请的内存
        item = NULL;    //将指针指向NULL
    }

    fclose(fp);
    printf("\n");
    printf("添加成功!\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setItem();
}

// 修改项目
void editItem()
{

    Item *item = (Item *)malloc(sizeof(Item));
    Item update_item;

    fp = fopen("item.dat", "r");
    fp2 = fopen("item_tmp.dat", "w");
    if (fp == NULL) {
        printf("没有任何项目!");
    } else {
        char update_item_name[10];
        printf("请输入要修改的项目的名称: ");
        scanf("%s", update_item_name);
        while (!feof(fp)) {
            memset(item, 0, sizeof(Item));     //内存空间初始化
            if ((fread(item, sizeof(Item), 1, fp) != 0)) {
                if (strcmp(item->name, update_item_name) != 0)
                    fwrite(item, sizeof(Item), 1, fp2);     //只要不是要修改的那个项目，就写进fp2里
                else if (strcmp(item->name, update_item_name) == 0) {
                    //找到这个相同的
                    printf("请输入要修改的项目的类型: (0 - 径赛  1 - 田赛)");
                    scanf("%d", &update_item.type);
                    printf("请输入要修改的项目的时间(分钟): ");
                    scanf("%d", &update_item.span);
                    printf("请输入要修改的项目的地点: ");
                    scanf("%s", update_item.place);
                    strcpy(item->name, update_item_name);    //复制
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
    printf("修改成功!\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setItem();
}

// 删除项目
void deleteItem()
{
    bool same = 0;
    Item *item = (Item *)malloc(sizeof(Item));
    fp = fopen("item.dat", "r");
    fp2 = fopen("item_tmp.dat", "w");

    char delete_item_name[10];
    printf("请输入要删除的项目的名称: ");
    scanf("%s", delete_item_name);

    while (!feof(fp)) {
        memset(item, 0, sizeof(Item));     //内存空间初始化
        if ((fread(item, sizeof(Item), 1, fp) != 0) && (strcmp(item->name, delete_item_name) != 0)) {
            fwrite(item, sizeof(Item), 1, fp2);     //只要不是要删除的那个项目，就写进fp2里
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
    rename("item_tmp.dat", "item.dat");    //把fp2改成fp

    if (same == 0) {
        printf("没有这个项目！\n");
    } else {
        printf("删除成功!\n");
    }

    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setItem();
}


// 最少人数
void setMinForItem()
{
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if((fp = fopen("rule.dat","rb+")) == NULL) {     //以读/写方式打开一个二进制文件
        fp = fopen("rule.dat", "wb+");   //不存在就创建
    }

    // 重置
    rewind(fp);
    // 读取
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //重置
    int minNum = 0;
    printf("请输入每个项目的最少人数: ");
    scanf("%d", &minNum);

    rule->minPeople = minNum;

    // 写入
    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));     //内存空间初始化

    if (rule != NULL) {
        free(rule);     //free释放了malloc所申请的内存
        rule = NULL;    //将指针指向NULL
    }

    fclose(fp);
    printf("\n");
    printf("设置成功!  <当前最少人数为%d人>\n", minNum);
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setSystemProperty();
}


// 设置分数
void setScoreRule()
{
    Rule *rule = (Rule *)malloc(sizeof(Rule));
    if((fp = fopen("rule.dat","rb+")) == NULL) {     //以读/写方式打开一个二进制文件
        fp = fopen("rule.dat", "wb+");   //不存在就创建
    }

    // 临时
    int temp[5] = {0};

    // 重置
    rewind(fp);

    // 读取
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //重置


    for (int i = 0; i < 5; i++) {

        char *str;
        switch (i) {
            case 0:
                str = "一";
                break;
            case 1:
                str = "二";
                break;
            case 2:
                str = "三";
                break;
            case 3:
                str = "四";
                break;
            case 4:
                str = "五";
                break;
            default:
                break;
        }
        printf("请输入第%s名可获得的分数: ", str);
        int score = 0;
        scanf("%d", &score);
        rule->score[i] = score;
        temp[i] = score;
    }

    // 写入
    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));     //内存空间初始化


    if (rule != NULL) {
        free(rule);     //free释放了malloc所申请的内存
        rule = NULL;    //将指针指向NULL
    }

    fclose(fp);

    printf("\n");
    printf("设置成功!   <");
    for (int i = 0; i < 5; i++) {
        char *str;
        switch (i) {
            case 0:
                str = "一";
                break;
            case 1:
                str = "二";
                break;
            case 2:
                str = "三";
                break;
            case 3:
                str = "四";
                break;
            case 4:
                str = "五";
                break;

            default:
                break;
        }
        printf("第%s名 %d分", str, temp[i]);
        if (i < 4) {
            printf("   ");
        }
    }
    printf(">\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setSystemProperty();
}

void setSchoolName()
{
    Rule *rule = (Rule*)malloc(sizeof(Rule));
    if ((fp = fopen("rule.dat", "rb+")) == NULL) { //以读/写方式打开一个二进制文件
        fp = fopen("rule.dat", "wb+");      //不存在就创建
    }

    rewind(fp);  //重置
    fread(rule, sizeof(Rule), 1, fp);
    rewind(fp);  //重置
    char school_name[20];
    printf("请输入学校(比赛单位)的名称: ");
    scanf("%s", school_name);

    strcpy(rule->school_name, school_name);

    fwrite(rule, sizeof(Rule), 1, fp);
    memset(rule, 0, sizeof(Rule));  //内存空间初始化

    if (rule != NULL) {
        free(rule);   //free释放了malloc所申请的内存
        rule = NULL;    //将指针只指向NULL
    }

    fclose(fp);
    printf("\n");
    printf("设置成功!\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setSystemProperty();
}

void printAllUnit()
{
    Unit *unit;
    int tmp = 0;
    if ((fp = fopen("unit.dat", "rb+")) == NULL) {
        fp = fopen("unit.dat", "wb+");
        printf("还没有任何参数单位!\n");
    } else {
        printf("\n");
        printf("参赛单位\n");
        printf("━━━━━━━━━━━━━━━━\n");

        unit = (Unit*)malloc(sizeof(Unit));
        while (!feof(fp)) {
            memset(unit, 0, sizeof(Unit));
            if ((fread(unit, sizeof(Unit), 1, fp) != 0)) {
                printf("%s\n", unit->name);
                tmp = tmp + 1;
            }

            if (tmp == 0) {
                printf("还没任何参赛单位!\n");

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
    printf("1、添加参赛单位   ");
    printf("2、删除参赛单位   ");
    printf("3、返回\n");
    printf("请选择功能 :");
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
    if((fp = fopen("unit.dat","rb+")) == NULL) {     //以读/写方式打开一个二进制文件进行追加
        fp = fopen("unit.dat", "wb+");   //不存在就创建
    }

    char temp_name[30];
    printf("请输入参赛单位名称: ");
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
        printf("已存在此参赛单位!\n");

    } else if (same == false) {
        strcpy(unit->name, temp_name);
        fwrite(unit, sizeof(Unit), 1, fp);
        memset(unit, 0, sizeof(Unit));
        printf("添加成功!\n");
    }

    if (unit != NULL) {
        free(unit);
        unit = NULL;
    }

    fclose(fp);
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setUnit();

};

void deleteUnit()
{
    bool same = false;
    Unit *unit = (Unit *)malloc(sizeof(Unit));
    fp = fopen("unit.dat", "r");
    fp2 = fopen("unit_tmp.dat", "w");

    char delete_unit_name[30];
    printf("请输入要删除的参赛单位的名称: ");
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
        printf("没有这个项目! \n");
    } else {
        printf("删除成功!\n");
    }

    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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
    printf("请输入每位运动员最多参加的项目数: ");
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
    printf("设置成功!\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setSystemProperty();

}

// ----------------------------------------- 报名设置 ----------------------------------------




void addStudent()
{
    //将参赛单位读到数组里
    char unit_tmp[20][30];
    int num_unit = 0;
    {
        Unit *unit;
        if ((fp = fopen("unit.dat", "rb+")) == NULL) {
            fp = fopen("unit.dat", "wb+");
            printf("还没有任何参数单位!\n");
            printf("请设置参赛单位后再添加学生!\n");
            printf("按任意键返回菜单..\n");

            system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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

    //将项目放进数组里
    char item_tmp[20][20];
    int num_item = 0;
    {
        Item *item;
        if ((fp = fopen("item.dat", "rb+")) == NULL) {
            fp = fopen("item.dat", "wb+");
            printf("还没有任何比赛项目!\n");
            printf("请设置比赛项目后再添加学生!\n");
            printf("按任意键返回菜单..\n");
            system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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

    if((fp = fopen("student.dat","rb+")) == NULL) {     //以读/写方式打开一个二进制文件进行追加
        fp = fopen("student.dat", "wb+");   //不存在就创建
    }

    //读出rule->maxItemPerAth
    int max = 0;
    Rule *rule = (Rule*)malloc(sizeof(Rule));
    fp2 = fopen("rule.dat", "r");
    if (fp2 == NULL) {
        printf("默认每个运动员最多能参加3项比赛\n");
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


    printf("请输入学号: ");
    scanf("%s", student->number);
    printf("请输入姓名: ");
    scanf("%s", student->name);
    printf("(0 - 男   1 - 女)请输入性别: ");
    scanf("%d", &student->gender);

    { //列出参赛单位再输入
        printf("(");
        for (int j = 0; j < num_unit; j++) {
            printf("%s ", unit_tmp[j]);
        }
        printf(")");
        printf(" 请输入参赛单位: ");
        scanf("%s", student->unit);
    }

    { //列出比赛项目后再输入
        printf("(");
        for (int j = 0; j < num_item; j++) {
            printf("%s ", item_tmp[j]);
        }
        printf(")");
        printf("请输入项目名称: ");
        scanf("%s", student->item);
    }




    int tmp = 0;
    // 检查是否存在
    rewind(fp); // <!-非常关键-!> 重置访问文件的指针
    Student *local_student = (Student *)malloc(sizeof(Student));
    while (!feof(fp)) {
        memset(local_student, 0, sizeof(Student));     //内存空间初始化
        // 遍历一遍看有没有已经存在的相同的项目名字
        if (fread(local_student, sizeof(Student), 1, fp) != 0) {

            if (strcmp(local_student->number, student->number) == 0) {
                // 学号相同
                tmp = tmp + 1;
                //学号和项目都相同
                if (strcmp(local_student->item, student->item) == 0) {
                    same = true;
                }
            }
        }
    }

    if (same == true) {
        // 不能报名
        printf("添加失败!你已报名此项目!");
    } else if (tmp >= max) {
        printf("添加失败!每个人最多只能报%d项!\n", max);
    } else if ((same == false) && (tmp < max)) {
        // 新增
        fwrite(student, sizeof(Student), 1, fp);
        memset(student, 0, sizeof(Student));     //内存空间初始化
        printf("添加成功!\n");
    }

    if (student != NULL) {
        free(student);     //free释放了malloc所申请的内存
        student = NULL;    //将指针指向NULL
    }

    fclose(fp);
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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
        printf("没有任何报名者信息!\n");
    } else {
        char update_student_number[10];
        printf("请输入要修改的学生的学号: \n");
        scanf("%s", update_student_number);
        while (!feof(fp)) {
            memset(student, 0, sizeof(Student));     //内存空间初始化
            if ((fread(student, sizeof(Student), 1, fp) != 0)) {
                if (strcmp(student->number, update_student_number) != 0)
                    fwrite(student, sizeof(Student), 1, fp2);     //只要不是要修改的那个学生，就写进fp2里
                else if (strcmp(student->number, update_student_number) == 0) {
                    //找到这个相同的
                    printf("请输入要修改的姓名: ");
                    scanf("%s", update_student.name);
                    printf("请输入要修改的性别(0 - 男  1 - 女): ");
                    scanf("%d", &update_student.gender);
                    printf("请输入要修改的学院: ");
                    scanf("%s", update_student.unit);
                    printf("请输入要修改的项目: ");
                    scanf("%s", update_student.item);

                    strcpy(student->name, update_student.name);    //复制
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
    printf("修改成功!\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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
    printf("请输入要删除的学生学号: ");
    scanf("%s", delete_student_number);
    printf("请输入此学生要删除的项目: ");
    scanf("%s", delete_student_item);

    while (!feof(fp)) {
        memset(student, 0, sizeof(Student));     //内存空间初始化
        if ((fread(student, sizeof(Student), 1, fp) != 0) && (strcmp(student->number, delete_student_number) != 0) && (strcmp(student->item, delete_student_item) != 0)) {
            fwrite(student, sizeof(Student), 1, fp2);     //只要不是要删除的那个学生的那个项目，就写进fp2里
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
    rename("student_tmp.dat", "student.dat");    //把fp2改成fp

    if (same == 0) {
        printf("没有这个学生！\n");
    } else {
        printf("删除成功!\n");
    }

    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    registerStudent();
}

void lookupStudent()
{

    Student *student;
    int tmp = 0;
    fp = fopen("student.dat","r");
    if (fp == NULL) {
        printf("还没有学生报名!\n");
    } else {
        printf("\n");
        printf("******* 已报名学生名单公布 *******\n");
        printf("━━━━━━━━━━━━━━━━━━\n");
        printf("%-18s%-18s%-18s%-18s%-18s\n", "学号", "姓名", "性别", "学院", "项目");
        student = (Student *)malloc(sizeof(Student));
        while (!feof(fp)) {
            memset(student, 0, sizeof(Student));
            if (fread(student, sizeof(Student), 1, fp) != 0) {
                char *genderStr;
                if (student->gender == 0) {
                    genderStr = "男";
                } else {
                    genderStr = "女";
                }
                printf("%-18s%-18s%-18s%-18s%-18s\n", student->number, student->name, genderStr, student->unit, student->item);
                tmp = tmp + 1;
            }
            if (tmp == 0) {
                printf("\n");
                printf("还没有学生报名!\n");
            }

        }

        if (student != NULL) {
            free(student);
            student = NULL;
        }
    }

    fclose(fp);
    printf("━━━━━━━━━━━━━━━━━━\n");
}


void setScore()
{
    int a;
    printf("\n");
    printf("********* 学生成绩设置 *********\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("1、设置成绩(学号)\n");
    printf("2、设置成绩(项目)\n");
    printf("3、返回\n");
    printf("请选择功能: ");
    scanf("%d", &a);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");

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
        printf("没有任何参赛者信息!\n");
        setSystemProperty();
        return;
    } else {
        char update_player_number[10];
        float score = 0.0;
        printf("请输入参赛者的学号: ");
        scanf("%s", update_player_number);
        printf("请输入参赛者的成绩: ");
        scanf("%f", &score);

        while (!feof(fp)) {
            memset(player, 0, sizeof(Player));     //内存空间初始化
            if ((fread(player, sizeof(Player), 1, fp) != 0)) {
                if (strcmp(player->number, update_player_number) != 0)
                    fwrite(player, sizeof(Player), 1, fp2);     //只要不是要修改的那个学生，就写进fp2里
                else if (strcmp(player->number, update_player_number) == 0) {
                    //找到这个相同的
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
    printf("成绩设置成功!\n");
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
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
        printf("还没结束报名!\n");
    } else {
        int i = 0;
        char lItem[10] = "";
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if ((fread(player, sizeof(Player), 1, fp_player) != 0)) {
                if (strcmp(lItem, player->item) != 0) {
                    // 找项目
                    strcpy(item_name[i], player->item);
                    i++;
                    strcpy(lItem, player->item);
                }
            }
        }
    }

    printf("请输入项目名称( ");
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
        // 有这个项目

    } else {
        // 没这个项目
        printf("\n不存在这个项目!\n");
    }

    // 列出玩家
    if (flag) {
        rewind(fp_player);
        int num = 0;
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));
            if ((fread(player, sizeof(Player), 1, fp_player) != 0)) {
                if (strcmp(inputItem, player->item) == 0) {
                    // 找到该项目的玩家
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

        printf("\n比赛名称: %s\n\n", inputItem);
//        int round = 1;
//        int numberOfPlayers = 0;

//        for (int i = 0; i < 50; i++) {
//            if (strcmp(player_name[i], "") == 0) {
//                break;
//            }
//
//            if (numberOfPlayers % NUM_OF_GROUP == 0) {
//                printf("           - 第 %d 轮 -           \n", round);
//                round++;
//            }
//
//            for (int j = 0; j < NUM_OF_GROUP; j++) {
//                printf("%d号            ", j + 1);
//            }
//            printf("\n");
//
//            for (int j = 0; j < NUM_OF_GROUP; j++) {
//                printf("%-15s", player_name[i]);
//            }
//
//        }

        // 统计
        int numberOfPlayers = 0;
        for (int i = 0; i < 50; i++) {
            if (strcmp(player_name[i], "") == 0) {
                break;
            }
            numberOfPlayers++;
        }

        int row = numberOfPlayers / NUM_OF_GROUP + 1;
        for (int r = 0; r < row; r++) {
            // 处理每一组
            printf("           - 第 %d 轮 -           \n", r + 1);

            int inputIndex = NUM_OF_GROUP;
            if (r == (row - 1)) {
                inputIndex = numberOfPlayers % NUM_OF_GROUP;
            }

            for (int j = 0; j < inputIndex; j++) {
                printf("%d号         ", j + 1);
            }
            printf("\n");
            for (int j = 0; j < inputIndex; j++) {
                printf("%-15s", player_name[r * NUM_OF_GROUP + j]);
            }
            printf("\n\n输入成绩(空格隔开每个人的成绩): ");
            // 输入
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



    // 保存数据

    rewind(fp_player);
    rewind(fp_player_update);

    if (fp_player == NULL) {
        printf("没有任何参赛者信息!\n");
    } else {
        while (!feof(fp_player)) {
            memset(player, 0, sizeof(Player));     //内存空间初始化
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
        printf("成绩设置成功!\n");
    } else {
        printf("成绩设置失败!\n");
    }
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    setScore();
}


// Password
void setNewPassword()
{
    //free(fp3);
    // 只需要让用户输入新密码  再确认对比一次可以了  不用旧密码 因为进去系统设置已经输了一次了
    printf("*****************************\n");

    Password *password;
    Password update_password;
    password = (Password *)malloc(sizeof(Password));

    FILE *fp4 = fopen("password.dat", "rb");
    FILE *fp2 = fopen("password_tmp.dat", "wb");
    if (fp4 == NULL) {
        printf("没有设密码!\n");
    } else {
        char pass_word_tmp[20];
        printf("请输入新密码: \n");
        scanf("%s", pass_word_tmp);
        while (!feof(fp4)) {
            memset(password, 0, sizeof(Password));     //内存空间初始化
            if ((fread(password, sizeof(struct Password), 1, fp4) != 0)) {
                printf("再次输入新密码\n");
                scanf("%s", update_password.pass_word);

                if (strcmp(update_password.pass_word, pass_word_tmp) == 0) {
                    strcpy(password->pass_word, update_password.pass_word);    //复制
                    fwrite(password, sizeof(struct Password), 1, fp2);
                    printf("密码修改成功！！\n");
                } else {
                    printf("您输的两次密码不一致\n");
                    rewind(fp4); //重置
                    while(!feof(fp4))    //把password.dat里的密码复制到password_tmp.dat里
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
    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();
    menu();
}

void InputPassword()
{
    //输入密码，以进入系统设置界面
    printf("\n");
    printf("*****************************\n");
    printf("若没有设置过密码，请注意初始密码为0000\n");
    int a;
    Password *password;
    password = (Password *)malloc(sizeof(Password));

    FILE *fp4 = fopen("password.dat", "rb");
    if (fp4 == NULL) {
        printf("没有设密码!\n");
    } else {
        char pass_word_tmp[20];
        printf("请输入密码: \n");
        scanf("%s", pass_word_tmp);
        while (!feof(fp4)) {
            memset(password, 0, sizeof(Password));     //内存空间初始化
            if ((fread(password, sizeof(struct Password), 1, fp4) != 0)) {
                if (strcmp(password->pass_word, pass_word_tmp) != 0) {
                    printf("密码错误！！\n");      //密码错误，返回主菜单
                    fclose(fp4);     //先关闭文件，再调用menu方法
                    printf("1.忘记密码\n");
                    printf("2.返回主菜单\n");
                    scanf("%d",&a);
                    if(a == 1) {
                        ForgotPassword();
                    } else {
                        menu();
                    }
                } else if (strcmp(password->pass_word, pass_word_tmp) == 0) {
                    //密码正确！！
                    printf("密码正确！！\n");
                    fclose(fp4);          //先关闭文件，再调用其他方法
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
    //忘记密码，判断管理员号码
    printf("********* 忘记密码 *********\n");
    printf("━━━━━━━━━━━━━━━━━━\n");

    Password *phoneNumber;
    phoneNumber = (Password *)malloc(sizeof(Password));
    FILE *fp2 = fopen("phoneNumber.dat","rb");
    char phone_tmp[20];

    printf("请输入管理员之一黄蜂的手机号码：\n");
    scanf("%s", phone_tmp);
    while (!feof(fp2)) {
        memset(phoneNumber, 0, sizeof(Password));     //内存空间初始化
        if ((fread(phoneNumber, sizeof(struct Password), 1, fp2) != 0)) {
            if (strcmp(phoneNumber->pass_word, phone_tmp) != 0) {
                printf("号码错误！！\n");      //密码错误，返回主菜单
                fclose(fp2);     //先关闭文件，再调用menu方法
                menu();
            } else if (strcmp(phoneNumber->pass_word, phone_tmp) == 0) {
                //号码正确！！
                printf("号码正确！！\n");
                printf("\n");
                fclose(fp2);          //先关闭文件，再调用其他方法
                ForgotPassword2();
            }
        }
    }
}

void ForgotPassword2()
{
    //输出密码
    Password *showPassword;
    FILE *fp3 = fopen("password.dat","rb");
    if (fp3 == NULL) {
        printf("没有密码!\n");
    } else {
        int tmp = 0;
        showPassword = (Password *)malloc(sizeof(Password));
        while (!feof(fp3)) {
            memset(showPassword, 0, sizeof(Password));
            if (fread(showPassword, sizeof(struct Password), 1, fp3) !=0) {
                printf("密码为：%s\n", showPassword->pass_word);
                tmp = tmp + 1;
            }
            if (tmp == 0) {
                printf("\n");
                printf("没有密码!\n");
            }
        }
        if (showPassword != NULL) {
            free(showPassword);
            showPassword = NULL;
        }
    }

    fclose(fp3);

    printf("━━━━━━━━━━━━━━━━━━\n");
    printf("按任意键返回菜单..\n");
    system("read -n1 -p '' key");  //无显示返回。相当于windows下的getch();

    menu();
}
