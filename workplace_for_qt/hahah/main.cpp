
#include<iostream>
#include"circle.h"

#include<iostream>
using namespace std;
#include<string>
/*class Circle
{
public:
    double radius;
    Circle()
    {
        radius=1;
    }
    Circle(double newRadius)
    {
        radius=newRadius;
    }
    double getArea()
    {
        return radius*radius*3.14159;
    }
};*/
int main()
{
    //显示的速度好像是有点满的啊，不过没有关系的哈。
    Circle circle1(1.2);
    Circle circle4(500);//因为这个是没有运用到它的值所以是没有显示出来的嘛，哈哈
    //好像我是越来越喜欢这样的编程的方式了呢，这样我就不用在codeblock里面进行编写c++的代码的了
    //真的是往事打击的哈哈哈哈哈哈哈哈

    Circle circle2(25);
    Circle circle3(125);
    cout<<"the"<<circle1.getArea()<<endl;
    cout<<"thdjh"<<circle2.getArea()<<endl;
    cout<<"hdsfhk"<<circle3.getArea()<<endl;
    circle1.setRadius(150);
    cout<<"shdfj"<<circle1.getArea()<<endl;
    return 0;

}
