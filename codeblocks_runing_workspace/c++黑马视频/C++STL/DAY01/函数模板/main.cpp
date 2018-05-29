#include <iostream>
#include<string>
using namespace std;

template<class T>
class person
{
public:
    person(T pname)
    {
        this->pname = pname;
    }
    void show()
    {
        cout << "this person'name is:" << this->pname << endl;
    }
private:
    T pname;
};
int main()
{
    person<string> AA("hello");
    AA.show();
//    cout << "Hello world!" << endl;
    return 0;
}
