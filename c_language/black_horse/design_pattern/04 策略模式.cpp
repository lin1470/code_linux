#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//�������� ��������
class WeaponStrategy{
public:
	virtual void UseWeapon() = 0;
};

class Knife : public WeaponStrategy{
public:
	virtual void UseWeapon(){
		cout << "ʹ��ذ�ף�" << endl;
	}
};

class AK47 :public WeaponStrategy{
public:
	virtual void UseWeapon(){
		cout << "ʹ��AK47��" << endl;
	}
};

class Character {
public:
	void setWeapon(WeaponStrategy* weapon){
		this->pWeapon = weapon;
	}
	void ThrowWeapon(){
		this->pWeapon->UseWeapon();
	}
public:
	WeaponStrategy* pWeapon;
};


void test01(){
	
	//������ɫ
	Character* character = new Character;

	//��������
	WeaponStrategy* knife = new Knife;
	WeaponStrategy* ak47 = new AK47;

	character->setWeapon(knife);
	character->ThrowWeapon();

	character->setWeapon(ak47);
	character->ThrowWeapon();

	delete ak47;
	delete knife;
	delete character;
}

int main(void){

	test01();
	
	return 0;
}