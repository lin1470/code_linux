#	include<iostream>
using namespace std;


class DrinkTemplate{
public:
	//��ˮ
	virtual void BoildWater() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//�Ӹ�����
	virtual void AddSomething() = 0;

	//ģ�巽��
	void Make(){
		BoildWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};

//���ݿ���
class Coffee : public DrinkTemplate{
public:
	virtual void BoildWater(){
		cout << "��ɽȪˮ..." << endl;
	}
	//����
	virtual void Brew(){
		cout << "���ݿ���..." << endl;
	}
	//���뱭��
	virtual void PourInCup(){
		cout << "���ȵ��뱭��..." << endl;
	}
	//�Ӹ�����
	virtual void AddSomething(){
		cout << "���ǣ���ţ��,�ӵ��..." << endl;
	}
};

//���ݲ�ˮ
class Tea : public DrinkTemplate{
public:
	virtual void BoildWater(){
		cout << "������ˮ..." << endl;
	}
	//����
	virtual void Brew(){
		cout << "����������..." << endl;
	}
	//���뱭��
	virtual void PourInCup(){
		cout << "��ˮ���뱭��..." << endl;
	}
	//�Ӹ�����
	virtual void AddSomething(){
		cout << "����..������...������..." << endl;
	}
};

void test01(){

	Tea* tea = new Tea;
	tea->Make();

	cout << "-----------" << endl;

	Coffee* coffee = new Coffee;
	coffee->Make();
	
}


int main(){

	test01();

	system("pause");
	return 0;
}