
#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int n = 0;

extern int projectNum;
extern int getState();
extern int state;
void viewMenu();
extern char password[20];

//�����ơ�ѡ��
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
//�����롱ѡ��
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
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","�鿴�������(1)",
                   "���뱨����2)","����������(3)","�鿴������Ŀ(4)","����(5)","����(0)");
            file(getItemNum(0,5,"������˵��"));
            break;
        case 2:
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","����˶�Ա(1)",
                   "ɾ���˶�Ա(2)","�����˶�Ա��Ϣ(3)","�½���Ŀ(4)","��Ϣ����(5)","����(0)");
            int i = getItemNum(0,5,"������˵��");
            if(i==1 && projectNum == 0 ){
                printf("���Ƚ���������Ŀ��\n");
                system("pause");
                viewMenu();
                break;
            }
            edit(i);
            break;
        case 3:
            printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","���������(1)","��������(2)","����(0)");
            control(getItemNum(0,2,"������˵��"));
            break;
        case 4:
            if(state == 0){
                printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","�ر����뱣��(1)","��������(2)","����(0)");
            }else{
                printf("\t\t\t%s\n\t\t\t%s\n\t\t\t%s\n","�������뱣��(1)","��������(2)","����(0)");
            }
            manage(getItemNum(0,2,"������˵���"));
            break;
        case 0:
            printf("�Ƿ񱣴汨���� y/n ������������0\n");

            do  c = (char) getchar();
            while(c != 'y' & c != 'n' & c != '0');
            if(c == 'y'){
                saveData();
                exit(1);
            } else if (c == 'n')exit(1);
            else if (c == '0')  viewMenu();
            else printf("��������������\n");

            break;
        default:
            viewMenu();
    }
}


void viewMenu(){

    system("cls");

    printf("\n");
    printf("\t\t\t%s\n"," ����������������������������������");
    printf("\t\t\t%s\n","|              ��ӭ����           |");
    printf("\t\t\t%s\n","|                                 |");
    printf("\t\t\t%s\n","|            ����ũҩҩҩ         |");
    printf("\t\t\t%s\n","|                                 |");
    printf("\t\t\t%s\n","|           �˶������ϵͳ        |");
    printf("\t\t\t%s\n"," ����������������������������������");
    printf("\t\t\t%s\t%s\t%s\t%s\t%s\n","�ļ�(1)","�༭(2)","����(3)","����(4)","�˳�(0)");

    menu(getItemNum(0,4,"������˵��"));
}

