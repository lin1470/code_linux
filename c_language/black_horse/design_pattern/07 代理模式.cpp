#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//�ṩһ�ִ��������ƶ���������ķ���
class AbstractCommonInterface{
public:
	virtual void run() = 0;
};

//���Ѿ�д�õ�ϵͳ
class MySystem : public AbstractCommonInterface{
public:
	virtual void run(){
		cout << "ϵͳ����..." << endl;
	}
};

//������ҪȨ����֤�����������˶����������ҵ��������ṩ�û���������
class MySystemProxy : public AbstractCommonInterface{
public:
	MySystemProxy(string username,string password){
		this->mUsername = username;
		this->mPassword = password;
		pSystem = new MySystem;
	}

	bool checkUsernameAndPassoword(){
		if (mUsername == "admin" && mPassword == "admin"){
			return true;
		}
		return false;
	}

	virtual void run(){
		
		if (checkUsernameAndPassoword()){
			cout << "�û�����������ȷ����֤ͨ��..." << endl;;
			this->pSystem->run();
		}
		else{
			cout << "�û��������������,Ȩ�޲���..." << endl;
		}

	}
	~MySystemProxy(){
		if (pSystem != NULL){
			delete pSystem;
		}
	}
public:
	MySystem* pSystem;
	string mUsername;
	string mPassword;
};

void test01(){

	
	MySystemProxy* proxy = new MySystemProxy("admin","admin");
	proxy->run();


}



int main(void){
	test01();
	return 0;
}