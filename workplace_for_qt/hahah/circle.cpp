#include "circle.h"

Circle::Circle()
{
    //ctorra

    radius=1;
}

Circle::Circle(double newRadius)
{
    radius=newRadius;
}
double Circle::getArea()
{
    return radius*radius*3.14159;
}
double Circle::getRadius()
{
    return radius;
}
void Circle::setRadius(double newRadius)
{
    radius=newRadius;
}


