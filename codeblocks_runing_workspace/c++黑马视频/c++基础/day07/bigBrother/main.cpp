#include <iostream>

using namespace std;

class BigBrother{
public:
    //�����
    virtual void fightPeople() = 0;
};

class EastNeverLose: public BigBrother
{
public:
    virtual void fightPeople()
    {
        cout << "ʹ���˿����������!"<< endl;
    }
private:
    int name =1;

};

class Wuyazi:public BigBrother
{
public:
    virtual void fightPeople()
    {
        cout << "ʹ���˱�ڤ�񹦴���" << endl;
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
