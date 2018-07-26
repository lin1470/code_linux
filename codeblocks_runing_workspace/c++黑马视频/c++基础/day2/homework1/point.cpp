#include<iostream>
#include"point.h"
#include<cmath>
using namespace std;
void point::set_x(double x)
{
    px = x;
}
void point::set_y(double y)
{
    py =y;
}

double point::get_x()
{
    return px;
}
double point::get_y()
{
    return py;
}
double point::calculate_distance(point &p)
{
    return sqrt((px-p.px)*(px-p.px)+(py-p.py)*(py-p.py));
}
void point::initialize_point()
{
    cout << "please input x,y for a point instance!" << endl;
    cin >> px >> py;
}
