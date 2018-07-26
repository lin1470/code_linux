
#include<iostream>
#include"Circle.h"
using namespace std;
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
    Circle circle1(1.2);
    Circle circle2(25);
    Circle circle3(125);
    cout<<"the"<<circle1.getArea()<<endl;
    cout<<"thdjh"<<circle2.getArea()<<endl;
    cout<<"hdsfhk"<<circle3.getArea()<<endl;
    circle1.setRadius(100);
    cout<<"shdfj"<<circle1.getArea()<<endl;
    return 0;

}
