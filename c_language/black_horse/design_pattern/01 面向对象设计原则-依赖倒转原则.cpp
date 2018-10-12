#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//���й�����Ա
class BankWorker{
public:
	void saveService(){
		cout << "������ҵ��..." << endl;
	}
	void payService(){
		cout << "����֧��ҵ��.." << endl;
	}
	void tranferService(){
		cout << "����ת��ҵ��.." << endl;
	}
};

//�в�ģ��
void doSaveBussiness(BankWorker* worker){
	worker->saveService();
}
void doPayBussiness(BankWorker* worker){
	worker->payService();
}
void doTransferBussiness(BankWorker* worker){
	worker->tranferService();
}

void test01(){

	BankWorker* worker = new BankWorker;
	doSaveBussiness(worker); //������ҵ��
	doPayBussiness(worker); //����֧��ҵ��
	doTransferBussiness(worker); //����ת��ҵ��
}



//���й�����Ա
class AbstractWorker{
public:
	virtual void doBusiness() = 0;
};

//ר�Ÿ��������ҵ��Ĺ�����Ա
class SaveBankWorer :public AbstractWorker{
public:
	virtual void doBusiness(){
		cout << "������ҵ��..." << endl;
	}
};

//ר�Ű���֧��ҵ��Ĺ�����Ա
class PayBankWorker : public AbstractWorker{
public:
	virtual void doBusiness(){
		cout << "����֧��ҵ��..." << endl;
	}
};

//ר�Ű���ת��ҵ��Ĺ�����Ա
class TransferBankWorker : public AbstractWorker{
public:
	virtual void doBusiness(){
		cout << "����ת��ҵ��..." << endl;
	}
};

//�в�ҵ��  ���ܿ���չ
void doNewBusiness(AbstractWorker* worker){
	worker->doBusiness();
	delete worker;
}

void tesat02(){
	
	doNewBusiness(new TransferBankWorker);
	doNewBusiness(new PayBankWorker);
	doNewBusiness(new SaveBankWorer);
}





int main(void){
	tesat02();
	return 0;
}