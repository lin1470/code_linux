#include<iostream>
#include<vector>
using namespace std;
int cal(int a,int b)
{
    return a+b;
}
int mines(int a,int b)
{
    return a-b;
}
int multiply(int a,int b)
{
    return a*b;
}
int divide(int a,int b)
{
    return a*1.0/b;
}
void compute(int a,int b,int (*p)(int,int))
{
    cout<<p(a,b)<<endl;
}
int main()
{
    decltype(cal) *p1=cal, *p2=mines,*p3=multiply,*p4=divide;
    vector<decltype(cal)*> vf={p1,p2,p3,p4};
    for(auto p:vf)
        compute(5,10,p);
    return 0;

}
