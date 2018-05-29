#include<stdio.h>
#include<stdlib.h>

#define MAXSTRLEN 255//the longest length of a string
typedef char SString[MAXSTRLEN+1];//define the static string

int next[MAXSTRLEN];//a array in the KMP algorithm

void get_next(SString T,int next[])//书本上递推的方法。p83页
{
    int i=1;
    next[1]=0;
    int j=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
        {
            i++;j++;next[i]=j;
        }
        else j=next[j];
    }
}//调用这个方法来初始化这个next这个数组。
int Index(SString S,SString T,int pos)
{
    int i=pos,j=1;
    get_next(T,next);
    while(i<=S[0]&&j<=T[0])
    {
        if(j==0||S[i]==T[j])
        {
            i++;j++;
        }
        else
            j=next[j];
    }
    if(j>T[0])return (i-T[0]);
    else
        return 0;
}//index in KMP algorithm

int lenth(SString str)
{
    int i=1;
    while(str[i]) i++;
    return (i-1);
}//从下标1的字符开始计算

void find (char name[],SString keys)
{
    SString line;
    FILE *fp;
    int l=0;//l是存放行号的。
    int j=0;//j是控制寻找的单词的位置的。
    fp=fopen("hhh.txt","r");
    if(!fp)
    {
        printf("打开文件错误!");
        exit(1);
    }
    keys[0]=lenth(keys);        //求关键字的长度
    printf("这里是关键字%s\n",&keys[1]);    //打印关键字
    while(!feof(fp))
    {
        printf("为什么这里无法显示呢这里是第%d行",l);
        fgets(&line[1],MAXSTRLEN,fp);//从文件中读取一行的内容放进这个字符串里面
        //printf("%s\n",line);
        line[0]=lenth(line);
        printf("%s\n",line);
        //j=Index(line,keys,j+1);
        l++;
    }
    fclose(fp);

}

int main()
{
    SString hh;
    printf("please input hello:\n");
    scanf("%s",&hh[1]);
   // hh[0]=lenth(hh);
   // printf("%s\n",hh);
   // printf("woni \n");
    find("hhh.txt",hh);
    return 0;

}
