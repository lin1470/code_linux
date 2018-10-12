#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<list>
using namespace std;

//�����Ӣ�� ����Ĺ۲���
class AbstractHero{
public:
	virtual void Update() = 0;
};


//����Ӣ��  ����۲���
class HeroA :public AbstractHero{
public:
	HeroA(){
		cout << "Ӣ��A����ߣBOSS ..." << endl;
	}
	virtual void Update(){
		cout << "Ӣ��Aֹͣߣ,����״̬..." << endl;
	}
};

class HeroB :public AbstractHero{
public:
	HeroB(){
		cout << "Ӣ��B����ߣBOSS ..." << endl;
	}
	virtual void Update(){
		cout << "Ӣ��Bֹͣߣ,����״̬..." << endl;
	}
};

class HeroC :public AbstractHero{
public:
	HeroC(){
		cout << "Ӣ��C����ߣBOSS ..." << endl;
	}
	virtual void Update(){
		cout << "Ӣ��Cֹͣߣ,����״̬..." << endl;
	}
};

class HeroD :public AbstractHero{
public:
	HeroD(){
		cout << "Ӣ��D����ߣBOSS ..." << endl;
	}
	virtual void Update(){
		cout << "Ӣ��Dֹͣߣ,����״̬..." << endl;
	}
};

class HeroE :public AbstractHero{
public:
	HeroE(){
		cout << "Ӣ��E����ߣBOSS ..." << endl;
	}
	virtual void Update(){
		cout << "Ӣ��Eֹͣߣ,����״̬..." << endl;
	}
};


//�۲�Ŀ�����
class AbstractBoss{
public:
	//��ӹ۲���
	virtual void addHero(AbstractHero* hero) = 0;
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero) = 0;
	//֪ͨ���й۲���
	virtual void notify() = 0; 
};


//����Ĺ۲��� BOSSA
class BOSSA : public AbstractBoss{
public:
	virtual void addHero(AbstractHero* hero){
		pHeroList.push_back(hero);
	}
	//ɾ���۲���
	virtual void deleteHero(AbstractHero* hero){
		pHeroList.remove(hero);
	}
	//֪ͨ���й۲���
	virtual void notify(){
		for (list<AbstractHero*>::iterator it = pHeroList.begin(); it != pHeroList.end();it ++){
			(*it)->Update();
		}
	}
public:
	list<AbstractHero*> pHeroList;
};



void test01(){
	

	//�����۲���
	AbstractHero* heroA = new HeroA;
	AbstractHero* heroB = new HeroB;
	AbstractHero* heroC = new HeroC;
	AbstractHero* heroD = new HeroD;
	AbstractHero* heroE = new HeroE;

	//�����۲�Ŀ��
	AbstractBoss* bossA = new BOSSA;
	bossA->addHero(heroA);
	bossA->addHero(heroB);
	bossA->addHero(heroC);
	bossA->addHero(heroD);
	bossA->addHero(heroE);


	cout << "heroC����..." << endl;
	bossA->deleteHero(heroC);

	cout << "Boss����...֪ͨ����Ӣ��ֹͣ��������װ��..." << endl;
	bossA->notify();

}


int main(void){
	test01();
	return 0;
}