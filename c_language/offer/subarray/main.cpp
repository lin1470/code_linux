#include <iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int spaceCount = 0;
        length = strlen(str);
        char *str0 = str;
        while(*str0 != '\0'){
            if(*str0 == ' ')
                spaceCount++;
            str0++;
        }
        while(length != -1){
            if(str[length]!=' '){
                str[length+spaceCount*2]=str[length];
                length--;
            }
            else{
                int i = length+(spaceCount)*2;
                str[i] = '0';
                str[i-1] = '2';
                str[i-2] = '%';
                length--;
                spaceCount--;
            }

        }

    }
};
int main() {
    char str[100]="hello worl d!  ";
    Solution s;
    s.replaceSpace(str,12);
    cout << str;
    return 0;
}