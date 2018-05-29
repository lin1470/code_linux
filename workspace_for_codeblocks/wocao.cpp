#include<iostream>
#include<vector>
using namespace std;
int func (int,int);
int main()
{
    vector<decltype(func)*> vf;
}
