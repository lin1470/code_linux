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
        cout << "����Բ�ཻ��!" << endl;
    else cout << "����Բ���ཻ!" << endl;
    cout<<"----------------";
    point p1,p2;
    p1.initialize_point();
    p2.initialize_point();
    cout << "����֮��ľ���Ϊ:"<< p1.calculate_distance(p2)<< endl;
    return 0;
}
