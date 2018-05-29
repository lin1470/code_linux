#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>  //标准地输入和输出的类库
#include <math.h>
using namespace std;
//const int N=10;  //表示了这个是二维的数组最多就只能是放10*10的二维数组，可以用动态数组来解决这个问题
//这个固定数组的问题。
//int chessboard[N][N];    //0洞 1可以放 2放了
//int result[N*N];   //暂时不知道是什么鬼，一百个数组一开始就赋值为零。
int len;  //结果数的长度
int n;
bool check(int x,int y){//智障啊，居然声明为一个内联的函数，极度智障。
    int i;
    for(i=y-1;i>=0;i--) {   //左横
          if(chessboard[x][i]==2)      //遇到车
           return false;
        if(chessboard[x][i]==0)       //遇到洞 不会攻击到别人
          break;
    }

    for(i=y+1;i<n;i++) {   //右横
           if(chessboard[x][i]==2)      //遇到车
           return false;
        if(chessboard[x][i]==0)       //遇到洞 不会攻击到别人
          break;
    }


    for(i=x-1;i>=0;i--)  {        //左竖
       if(chessboard[i][y]==2)
       return false;

       if(chessboard[i][y]==0)
       break;
    }

       for(i=x+1;i<n;i++)  {        //右竖
       if(chessboard[i][y]==2)
       return false;

       if(chessboard[i][y]==0)
          break;
    }

       return true;
}
void dfs(int now,int sum){
    if(now>=n*n){
        result[sum]++;
        return;
    }//递归的终止的条件来的。
    int x=now/n;
    int y=now%n;

    if(chessboard[x][y]==1){
        if(check(x,y)){
            chessboard[x][y]=2;
            dfs(now+1,sum+1);
            chessboard[x][y]=1;
        }
    }
    dfs(now+1,sum);
}//这个函数看得不是很懂啊，check可以看做是检查这个地方是否能放棋子的地方来的。
int main(){
    int i,j;
    while(cin>>n){
        //下面进行动态的分配来做。
        int** chessboard;
       int* result=new int [n*n];
       chessboard=new int*[n];
       for(int in=0;in<n;in++)
       {
           chessboard[in]=new int[n];
       }

       //以上是动态分配的方法。

        for(i=0;i<n;i++)
          for(j=0;j<n;j++){
            cin>>chessboard[i][j];
          }//为每个二维数组的元素赋值。

          memset(result,0,sizeof(result));//一开始就为一维数组赋值re[n*n]赋值。

            dfs(0,0);//关键就是这个函数的应用咯。

//绕过一个来说的话，这个 也是可以的哈哈。
        for(i=1;i<n*n;i++){
            if(result[i]!=0){
                cout<<result[i]<<endl;
            }
            else
                break;
        }
        for(int in=0;in<n;in++)
            delete []chessboard[in];
        delete []chessboard;

        delete result;
    }
    return 0;
}
