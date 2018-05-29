#include <iostream>

using namespace std;
long long pow(int a,int b)
{
    long long ans = 1,base = a;
    while(b){
        if((b&1) == 1)
            ans *= base;
        base *=base;
        b >>= 1;
    }
    return ans;
}
int main()
{
    cout << "pow(2,10)的结果是:" << pow(2,15) << endl;
    return 0;
}
