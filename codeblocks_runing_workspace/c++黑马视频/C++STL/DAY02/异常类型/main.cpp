#include <iostream>
#include <cstring>
using namespace std;

class myException
{
public:
    myException()=default;
    myException(char *str)
    {
        error = new char[strlen(str+1)];
        strcpy(error,str);
    }
    void what()
    {
        cout << error << endl;
    }
    ~myException()
    {
        cout << "destroy exception class" << endl;
        if(error !=0){
            delete error;
        }
    }
private:
    char *error;
};
void func01()
{
    throw 1;
}
void func02()
{
    throw "exception!";
}

void func03()
{
    throw myException("�Զ����쳣");
}
void test()
{
    try
    {
        func01();
    }
    catch(int e)
    {
        cout << "���񵽵��쳣Ϊ:"<< e << endl;
    }
    try{
        func02();
    }
    catch(char const*e){
        cout << "���񵽵��쳣Ϊ:" << e << endl;
    }
    //func02();
    try{
        func03();
    }
    //��ͨԪ�غ����ú�ָ������쳣���������,��Ҫע��.
    // �쳣���͵���������,�������ͨ��Ԫ�ؽ��յĻ�����catch�ӿ�����˾��ͷ�.
    // ��������õĻ�,��û��һ����������Ĺ���
    // �����ָ��Ļ�,��Ҫ�ֶ������ͷŵĹ���.
    catch(myException &e){
         e.what();
    }
}
int main()
{
    test();
    cout << "Hello world!" << endl;
    return 0;
}
