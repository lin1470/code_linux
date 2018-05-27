#include <iostream>
using namespace std;
#define MOD 10000
int main() {
    long long n;
    while(cin >>n){
        long long sum =((1+n)*n%MOD)/2;
        long long result = ((sum%MOD)*(sum%MOD))%MOD;
        printf("%04lld\n",result);
    }
    return 0;
}