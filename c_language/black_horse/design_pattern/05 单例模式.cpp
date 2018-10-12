#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class A{
private:
	A(){
		a = new A;
	}
public:
	static A* getInstace(){
		return a;
	}

private:
	static A* a;
};

A* A::a = NULL;

//ʵ�ֵ�������
//1. ���캯��˽�л�
//2. ���Ӿ�̬˽�еĵ�ǰ���ָ�����
//3. �ṩ��̬����ӿڣ��������û���õ�������


//���� ��Ϊ����ʽ 
class Singleton_lazy{
private:
	Singleton_lazy(){}
public:
	static Singleton_lazy* getInstance(){
		if (pSingleton == NULL){
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}
private:
	static Singleton_lazy* pSingleton;
};
//�����ʼ��
Singleton_lazy* Singleton_lazy::pSingleton = NULL;

//����ʽ
class Singleton_hungry{
private:
	Singleton_hungry(){}
public:
	static Singleton_hungry* getInstance(){
		return pSingleton;
	}

#if 0
	static void freeSpace(){
		if (pSingleton != NULL	){
			delete pSingleton;
		}
	}
#endif

	class Garbo{
		~Garbo(){
			if (pSingleton != NULL){
				delete pSingleton;
			}
		}
	};

private:
	static Singleton_hungry* pSingleton;
	static Garbo garbo;
}; 
Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test01(){
	
	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ�,�ǵ���!" << endl;
	}
	else{
		cout << "���ǵ���ģʽ��" << endl;
	}

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4){
		cout << "����ָ��ָ��ͬһ���ڴ�ռ�,�ǵ���!" << endl;
	}
	else{
		cout << "���ǵ���ģʽ��" << endl;
	}
}

//���������ͷ�����

void test02(){}


int main(void){
	test01();

	return 0;
}