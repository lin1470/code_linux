//
// Created by bruce on 18-5-30.
//
#include<iostream>
#include <cstring>
using namespace std;
//异常基础类
class BassMyException
{
public:
    virtual void what()=0;
    virtual ~BassMyException(){};
};
class TargetSpaceNullException:public BassMyException
{
public:
    virtual void what()
    {
        cout << "target NUll error\n";
    }
    ~TargetSpaceNullException(){};

};

class SourceSpaceNullException:public BassMyException
{
public:
    virtual void what()
    {
        cout << "source NUll eoor\n";
    }
    ~SourceSpaceNullException(){};
};

using namespace std;
void copy_str(char* target,char* source)
{
    if(target ==NULL)
    {
        throw TargetSpaceNullException();
    }
    if(source == NULL)
    {
        throw SourceSpaceNullException();
    }
//    int len = strlen(source)+1;
    while(*source !='\0'){
        *target = *source;
        target++;
        source++;
    }

}

int main()
{
    char *source = "hello world\n";
    char buf[1024] = {0};
    try{
        copy_str(buf,NULL);
    }
    catch(BassMyException& ex)
    {
        ex.what();
    }
    cout << buf<< endl;
    return 0;
}
