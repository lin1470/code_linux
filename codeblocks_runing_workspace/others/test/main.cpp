#include<iostream>
using namespace std;
void swap0(int *p,int *q){
	int temp =0;
	cout << "p is :" << p << "q is :" << q << endl;
	temp = *p;
	*p = *q;
	*q = temp;
	// return 0;
}
void swap1(int &p,int &q){
	int temp = 0;
	temp = p;
	p = q;
	q = temp;
}
int main(){
	int a =0,b =1;
	cout<< "sdf";
	swap0(a,b);
	cout << "fsdfsfd"<< endl;
	cout << a <<endl << b << endl;
	return 0;
}
