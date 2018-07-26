#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>

#define FILE_PATH "g:\\entryForm.txt"  // 文件路径

int fileTest(){
    char name[20];  // 姓名
    int age;  // 年龄
    int studNo;  // 学号
    float score;  // 平均分
    FILE *fp;  // 文件指针

    // 判断文件是否能够正确创建/打开
    if( (fp=fopen(FILE_PATH,"wt+")) == NULL ){
        perror(FILE_PATH);
        exit(1);
    }

    // 从控制台输入学生信息并写入文件
    printf("请输入姓名、年龄、学号和平均分(以空格分隔)：\n");
    while(scanf("%s %d %d %f", name, &age, &studNo, &score)!= EOF && age !=0){
        fprintf(fp,"%s\t%d\t%d\t%f\n", name, age, studNo, score);
    }
    // 刷新缓冲区，将缓冲区的内容写入文件
    fflush(fp);
    // 重置文件内部位置指针，让位置指针指向文件开头
    rewind(fp);
    // 从文件中读取学生信息
    printf("\n读取文件内容：\n");
    while(fscanf(fp, "%s\t%d\t%d\t%f", name, &age, &studNo, &score) != EOF){
        printf("%s  %d  %d  %f\n", name, age, studNo, score);
    }
    fclose(fp);
    return EXIT_SUCCESS;
}

void checkSample(char password[]){
    int n,p;
    char ch,pwd[20];

    while(strcmp(pwd,password) != 0){
        system("cls");//清屏
        p=0;
//    puts("请输入账号：");
//    scanf("%s%*c",acnt);
        puts("请输入密码：");
        while((ch=getch())!='\r')//判断是否是回车
        {
            if(ch==8)//实现backspace键的功能，其中backspace键的ascii码是8
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                if(p>0)//最多只能删到没有字符
                    p--;
            }
            if(!isdigit(ch)&&!isalpha(ch))//判断是否是数字或字符
                continue;
            putchar('*');//在屏幕上打印星号
            pwd[p++]=ch;//保存密码
        }
        pwd[p]=0;//结束字符串

    }
}