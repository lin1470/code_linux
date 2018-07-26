#include <iostream>
#include<time.h>
using namespace std;
long long power(int a , int n)
{

    if(n ==1)
        return a;
    if(n%2 == 0){
         long long temp = power(a,n/2);
        return temp*temp;
    }
        else{
            long long temp = power(a,(n-1)/2);
            return temp*temp*a;
        }

}
int main()
{
    clock_t start1,end1,start2,end2;
    start1 = clock();
    cout << "power(2,5)连乘的结果是:" << power(10,6)<< endl;
    end1 = clock();
    cout << "运行时间是:" << start1 << end1<< endl;
    return 0;
}
