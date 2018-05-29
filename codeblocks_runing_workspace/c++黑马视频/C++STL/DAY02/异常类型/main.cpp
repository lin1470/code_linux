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
    throw myException("自定义异常");
}
void test()
{
    try
    {
        func01();
    }
    catch(int e)
    {
        cout << "捕获到的异常为:"<< e << endl;
    }
    try{
        func02();
    }
    catch(char const*e){
        cout << "捕获到的异常为:" << e << endl;
    }
    //func02();
    try{
        func03();
    }
    //普通元素和引用和指针接收异常对象的区别,需要注意.
    // 异常类型的声明周期,如果是普通的元素接收的话就是catch子块完成了就释放.
    // 如果是引用的话,就没有一个拷贝构造的过程
    // 如果是指针的话,需要手动控制释放的过程.
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
