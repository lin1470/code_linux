#include <iostream>

using namespace std;
class Animal{};
class Cat:public Animal{};
class building{};
void test01()
{
    //static_cast转换
    int a = 97;
    char c = static_cast<char>(a);
    cout << c << endl;
    //基础数据类型指针
//    int *p =NULL;
//    char *sp = static_cast<char*>(p);

    //只能用于对内置的数据类型,
    //具有继承关系的指针或者是引用
}

void test02
{
    //基础数据类型
//    int a = 10;
//    char c = dynamic_cast<char>(a);

    //非继承关系的指针
    // Animal *ani =NULL;
    // Binding *b = dynamic_cast<Animal*>(ani);

    //具有继承关系的
//    Animal *ani =NULL;
//    Cat *cat = dynamic_cast<Animal*>(ani);
    // 父类指针转换成子类指针,是不能转换的.

}
int main()
{
    test01();
    cout << "Hello world!" << endl;
    return 0;
}
