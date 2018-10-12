#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include<Windows.h>
using namespace std;


//Э�鴦����
class HandleClientProtocol{
public:
	//�������ӽ��
	void AddMoney(){
		cout << "��������ӽ�ң�" << endl;
	}

	//����������ʯ
	void AddDiamond(){
		cout << "�����������ʯ!" << endl;
	}

	//�������װ��
	void AddEquipment(){
		cout << "����Ҵ�װ����" << endl;
	}

	//�����������
	void addLevel(){
		cout << "���������!" << endl;
	}
};

//����ӿ�
class AbstractCommand{
public:
	virtual void handle() = 0; //����ͻ�������Ľӿ�
};


//�������ӽ������
class AddMoneyCommand :public AbstractCommand{
public:
	AddMoneyCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	virtual void handle(){
		this->pProtocol->AddMoney();
	}
public:
	HandleClientProtocol* pProtocol;
};

//����������ʯ������
class AddDiamondCommand :public AbstractCommand{
public:
	AddDiamondCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	virtual void handle(){
		this->pProtocol->AddDiamond();
	}
public:
	HandleClientProtocol* pProtocol;
};


//������Ҵ�װ��������
class AddEquipmentCommand : public AbstractCommand{
public:
	AddEquipmentCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	virtual void handle(){
		this->pProtocol->AddEquipment();
	}
public:
	HandleClientProtocol* pProtocol;
};

//�����������������
class AddLevelCommand : public AbstractCommand{
public:
	AddLevelCommand(HandleClientProtocol* protocol){
		this->pProtocol = protocol;
	}
	virtual void handle(){
		this->pProtocol->addLevel();
	}
public:
	HandleClientProtocol* pProtocol;

};


//����������
class Serser{
public:
	void addRequest(AbstractCommand* command){
		mCommands.push(command);
	}

	void startHandle(){
		while (!mCommands.empty()){

			Sleep(2000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
public:
	queue<AbstractCommand*> mCommands;
};

void test01(){
	
	HandleClientProtocol* protocol = new HandleClientProtocol;
	//�ͻ������ӽ�ҵ�����
	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	//�ͻ���������ʯ������
	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
	//�ͻ��˴�װ��������
	AbstractCommand* addequpment = new AddEquipmentCommand(protocol);
	//�ͻ�����������
	AbstractCommand* addlevel = new AddLevelCommand(protocol);

	Serser* server = new Serser;
	//���ͻ���������뵽����Ķ�����
	server->addRequest(addmoney);
	server->addRequest(adddiamond);
	server->addRequest(addequpment);
	server->addRequest(addlevel);

	//��������ʼ��������
	server->startHandle();
}

int main(void){
	test01();
	return 0;
}