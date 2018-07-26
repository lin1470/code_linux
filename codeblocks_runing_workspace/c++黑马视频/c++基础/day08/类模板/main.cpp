#include <iostream>
#include<string>
using namespace std;
template<class T>
class Person
{
public:
    Person(T age,T id)
    {
        this->age = age;
        this->id = id;
    }
    void show()
    {
        cout << "this person'age is :" << this->age << "the name is "<< this->id << endl;
    }
private:
    int age,id;
};
int main()
{
    Person<int> AA(20,30);
    AA.show();
    cout << "Hello world!" << endl;
    return 0;
}
