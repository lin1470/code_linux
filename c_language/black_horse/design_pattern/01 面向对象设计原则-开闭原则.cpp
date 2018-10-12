#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
//����ԭ��  ����չ���ţ����޸Ĺرգ����ӹ�����ͨ�����Ӵ�����ʵ�֣�������ȥ�޸�Դ����


//дһ��������
class AbstractCaculator{
public:
	virtual int getResult() = 0;
	virtual void setOperatorNumber(int a, int b) = 0;
};

//�ӷ���������
class PlusCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult(){
		return mA + mB;
	}
public:
	int mA;
	int mB;
};

//����������
class MinuteCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult(){
		return mA - mB;
	}
public:
	int mA;
	int mB;
};

//�˷�������
class MultiplyCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult(){
		return mA * mB;
	}
public:
	int mA;
	int mB;
};


//ȡģ������  ͨ�����Ӵ�����ʵ��
class MultiplyCaculator :public AbstractCaculator{
public:
	virtual void setOperatorNumber(int a, int b){
		this->mA = a;
		this->mB = b;
	}
	virtual int getResult(){
		return mA % mB;
	}
public:
	int mA;
	int mB;
};


void test01(){
	
	AbstractCaculator* caculator = new PlusCaculator;
	caculator->setOperatorNumber(10,20);
	cout << "ret:" << caculator->getResult() << endl;

	delete caculator;

	caculator = new MinuteCaculator;
	caculator->setOperatorNumber(10, 20);
	cout << "ret:" << caculator->getResult() << endl;

}







int main(void){
	test01();
	return 0;
}