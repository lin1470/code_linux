#ifndef CAT_H
#define CAT_H

#include <Animal.h>


class Cat : public Animal
{
    public:
        Cat();
        virtual ~Cat();
        virtual void cry();

    protected:

    private:
};

#endif // CAT_H
