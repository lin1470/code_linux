#include<iostream>
using namespace std;
int fact()
{
static int cnt = 0;
return cnt++;
}
int &get(int *arry,int index){return arry[index];}//好一个左值的调用啊，服气。
