#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//����ˮ��
class AbstractFruit{
public:
	virtual void ShowName() = 0;
};

//ƻ��
class Apple : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����ƻ��!" << endl;
	}
};

//�㽶
class Banana : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "�����㽶!" << endl;
	}
};

//Ѽ��
class Pear : public AbstractFruit{
public:
	virtual void ShowName(){
		cout << "����Ѽ��!" << endl;
	}
};


//���󹤳�
class AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit() = 0;
};

//ƻ������
class AppleFactory : public AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit(){
		return new Apple;
	}
};

//�㽶����
class BananaFactory : public AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit(){
		return new Banana;
	}
};

//Ѽ��
class PearFactory : public AbstractFruitFactory{
public:
	virtual AbstractFruit* CreateFruit(){
		return new Pear;
	}
};

void test01(){
	
	AbstractFruitFactory* factory = NULL;
	AbstractFruit* fruit = NULL;

	//����һ��ƻ������
	factory = new AppleFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//����һ���㽶����
	factory = new BananaFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	//����һ��Ѽ�湤��
	factory = new PearFactory;
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

}

int main(void){

	test01();
	return 0;
}