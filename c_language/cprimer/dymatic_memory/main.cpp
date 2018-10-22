#include <iostream>
#include <memory>
#include <vector>

using namespace std;

vector<int>* getVec()
{
    return new vector<int>;
}

void printVec(vector<int> *p_vec)
{
    for(int i =0;i!=p_vec->size();i++)
    {
        cout << p_vec->at(i) << endl;
    }
}
void readVec()
{
    vector<int> *p_vec = getVec();
    int n;
    while(cin >> n)
    {
        p_vec->push_back(n);
    }
    printVec(p_vec);
    delete p_vec;
    p_vec = NULL;
}

shared_ptr<vector<int>> getDvec()
{
    return make_shared<vector<int>>();
}

void read_data(shared_ptr<vector<int>> sp)
{
    int number;
    while(cin >> number)
    {
        sp->push_back(number);
    }
}

void print_data(shared_ptr<vector<int>> sp)
{
    for(int i =0;i!=sp->size();i++)
    {
        cout << sp->at(i) << endl;
    }
}
void test1()
{
    readVec();
}

void test2()
{
    shared_ptr<vector<int>> sp = getDvec();
    read_data(sp);
    print_data(sp);
}
int main() {
//    test1();
    test2();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}