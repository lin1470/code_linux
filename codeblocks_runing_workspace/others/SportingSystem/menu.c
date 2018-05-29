
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int n = 0;

extern int projectNum;
extern int getState();
extern int state;
void viewMenu();
extern char password[20];

//“控制”选项
void control(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            makeOrder();
            break;

    }
}
//“密码”选项
void manage(int n) {
    switch (n) {
        case 0:
            viewMenu();
            break;
        case 1:
            changeState();
            system("pause");
            viewMenu();
            break;
        case 2:
            setPassword();
            break;
    }
}

void menu(int n){

    char c;

    switch (n){
        case 1:
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","查看报名情况(1)",
                   "导入报名表（2)","导出报名表(3)","查看现有项目(4)","保存(5)","返回(0)");
            file(getItemNum(0,5,"请输入菜单项："));
            break;
        case 2:
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","添加运动员(1)",
                   "删除运动员(2)","更改运动员信息(3)","新建项目(4)","信息检索(5)","返回(0)");
            int i = getItemNum(0,5,"请输入菜单项：");
            if(i==1 && projectNum == 0 ){
                printf("请先建立参赛项目！\n");
                system("pause");
                viewMenu();
                break;
            }
            edit(i);
            break;
        case 3:
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","生成秩序册(1)","赛果汇总(2)","返回(0)");
            control(getItemNum(0,2,"请输入菜单项："));
            break;
        case 4:
            if(state == 0){
                printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","关闭密码保护(1)","设置密码(2)","返回(0)");
            }else{
                printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","开启密码保护(1)","设置密码(2)","返回(0)");
            }
            manage(getItemNum(0,2,"请输入菜单项"));
            break;
        case 0:
            printf("是否保存报名表？ y/n ，返回请输入0\n");

            do  c = (char) getchar();
            while(c != 'y' & c != 'n' & c != '0');
            if(c == 'y'){
                saveData();
                exit(1);
            } else if (c == 'n')exit(1);
            else if (c == '0')  viewMenu();
            else printf("输入有误，请重试\n");

            break;
        default:
            viewMenu();
    }
}


void viewMenu(){

    system("cls");

    printf("\n");
    printf("\t\t\t%s\n"," —————————————————");
    printf("\t\t\t%s\n","|              欢迎来到           |");
    printf("\t\t\t%s\n","|                                 |");
    printf("\t\t\t%s\n","|            王者农药药药         |");
    printf("\t\t\t%s\n","|                                 |");
    printf("\t\t\t%s\n","|           运动会管理系统        |");
    printf("\t\t\t%s\n"," —————————————————");
    printf("\t\t\t%s\t%s\t%s\t%s\t%s\n","文件(1)","编辑(2)","控制(3)","管理(4)","退出(0)");

    menu(getItemNum(0,4,"请输入菜单项："));
}

