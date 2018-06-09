#include <iostream>
using namespace std;
//算法，负责统计某个元素的个数
int mycount(int *start,int *end,int val)
{
    int num=0;
    while(start!=end)
    {
        if(*start==val)
        num++;
        start++;
    }
    return num;
}
//int main() {
//
//    int arr[] = {0,7,5,4,9,2,0};
//    int *pbegin = arr;//迭代器开始位置
//    int *pend = &(arr[sizeof(arr)/sizeof(int)]);
//
//    int num = mycount(pbegin,pend,0);
//    cout << "the count is"<<num<<endl;
//    return 0;
//}