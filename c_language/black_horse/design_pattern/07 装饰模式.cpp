#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//һ������� �ü̳�ʵ����Ĺ�����չ
//װ��ģʽ  ���Զ�̬��һ�������ӹ���

//����Ӣ��
class AbstractHero{
public:
	virtual void ShowStatus() = 0;
public:
	int mHp;
	int mMp;
	int mAt;
	int mDf;
};

//����Ӣ��
class HeroA : public AbstractHero{
public:
	HeroA(){
		mHp= 0 ;
		mMp= 0 ;
		mAt= 0 ;
		mDf= 0 ;
	}
	virtual void ShowStatus(){
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};

//Ӣ�۴���ĳ��װ���� ��ô�����Ǹ�Ӣ��
class AbstractEquipment : public AbstractHero{
public:
	AbstractEquipment(AbstractHero* hero){
		this->pHero = hero;
	}
	virtual void ShowStatus(){}
public:
	AbstractHero* pHero;
};

//��ͽ
class KuangtuEquipment : public AbstractEquipment{
public:
	KuangtuEquipment(AbstractHero* hero) :AbstractEquipment(hero){}
	//���Ӷ��⹦��
	void AddKuangtu(){
		
		cout << "Ӣ�۴��Ͽ�ͽ֮��..." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt;
		this->mDf = this->pHero->mDf + 30;

		delete this->pHero;

	}
	virtual void ShowStatus(){
		AddKuangtu(); //�������ӹ���
		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};

//�޾�֮��
class WujinzhiKnife : public AbstractEquipment{
public:
	WujinzhiKnife(AbstractHero* hero) :AbstractEquipment(hero){}
	//���Ӷ��⹦��
	void AddKuangtu(){

		cout << "Ӣ��װ���޾�֮��֮��..." << endl;
		this->mHp = this->pHero->mHp;
		this->mMp = this->pHero->mMp;
		this->mAt = this->pHero->mAt + 80;
		this->mDf = this->pHero->mDf;

		delete this->pHero;

	}
	virtual void ShowStatus(){
		AddKuangtu();

		cout << "Ѫ��:" << mHp << endl;
		cout << "ħ��:" << mMp << endl;
		cout << "����:" << mAt << endl;
		cout << "����:" << mDf << endl;
	}
};

void test01(){
	
	AbstractHero* hero = new HeroA;
	hero->ShowStatus();

	cout << "---------------" << endl;

	//���㱼��Ӣ�۴����·�
	hero = new KuangtuEquipment(hero);
	hero->ShowStatus();

	cout << "---------------" << endl;

	//��Ӣ��װ������
	hero = new WujinzhiKnife(hero);
	hero->ShowStatus();

}


int main(void){
	test01();
	return 0;
}