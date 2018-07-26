#include <iostream>

using namespace std;

class AA
{
public:
    AA()
    {
        m_i =0;
    }

    int get_i()
    {
        m_i++;
        return this->m_i;
    }
private:
    int m_i;
};
int main()
{
    AA a;
    cout << a.get_i() <<endl;
    cout << "Hello world!" << endl;
    return 0;
}
