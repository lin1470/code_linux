#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

struct MyPrint : public binary_function<int,int,void> {
	void operator()(int v,int val) const{
		cout << "v:" << v << " val:" << val << endl;
		cout << v + val << " ";
	}
};

//�º��������� bind1st bind2nd ��������
void test01(){
	
	vector<int> v;
	for (int i = 0; i < 10;i ++){
		v.push_back(i);
	}

	int addNum = 200;
	for_each(v.begin(), v.end(), bind1st(MyPrint(), addNum));
	//��������  ��һ����Ԫ��������ת���һԪ��������
	//bind1st bind2nd����
	//bind1st����addNum��Ϊ��������ĵ�һ������
	//bind2nd����addNum��Ϊ��������ĵڶ�������
}

struct MyPrint02{
	void operator()(int v){
		cout << v << " ";
	}
};

struct MyCompare : public binary_function<int,int,bool>{
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};

struct MyGreater5 : public binary_function<int,int,bool>{
	bool operator()(int v,int val) const{
		cout << "v:" << v << " val:" << val << endl;
		return v > val;
	}
};

//�º��������� not1 not2 ȡ��������
void test02(){

	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyPrint02()); cout << endl;
	sort(v.begin(), v.end(), not2(MyCompare()));
	for_each(v.begin(), v.end(), MyPrint02()); cout << endl;

	//not1 not2 
	//����Զ�Ԫν��ȡ������not2
	//�����һԪν��ȡ������not1
	vector<int>::iterator it = find_if(v.begin(), v.end(),not1(bind2nd(MyGreater5(),10)));
	if (it == v.end()){
		cout << "û���ҵ�" << endl;
	}
	else{
		cout << *it << endl;
	}
}

//�º��������� ptr_fun
void MyPrint03(int val,int val2){
	cout << "val1:" << val << " val2:" << val2 << endl;
	cout << val + val2 << endl;
}
void test03(){

	vector<int> v;
	for (int i = 0; i < 10; i++){
		v.push_back(i);
	}

	//ptr_func����ͨ���� ת��  ��������
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint03),10));
}

//��Ա���������� mem_fun mem_fun_ref
class Person{
public:
	Person(int age, int id) :age(age), id(id){}
	void show(){
		cout << "age:" << age << " id:" << id << " aaa" << endl;
	}
public:
	int age; 
	int id;
};
void test04(){
	
	//��������д�ŵĶ�����߶���ָ�룬����for_each�㷨��ӡ��ʱ�򣬵�����
	//�Լ��ṩ�Ĵ�ӡ����

	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//��ʽ: &����::������
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));

	vector<Person*> v1;
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);

	for_each(v1.begin(),v1.end(),mem_fun(&Person::show));

	//mem_fun_ref mem_fun����?
	//�����ŵ��Ƕ���ָ�� ʹ��mem_fun
	//���ʹ�õ��Ƕ��� ʹ��mem_fun_ref
}

int main(void){

	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}