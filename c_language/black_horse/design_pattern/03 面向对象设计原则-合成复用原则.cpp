#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//����
class AbstractCar{
public:
	virtual void run() = 0;
};


//���ڳ�
class Dazhong :public AbstractCar{
public:
	virtual void run(){
		cout << "���ڳ�����..." << endl;
	}
};

//������
class Tuolaji :public AbstractCar{
public:
	virtual void run(){
		cout << "����������..." << endl;
	}
};


//��Ծ����� �����ü̳�
#if 0
class Person : public Tuolaji{
public:
	void Doufeng(){
		run();
	}
};

class PersonB : public Dazhong{
public:
	void Doufeng(){
		run();
	}
};
#endif

//����ʹ�����
class Person{
public:
	void setCar(AbstractCar* car){
		this->car = car;
	}
	void Doufeng(){
		this->car->run();
		if (this->car != NULL){
			delete this->car;
			this->car = NULL;
		}
	}
public:
	AbstractCar* car;
};

void test02(){
	
	Person* p = new Person;
	p->setCar(new Dazhong);
	p->Doufeng();

	p->setCar(new Tuolaji);
	p->Doufeng();

	delete p;
}


//�̳к���� ����ʹ�����
int main(void){

	test02();
	return 0;
}