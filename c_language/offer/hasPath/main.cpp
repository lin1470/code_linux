#include <iostream>
#include <string.h>

using namespace std;

bool hasPathCore(char*,int,int,int,int,char*,int,bool *);
bool hasPath( char* matrix, int rows, int cols,  char* str)
{
    if(matrix == NULL || rows<0 || cols <0|| str ==NULL)
        return false;
    bool *visited = new bool[rows*cols];
    memset(visited,0,rows*cols);
    int pathIndex =0;
    for(int i = 0;i<rows;i++)
        for(int j = 0;j<cols;j++)
        {
            if(hasPathCore(matrix,rows,cols,i,j,str,pathIndex,visited))
                return true;
        }

    delete(visited);
        return false;
}

bool hasPathCore(char *matrix,int rows,int cols,int row,int col,char *str,int pathIndex,bool *visited)
{
    bool haspath = false;
    if(str[pathIndex]=='\0') // 全部路径已经是找到了,那么就是字符串的空格.
        return true;
    if(matrix[row*cols+col]==str[pathIndex]
    && row>=0 && row<rows && col >=0 && col < cols
    && !visited[row*cols+col])
    {
        pathIndex++;
        visited[row*cols+col] = true;
        haspath = hasPathCore(matrix,rows,cols,row,col-1,str,pathIndex,visited)||
                hasPathCore(matrix,rows,cols,row+1,col,str,pathIndex,visited)||
                hasPathCore(matrix,rows,cols,row,col+1,str,pathIndex,visited)||
                hasPathCore(matrix,rows,cols,row-1,col,str,pathIndex,visited);
        if(!haspath)
        {
            --pathIndex;
            visited[row*cols+col] = false;
        }
    }
    return haspath;
}

int main()
{
     char *matrix = "abtgcfcsjdeh";
     char *str = "bfce";
     char *str1 = "abfb";
    printf("the return is %d",hasPath(matrix,3,4,str));
    printf("the return 2 is %d",hasPath(matrix,3,4,str1));
    return 0;
}