#include <iostream>
#include "Dog.h"
#include "Animal.h"
#include "Cat.h"
using namespace std;

int main()
{
    Animal* dog = new Dog;
    dog->cry();
    delete dog;
    Animal * cat = new Cat;
    cat ->cry();
    delete cat;
    cout << "Hello world!" << endl;
    return 0;
}
