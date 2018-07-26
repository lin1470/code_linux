#include <iostream>

using namespace std;

class BigBrother{
public:
    //会打人
    virtual void fightPeople() = 0;
};

class EastNeverLose: public BigBrother
{
public:
    virtual void fightPeople()
    {
        cout << "使用了葵花宝典打人!"<< endl;
    }
private:
    int name =1;

};

class Wuyazi:public BigBrother
{
public:
    virtual void fightPeople()
    {
        cout << "使用了北冥神功打人" << endl;
    }
private:
    int a =2;
};


int main()
{
    BigBrother *bigBrother =  new Wuyazi;
    bigBrother->fightPeople();
    delete bigBrother;
    return 0;
}
