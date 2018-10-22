#include <list>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Person
{
public:

    Person()
    {

    }
    Person(int id ,string name)
    {
        this->id = id;
        this->name = name;
    }
    string name=" ";
    int id = 0;
};
void test1()
{
    vector<Person> pvec;
    pvec.emplace_back(2,"hello");
    pvec.emplace(pvec.begin());
    pvec.emplace(pvec.begin(),1,"hello");
    for(int i=0;i!=pvec.size();i++)
    {
        cout << pvec.at(i).id << pvec.at(i).name<< endl;
    }
}

void test2()
{
    list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter %2)
        {
            iter = vi.insert(iter,*iter);
            iter++;
            iter++;
        }
        else
        {
            iter = vi.erase(iter);
        }
    }

    for(auto it= vi.cbegin();it != vi.cend();it++)
    {
        cout << *it << endl;
    }
}
void test3()
{
    vector<int> ivec;
    cout << "ivec: size: " << ivec.size()
    << "ivec:capacity: " << ivec.capacity() << endl;
    for(int i = 0;i<= 24;i++)
    {
        ivec.push_back(i);
    }
    cout << "ivec: size: " << ivec.size()
         << "ivec:capacity: " << ivec.capacity() << endl;
}
int main()
{
//    test1();
//    test2();
    test3();
    list<char *> clist= {"123","1234"};
    vector<string> svec(clist.cbegin(),clist.cend());
    for(int i =0;i<svec.size();i++)
    {
        cout << svec.at(i)<<endl;
    }
    return 0;
}