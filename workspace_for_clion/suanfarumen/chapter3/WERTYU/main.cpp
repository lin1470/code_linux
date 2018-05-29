#include <iostream>
#include <cstring>

using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main() {
    int c;
    while(scanf("%c",&c)!=EOF){
        char *strtem;
        int ok =1;
        if((strtem=strchr(s,c))==NULL) ok =0;
        if(ok)
            cout << *(--strtem);
        else cout << char(c);
    }
    return 0;
}