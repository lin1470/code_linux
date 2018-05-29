#include <iostream>
#include<cstring>
using namespace std;
class person
{
public:
    person()
    {
        age =0;
    }
    void setAge(int age)
    {
        if(age<0 ||age > 100){
            throw out_of_range("ÄêÁä³¬³öÁË·¶Î§!");
        }
        this->age = age;
    }
private:
    int age;
};

class MyOutOfRange:public exception
{
public:
    MyOutOfRange()=default;
    MyOutOfRange(char * str){
        error = new char[strlen(str)+1];
        strcpy(error,str);
    }
    virtual const char* what() const{
        return error;
    }
    ~MyOutOfRange(){
        cout << "destroy my exception!" << endl;
        if(error != 0){
            delete error;
        }
    }
public:
    char * error;

};
void func01()
{
    throw MyOutOfRange("gg");
}
void test()
{
    try {
        func01();
    }catch(exception &e){
        cout << e.what() << endl;
    }
}
void test01(){
    person a;
    try{
        a.setAge(1000);
    }
    catch(exception &e){
        cout << e.what() << endl;
    }
    cout << "Hello world!" << endl;
}
int main()
{
    test();
    return 0;
}
