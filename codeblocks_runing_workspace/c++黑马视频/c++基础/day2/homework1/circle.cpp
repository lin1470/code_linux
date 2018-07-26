#include"circle.h"
#include<iostream>
#include<cmath>
using namespace std;
void circle::set_x(double x){
    cx = x;
}
void circle::set_y(double y){
        cy = y;
}
void circle::set_r(double r)
{
    cr = r;
}
double circle::get_x()
{
    return cx;
}
double circle::get_y()
{
    return cy;
}
double circle::get_r()
{
    return cr;
}
void circle::initialize_circle()
{
    cout<< "please input the x,y,r for a circle!" << endl;
    cin >> cx >> cy >> cr;
}
bool circle::is_intersect(circle &c)
{
    if(sqrt((cx-c.cx)*(cx-c.cx)+(cy-c.cy)*(cy-c.cy))<(cr+c.cr))
        return true;
    else return false;
}
