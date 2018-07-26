#include <iostream>

using namespace std;
class shape
{
public:
    virtual void show()=0;
    virtual double getArea()=0;
    ~shape()
    {

    }
};

class Circle:public shape
{
public:
    Circle(double r)
    {
        this->r = r;
    }
    virtual void show()
    {
        cout <<"Print the radix of circle"<< this->r << endl;
    }
    virtual double getArea()
    {
        cout << this->r *this->r * 3.14 << endl;
        return this->r *this->r*3.14;
    }
    ~Circle()
    {
        cout << "Ô²µÄÎö¹¹º¯Êý" << endl;
    }
private:
    double r;
};

class Square:public shape
{
public:
    Square(double r)
    {
        this->r = r;
    }
    virtual void show()
    {
        cout << "print the side of square:"<< this->r << endl;
    }
    virtual double getArea()
    {
        cout << this->r*this->r << endl;
        return this->r*this->r;
    }
    virtual ~Square()
    {
        cout << "destroy this square" << endl;
    }
private:
    double r;
};
int main()
{
    shape *a[2] = {0,0};
    for(int i =0;i<2;i++){
        if(i==0){
            double r;
            cout << "input a radix of a circle:" << endl;
            cin >> r;
            a[i]=new Circle(r);
        }
        else if(i == 1){
            double r= 1.0;
            cout << "input a side of a square:" << endl;
            cin >> r;
            a[i] = new Square(r);
        }
    }
//    a[0] = new Circle(2.0);
//    a[1] = new Square(2.0);
//    for(int i=0;i<2;i++){
//        a[i]->show();
//        cout << a[i]->getArea() << endl;
//        delete a[i];
//    }
//    shape *a1;
//    shape *a2;
//    cout << "input a radix of a circle:" << endl;
//    double r;
//    cin >> r;
//    a1 = new Circle(r);
//    cout << "input a side of a square:" << endl;
//    a1->show();
//    cout << a1->getArea() << endl;
//    delete a1;
//    double a;
//    cin >> a;
//    a2 = new Square(a);
//    a2->show();
//    cout << a2->getArea() << endl;
//    delete a2;
//
//    cout << "Hello world!" << endl;
    return 0;
}
