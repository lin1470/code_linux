#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <conio.h>
#include <ctype.h>
#include <mem.h>

#define FILE_PATH "g:\\entryForm.txt"  // �ļ�·��

int fileTest(){
    char name[20];  // ����
    int age;  // ����
    int studNo;  // ѧ��
    float score;  // ƽ����
    FILE *fp;  // �ļ�ָ��

    // �ж��ļ��Ƿ��ܹ���ȷ����/��
    if( (fp=fopen(FILE_PATH,"wt+")) == NULL ){
        perror(FILE_PATH);
        exit(1);
    }

    // �ӿ���̨����ѧ����Ϣ��д���ļ�
    printf("���������������䡢ѧ�ź�ƽ����(�Կո�ָ�)��\n");
    while(scanf("%s %d %d %f", name, &age, &studNo, &score)!= EOF && age !=0){
        fprintf(fp,"%s\t%d\t%d\t%f\n", name, age, studNo, score);
    }
    // ˢ�»���������������������д���ļ�
    fflush(fp);
    // �����ļ��ڲ�λ��ָ�룬��λ��ָ��ָ���ļ���ͷ
    rewind(fp);
    // ���ļ��ж�ȡѧ����Ϣ
    printf("\n��ȡ�ļ����ݣ�\n");
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
        system("cls");//����
        p=0;
//    puts("�������˺ţ�");
//    scanf("%s%*c",acnt);
        puts("���������룺");
        while((ch=getch())!='\r')//�ж��Ƿ��ǻس�
        {
            if(ch==8)//ʵ��backspace���Ĺ��ܣ�����backspace����ascii����8
            {
                putchar('\b');
                putchar(' ');
                putchar('\b');
                if(p>0)//���ֻ��ɾ��û���ַ�
                    p--;
            }
            if(!isdigit(ch)&&!isalpha(ch))//�ж��Ƿ������ֻ��ַ�
                continue;
            putchar('*');//����Ļ�ϴ�ӡ�Ǻ�
            pwd[p++]=ch;//��������
        }
        pwd[p]=0;//�����ַ���

    }
}