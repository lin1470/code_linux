#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
using namespace std;

//��ʼ��
void test01(){
	
	list<int> mlist1;
	list<int> mlist2(10,10); //�вι���
	list<int> mlist3(mlist2);//��������
	list<int> mlist4(mlist2.begin(), mlist2.end());

	for (list<int>::iterator it = mlist5.begin(); it != mlist4.end();it ++){
		cout << *it << " ";
	}
	cout << endl;

}

//list��������ɾ��
void test02(){

	list<int> mlist;

	//�������
	mlist.push_back(100);
	mlist.push_front(200); 

	mlist.insert(mlist.begin(),300);
	mlist.insert(mlist.end(),400);
	mlist.insert(mlist.end(), 200);

	list<int>::iterator it = mlist.begin();
	it++;
	it++;
	mlist.insert(it, 500);
	mlist.insert(mlist.end(), 200);
	//ɾ��
	//mlist.pop_back();
	//mlist.pop_front();
	//mlist.erase(mlist.begin(), mlist.end()); //mlist.clear();
	mlist.remove(200); //ɾ��ƥ������ֵ

	list<int>::iterator testit = mlist.begin();
	for (int i = 0; i < mlist.size() - 1;i++){
		testit++;
	}

	(*(mlist.end()));

	cout << "------------" << endl;
	cout << (*testit) << endl;
	cout << mlist.back() << endl;
	cout << "------------" << endl;

	//ɾ������200 ����ɾ����һ�γ��ֵ�200
	/*
		for (list<int>::iterator lit = mlist.begin(); lit != mlist.end(); lit++){
		cout << *lit << " ";
		}
		cout << endl;
	*/

	

	
	
}

//��ֵ����
void test03(){

	list<int> mlist;
	mlist.assign(10, 10);


	list<int> mlist2;
	mlist2 = mlist;

	mlist2.swap(mlist);

}

//���� ��ת
void test04(){

	list<int> mlist;
	for (int i = 0; i < 10;i++){
		mlist.push_back(i);
	}

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//����Ԫ�ط�ת
	mlist.reverse();

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

}

bool mycompare05(int v1,int v2){
	return v1 > v2;
}

//����
void test05(){

	list<int> mlist;
	mlist.push_back(2);
	mlist.push_back(1);
	mlist.push_back(7);
	mlist.push_back(5);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//����  ������ô����? Ĭ�ϴ�С����
	mlist.sort();


	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//�Ӵ�С
	mlist.sort(mycompare05);

	for (list<int>::iterator it = mlist.begin(); it != mlist.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//�㷨sort ֧�ֿ�������ʵ�


}

int main(void){
	
	//test01();
	//test02();
	//test04();
	test05();



	return 0;
}