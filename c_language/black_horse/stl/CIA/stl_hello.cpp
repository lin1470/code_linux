////
//// Created by bruce on 18-5-31.
////
//#include<iostream>
//#include<vector>
//#include <algorithm>
//
//using namespace std;
//
//class Person
//{
//public:
//    Person(int age,int id):age(age),id(id){}
//
//public:
//    int age;
//    int id;
//};
//void printVector(int val)
//{
//    cout << val<<" ";
//}
//void test01()
//{
//    vector<int> v;//定义一个容器，并且指定这个容器存放的元素类型ing
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);
//    v.push_back(50);
//    v.push_back(60);
//    //通过stl提供的for_each算法
//    //容器提供的迭代器
//    vector<int>::iterator pbegin = v.begin();//指向第一个元素
//    vector<int>::iterator pend = v.end();//指向容器的结尾，而不是结束元素
//    //容器中可能存放基础的数据类型，也可能存在自定义数据类型
//
//    //遍历容器算法，涉及到回调函数
//    for_each(pbegin,pend,printVector);
//}
//void test02()
//{
//    vector<Person> v;
//    Person p1(10,2),p2(20,34);
//    v.push_back(p1);
//    v.push_back(p2);
//    for(vector<Person>::iterator it = v.begin();it!=v.end();it++)
//    {
//        cout<<(*it).age<<" "<<(*it).id<<endl;
//    }
//
//}
////
////int main()
////{
////
//////    test01();
////    test02();
////    return 0;
////
////}