#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


//���ӻ�
class Television{
public:
	void On(){
		cout << "���ӻ���..." << endl;
	}
	void Off(){
		cout << "���ӻ��ر�..." << endl;
	}
};

//��
class Light{
public:
	void On(){
		cout << "�ƴ�..." << endl;
	}
	void Off(){
		cout << "�ƹر�..." << endl;
	}
};
//����
class Audio{
public:
	void On(){
		cout << "�����..." << endl;
	}
	void Off(){
		cout << "����ر�..." << endl;
	}
};

//��˷�
class Mircophone{
public:
	void On(){
		cout << "��˷��..." << endl;
	}
	void Off(){
		cout << "��˷�ر�..." << endl;
	}
};

//DVD������
class DVDPlayer{
public:
	void On(){
		cout << "DVD��������..." << endl;
	}
	void Off(){
		cout << "DVD�������ر�..." << endl;
	}
};


//��Ϸ��
class Gamemachine{
public:
	void On(){
		cout << "��Ϸ����..." << endl;
	}
	void Off(){
		cout << "��Ϸ���ر�..." << endl;
	}
};


class KTVMode{
public:
	KTVMode(){
		pTv = new Television;
		pLight = new Light;
		pAudio = new Audio;
		pMicrophone = new Mircophone;
		pDvd = new DVDPlayer;
	}

	void OnKTV(){
		pTv->On();
		pLight->Off();
		pAudio->On();
		pMicrophone->On();
		pDvd->On();
	}

	void OffKTV(){
		pTv->Off();
		pLight->On();
		pAudio->Off();
		pMicrophone->Off();
		pDvd->Off();
	}

	~KTVMode(){
		delete pTv;
		delete pLight;
		delete pAudio;
		delete pMicrophone;
		delete pDvd;
	}
public:
	Television* pTv;
	Light* pLight;
	Audio* pAudio;
	Mircophone* pMicrophone;
	DVDPlayer* pDvd;
};

void test01(){

	KTVMode* ktv = new KTVMode;
	ktv->OnKTV();
}


int main(void)
{
	test01();
	system("pause");
	return 0;
}