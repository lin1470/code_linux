#include <iostream>
#include<string>

using namespace std;
template<typename T>
T maxValue (T value1,T value2)
{
    return (value1>value2? value1:value2);
}//好一个模板来的啊，真是厉害了哈哈

int main()
{

    cout<<"Maximun between 1 and 3 is"<<maxValue(1,3)<<endl;
    cout<<"shdfhd"<<maxValue(1.5,3.0)<<endl;
    cout<<"Maximun between 'a'and 'b'is"<<maxValue('A','B')<<endl;
    cout<<"Maximun between \"sdfsdf\" and \"aaa\""<<maxValue("SDFD","AAA");
    return 0;
}

