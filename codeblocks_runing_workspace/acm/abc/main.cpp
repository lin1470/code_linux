#include <iostream>

using namespace std;

int main()
{
    long a[3][10];
    int n=0;
    cin>>n;
    for(int i=0;i!=n;i++){
        cin>>a[0][i]>>a[1][i]>>a[2][i];
    }
    for(int i=0;i!=n;i++){
        if(a[0][i]+a[1][i]>a[2][i])
            cout<< "Case #"<<i+1<< ": true" << endl;
        else cout << "Case #"<< i+1 << ": false" << endl;
    }
    return 0;
}
