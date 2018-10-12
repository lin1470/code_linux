#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//transform ��һ��������Ԫ�� ���� ����һ��������
struct MyPlus{
	int operator()(int val){
		return val + 100;
	}
};

void MyPrint(int val){
	cout << val << " ";
}
void test01(){

	vector<int> v1;
	vector<int> v2;
	

	for (int i = 0; i < 10;i++){
		v1.push_back(i);
	}

	v2.resize(v1.size()); //���ٿռ�

	transform(v1.begin(), v1.end(), v2.begin(), MyPlus());
	for_each(v2.begin(), v2.end(), MyPrint);
	cout << endl;
}

//���õĲ����㷨
void test02(){
	
	vector<int> v1;
	for (int i = 0; i < 10; i++){
		v1.push_back(i);
	}

	vector<int>::iterator ret = find(v1.begin(), v1.end(), 5);
	if (ret == v1.end()){
		cout << "ô���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ���:" << *ret << endl;
	}
}

class Person{
public:
	Person(int age, int id) :age(age), id(id){}
	bool operator==(const Person& p) const{
		return p.id == this->id && p.age == this->age;
	}
public:
	int id;
	int age;
};

void test03(){
	
	vector<Person> v1;

	Person p1(10, 20), p2(20, 30);

	v1.push_back(p1);
	v1.push_back(p2);

	vector<Person>::iterator ret =  find(v1.begin(), v1.end(), p1);
	if (ret == v1.end()){
		cout << "ô���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ���:" << endl;
	}

}

//binary_search ���ֲ��ҷ�
bool MySearch(int val){
	return val > 5;
}
bool MySearch2(int val){
	return val > 5;
}
void test04(){
	
	vector<int> v1;
	for (int i = 0; i < 10; i++){
		v1.push_back(i);
	}
	v1.push_back(9);

	bool ret =binary_search(v1.begin(), v1.end(), 5);
	if (ret){
		cout << "�ҵ���" << endl;
	}else{
		cout << "û���ҵ�!" << endl;
	}

	vector<int>::iterator it =  adjacent_find(v1.begin(), v1.end());
	if (it != v1.end()){
		cout << "�ҵ������ظ�Ԫ��:" << *it <<  endl;
	}
	else{
		cout << "û���Ҵ������ظ�Ԫ��" << endl;
	}

	//find_f ��������ǵ�����(����) �����ص�һ������������Ԫ�صĵ�����
	it =  find_if(v1.begin(), v1.end(), MySearch);
	if (it != v1.end()){
		cout << "�ҵ�:" << *it << endl;
	}
	else{
		cout << "û���ҵ�" << endl;
	}

	//count count_if
	int num = count(v1.begin(), v1.end(), 9);
	cout << "9���ֵĴ���:" << num << endl;
	num = count_if(v1.begin(), v1.end(), MySearch2);
	cout << "����5�ĸ�����" << num << endl;

}



int main(void){
	
	//test01();
	//test02();
	//test03();
	test04();


	return 0;
}