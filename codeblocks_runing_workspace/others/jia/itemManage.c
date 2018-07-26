
#include <stdio.h>
#include <mem.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "data.h"

//0开1关
void check(){
    char tempPassword[20];

    printf("\n\n\n");
    printf("\t\t\t请输入管理员密码：");

    char c;

    while(strcmp(tempPassword,password) != 0){
        int p = 0;
        while((c = (char)getch()) !=  '\r'){
            if(c==8)//实现backspace键的功能，其中backspace键的ascii码是8
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                if(p>0)//最多只能删到没有字符
                    p--;
            }
            if(!isdigit(c)&&!isalpha(c))//判断是否是数字或字符
                continue;
            putchar('*');
            tempPassword[p++] = c;
        }
        tempPassword[p] = '\0';

        if(strcmp(tempPassword,password) != 0){
            system("cls");
            printf("\t\t\t密码验证失败，请重试：");
        }
    }

}
int getState() {

    FILE *file;

    // 判断文件是否能够正确创建/打开
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

    // 判断文件是否能够正确创建/打开
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
        printf("成功关闭密码锁，按任意键以继续...\n");
    } else{
        state = 0;
        printf("成功开启密码锁，按任意键以继续...\n");
    }
    saveState();
}

void setPassword(){

    check();
    printf("请设置新密码：\n");
    scanf("%s",password);

    saveState();
    printf("设置成功！按任意键继续...\n");
    system("pause");
}