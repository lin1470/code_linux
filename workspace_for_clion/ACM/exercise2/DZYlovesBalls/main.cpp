#include <iostream>
using namespace std;
long long gcd(long long a,long long b){
    return b==0? a:gcd(b,a%b);
}
int main() {
    long long n,m;
    while(cin>> n >> m){
        long long g = gcd(n*m,n+m);
        cout << n*m/g << "/" << (m+n)/g << endl;
    }
    return 0;
}
