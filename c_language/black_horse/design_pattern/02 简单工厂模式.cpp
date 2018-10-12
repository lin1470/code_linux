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

//ˮ������
class FruitFactory{
public:
		static AbstractFruit* CreateFruit(string flag){
		if (flag == "apple"){

			return new Apple;
		}
		else if (flag == "banana"){
			return new Banana;
		}
		else if (flag == "pear"){
			return new Pear;
		}
		else{
			return NULL;
		}
	}
};

void test01(){
	

	//����������Ҫ������ ֱ��������

	//FruitFactory* factory = new FruitFactory;
	AbstractFruit* fruit = FruitFactory::CreateFruit("apple");
	fruit->ShowName();
	delete fruit;

	fruit = FruitFactory::CreateFruit("banana");
	fruit->ShowName();
	delete fruit;

	fruit = FruitFactory::CreateFruit("pear");
	fruit->ShowName();
	delete fruit;

	delete factory;

}




int main(void){
	test01();
	return 0;
}