#include <iostream>
#include"circle.h"
#include"point.h"
using namespace std;

int main()
{
    circle c1,c2;
    c1.initialize_circle();
    c2.initialize_circle();
    if(c1.is_intersect(c2))
        cout << "两个圆相交了!" << endl;
    else cout << "两个圆不相交!" << endl;
    cout<<"----------------";
    point p1,p2;
    p1.initialize_point();
    p2.initialize_point();
    cout << "两点之间的距离为:"<< p1.calculate_distance(p2)<< endl;
    return 0;
}
