#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <list>
using namespace std;

//�º���
class mycompare{
public:
	bool operator()(int v1,int v2){
		return v1 > v2;
	}
};

//set������ʼ��
void test01(){

	
	set<int, mycompare> s1;  //�Զ��������� Ĭ�ϴ�С����
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	for (set<int>::iterator it = s1.begin(); it != s1.end();it ++){
		cout << *it << " ";
	}
	cout << endl;
#if 0
	//��ֵ����
	set<int> s2;
	s2 = s1;

	//ɾ������
	s1.erase(s1.begin()); 
	s1.erase(7);

	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	//������� ������� �������
	//��θı�Ĭ������
#endif
}



//set����
void test02(){
	
	set<int> s1;
	s1.insert(7);
	s1.insert(2);
	s1.insert(4);
	s1.insert(5);
	s1.insert(1);

	set<int>::iterator ret = s1.find(14);
	if (ret == s1.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//�ҵ�һ�����ڵ���key��Ԫ��
	ret = s1.lower_bound(2); 
	if (ret == s1.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//�ҵ�һ������key��ֵ
	ret = s1.upper_bound(2);
	if (ret == s1.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "ret:" << *ret << endl;
	}

	//equal_range ����Lower_bound �� upper_boundֵ
	pair<set<int>::iterator,set<int>::iterator> myret = s1.equal_range(2);
	if (myret.first == s1.end()){
		cout << "û���ҵ���" << endl;
	}
	else{
		cout << "myret:" << *(myret.first) << endl;
	}

	if (myret.second == s1.end()){
		cout << "û���ҵ���" << endl;
	}
	else{
		cout << "myret:" << *(myret.second) << endl;
	}

}

class Person{
public:
	Person(int age,int id):id(id),age(age){}
public:
	int id;
	int age;
};

class mycompare2{
public:
	bool operator()(Person p1,Person p2){
		if (p1.id == p2.id){
			return p1.age > p2.age;
		}
		else{
			return p1.id > p2.id;
		}
	}
};

void test03(){

	set<Person, mycompare2> sp; //set��Ҫ���򣬵���Ŷ���set֪����ô����

	Person p1(10, 20), p2(20, 20), p3(50, 60);
	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);

	Person p4(10, 30);

	for (set<Person, mycompare2>::iterator it = sp.begin(); it != sp.end();it++){
		cout << (*it).age << " " << (*it).id << endl;
	}

	//����
	set<Person, mycompare2>::iterator ret =  sp.find(p4);
	if (ret == sp.end()){
		cout << "û���ҵ�!" << endl;
	}
	else{
		cout << "�ҵ���" << (*ret).id << " " << (*ret).age << endl;
	}
}

int main(void){

	//test01();
	//test02();
	test03();


	
	return 0;
}