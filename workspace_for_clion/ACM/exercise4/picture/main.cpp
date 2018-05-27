#include <iostream>
using namespace std;
int main() {
    int n,m;
    while(cin>>n>>m){
        for(int i =m+2;i>0;i--){
            if(i == m+2 || i == 1){
                cout << "+";
                for(int j =0;j<n;j++)
                    cout << "-";
                cout << "+\n";
            }
            else{
                cout << "|";
                for(int j =0;j<n;j++)
                    cout << " ";
                cout << "|\n";
            }
        }
        cout << "\n";
    }
    return 0;
}