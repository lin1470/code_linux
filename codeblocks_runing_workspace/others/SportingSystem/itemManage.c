
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "data.h"

//0��1��
void check(){
    char tempPassword[20];

    printf("\n\n\n");
    printf("\t\t\t���������Ա���룺");

    char c;

    while(strcmp(tempPassword,password) != 0){
        int p = 0;
        while((c = (char)getch()) !=  '\r'){
            if(c==8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                if(p>0)//���ֻ��ɾ��û���ַ�
                    p--;
            }
            if(!isdigit(c)&&!isalpha(c))//�ж��Ƿ������ֻ��ַ�
                continue;
            putchar('*');
            tempPassword[p++] = c;
        }
        tempPassword[p] = '\0';

        if(strcmp(tempPassword,password) != 0){
            system("cls");
            printf("\t\t\t������֤ʧ�ܣ������ԣ�");
        }
    }

}
int getState() {

    FILE *file;

    // �ж��ļ��Ƿ��ܹ���ȷ����/��
    if( (file=fopen(PASSPATH,"r")) == NULL ){
        perror(PASSPATH);
        exit(1);
    }
    fscanf(file,"%d%s",&state,password);
    fclose(file);
    return state;
}

void saveState(){
    FILE *file;

    // �ж��ļ��Ƿ��ܹ���ȷ����/��
    if( (file=fopen(PASSPATH,"w")) == NULL ){
        perror(PASSPATH);
        exit(1);
    }
    fprintf(file,"%d %s",state,password);
    fclose(file);
}

void changeState(){
    if(state == 0){
        state = 1;
        printf("�ɹ��ر�����������������Լ���...\n");
    } else{
        state = 0;
        printf("�ɹ���������������������Լ���...\n");
    }
    saveState();
}

void setPassword(){

    check();
    printf("�����������룺\n");
    scanf("%s",password);

    saveState();
    printf("���óɹ��������������...\n");
    system("pause");
}