#include <iostream>

using namespace std;
class Animal{};
class Cat:public Animal{};
class building{};
void test01()
{
    //static_castת��
    int a = 97;
    char c = static_cast<char>(a);
    cout << c << endl;
    //������������ָ��
//    int *p =NULL;
//    char *sp = static_cast<char*>(p);

    //ֻ�����ڶ����õ���������,
    //���м̳й�ϵ��ָ�����������
}

void test02
{
    //������������
//    int a = 10;
//    char c = dynamic_cast<char>(a);

    //�Ǽ̳й�ϵ��ָ��
    // Animal *ani =NULL;
    // Binding *b = dynamic_cast<Animal*>(ani);

    //���м̳й�ϵ��
//    Animal *ani =NULL;
//    Cat *cat = dynamic_cast<Animal*>(ani);
    // ����ָ��ת��������ָ��,�ǲ���ת����.

}
int main()
{
    test01();
    cout << "Hello world!" << endl;
    return 0;
}
