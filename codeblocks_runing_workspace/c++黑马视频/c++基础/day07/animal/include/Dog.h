#ifndef DOG_H
#define DOG_H

#include <Animal.h>


class Dog : public Animal
{
    public:
        Dog();
        virtual ~Dog();
        virtual void cry();

    protected:

    private:
};

#endif // DOG_H
