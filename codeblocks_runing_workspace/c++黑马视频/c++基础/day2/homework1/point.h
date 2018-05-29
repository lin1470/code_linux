#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
class point
{
public:
    void set_x(double);
    void set_y(double);
    void set_r(double);
    double get_x();
    double get_y();
    double get_r();
    void initialize_point();
    double calculate_distance(point &p);
private:
    double px,py;
};


#endif // POINT_H_INCLUDED
