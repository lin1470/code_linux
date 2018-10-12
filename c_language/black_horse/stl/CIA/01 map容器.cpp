#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
using namespace std;

//map������ʼ��
void test01(){

	//map����ģ���������һ������key�����ͣ��ڶ�����value����
	map<int, int> mymap;

	//��������  pair.first keyֵ piar.second valueֵ
	//��һ��
	pair<map<int, int>::iterator, bool> ret = mymap.insert(pair<int, int>(10, 10));
	if (ret.second){
		cout << "��һ�β���ɹ�!" << endl;
	}
	else{
		cout << "����ʧ��!" << endl;
	}
	ret = mymap.insert(pair<int, int>(10, 20));
	if (ret.second){
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else{
		cout << "����ʧ��!" << endl;
	}
	//�ڶ���
	mymap.insert(make_pair(20, 20));
	//������
	mymap.insert(map<int, int>::value_type(30,30));
	//������
	mymap[40] = 40;
	mymap[10] = 20; 
	mymap[50] = 50;
	//�������key�����ڣ�����pair���뵽map������
	//�������key���ڣ���ô���޸�key��Ӧ��value

	//��ӡ
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end();it ++){
		// *it ȡ��������һ��pair
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

	//���ͨ��������ʽȥ����map��һ��������key��
	//��ômap�Ὣ������ʵ�key���뵽map��,���Ҹ�valueһ��Ĭ��ֵ
	cout << " mymap[60]: " <<  mymap[60] << endl;

	//��ӡ
	for (map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++){
		// *it ȡ��������һ��pair
		cout << "key:" << (*it).first << " value:" << it->second << endl;
	}

}

class MyKey{
public:
	MyKey(int index,int id){
		this->mIndex = index;
		this->mID = id;
	}
public:
	int mIndex;
	int mID;
};

struct mycompare{
	bool operator()(MyKey key1, MyKey key2){
		return key1.mIndex > key2.mIndex;
	}
};

void test02(){
	
	map<MyKey, int, mycompare> mymap; //�Զ������Զ��������ͣ�զ��?

	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 20));

	for (map<MyKey, int, mycompare>::iterator it = mymap.begin(); it != mymap.end();it ++){
		cout << it->first.mIndex << ":" << it->first.mID << " = " << it->second << endl;
	}
}

//equal_range
void test03(){

	map<int, int> mymap;
	mymap.insert(make_pair(1, 4));
	mymap.insert(make_pair(2, 5));
	mymap.insert(make_pair(3, 6));

	pair<map<int, int>::iterator, map<int, int>::iterator> ret =  mymap.equal_range(2);
	if (ret.first != mymap.end()){
		cout << "�ҵ�lower_bound��" << endl;
	}
	else{
		cout << "û���ҵ�";
	}

	if (ret.second != mymap.end()){
		cout << "�ҵ�upper_bound��" << endl;
	}
	else{
		cout << "û���ҵ�";
	}



}

int main(void){
		
	//test01();
	//test02();
	test03();

	return 0;
}