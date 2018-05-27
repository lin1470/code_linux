#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{
    int a[]={0,1,2,3,4,5};
    vector<int> ivec(begin(a),end(a));
    cout<<"hello!"<<endl;
    for(auto &i:ivec)
        i-=1;
    for(auto i:ivec)
        cout<<i<<"我真的草尼玛逼啊"<<endl;
    return 0;
}
