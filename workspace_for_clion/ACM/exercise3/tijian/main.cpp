#include <iostream>
using namespace std;
int main() {
    int n,k,m,t;
    cin >> t;
    while(t--){
        cin >> n >> k >> m;
        if(m>n)
            cout << k << endl;
        else{
            int sub = n*k;
            if(sub%m == 0)
                cout << sub/m<< endl;
            else
                cout << sub/m+1<< endl;
        }
    }
    return 0;
}