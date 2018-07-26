#include <iostream>
using namespace std;
#define MAXN 1000
int main() {
    long long n;
    int a[MAXN];
    int num;
    while(cin>>n)
    {
        num = 0;
        if(n==0)
            cout<<"0\n";
        else if(n>0)
        {
            while(n!=0)
            {
                if(n&1)
                    a[num]=1;
                else a[num]=0;
                n >>= 1;
                num++;
             }
            for(int i=num-1;i>=0;i--)
                cout << a[i];
            cout << endl;
            }
    }
    return 0;
}