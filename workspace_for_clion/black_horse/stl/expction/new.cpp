#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyVector.hpp"
//标准库异常class Person{
public:
Person(int age,string name){
    if (age < 0 || age > 100){
        throw out_of_range("年龄应该在 0-100 之间的数字!");
    }
    mName = name;
    mAge = age;
}
public:
string mName;
int mAge;
};
void test01(){
    try{
        Person p(101, "aaa");
    }
    catch (out_of_range& e){
        cout << e.what() << endl;
    }
}
//自定义异常类
class MyOutRangeException : public exception{
public:
    MyOutRangeException(const char* error){
        int len = strlen(error) + 1;
        this->pError = new char[len];
        strcpy(this->pError,error);
    }
    virtual const char*
    what() const{
        return this->pError;
    }
    virtual ~MyOutRangeException(){
        cout << "析构函数!" << endl;
        if (pError != NULL){
            delete[] this->pError;
        }
    }
public:
    char* pError;
};class Person02{
public:
    Person02(int age, string name){
        if (age < 0 || age > 100){
            throw MyOutRangeException("年龄应该在 0-100 之间的数字!");
        }
        mName = name;
        mAge = age;
    }
public:
    string mName;
    int mAge;
};
void test02(){
    try{
        Person02 p(101,"aaa");
    }
    catch (exception& e){
        cout << e.what() << endl;
    }
}
int main(){
    test01();
    test02();
    system("pause");
    return 0;
}