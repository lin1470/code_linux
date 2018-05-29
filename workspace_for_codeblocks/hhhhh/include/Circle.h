#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle();
        Circle(double);
        double getArea();
        void setRadius(double);
        double getRadius();
        virtual ~Circle();

    protected:

    private:
        double radius;
};

#endif // CIRCLE_H
