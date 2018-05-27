#include <iostream>
using namespace std;
int main() {
    int c,q=1;
    while((scanf("%c",&c))!= EOF)
    {
        if(c == '"')
        {
            printf("hello");
        }
        else cout << c;
    }

    return 0;
}