#include <iostream>
#include<string>

using namespace std;

bool replaceString (string& s, const string& oldSubStr,const string& newSubStr);

int main()
{
    cout << "Enter string s, oldSubStr, and newSubStr:" << endl;
    string s,oldSubStr,newSubStr;
    cin>>s>>oldSubStr>>newSubStr;
    bool isReplaced =replaceString(s,oldSubStr,newSubStr);
    if(isReplaced)
        cout<<"The replaced string s is:"<<s<<endl;
    else
        cout<<"no matches"<<endl;
    return 0;
}

