#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED
class circle{
public:
    void set_x(double x);
    void set_y(double y);
    void set_r(double r);
    double get_x();
    double get_y();
    double get_r();
    void initialize_circle();
    bool is_intersect(circle &c);
private:
    double cr;
    double cx,cy;

};


#endif // CIRCLE_H_INCLUDED
