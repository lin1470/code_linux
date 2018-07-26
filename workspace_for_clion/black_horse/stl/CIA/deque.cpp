////
//// Created by bruce on 18-6-8.
////
//#include<iostream>
//#include<deque>
//using namespace std;
//
//void test01()
//{
//    deque<int> d1;
//    deque<int> d2(10,5);
//    deque<int> d3(d2.begin(),d2.end());
//    deque<int> d4(d3);
//
//}
//
//
//void test02()
//{
//    deque<int> d1;
//    deque<int> d2;
//    deque<int> d3;
//    d1.assign(10,5);
//    d2.assign(d1.begin(),d1.end());
//    d3 = d2; //等号赋值
//    d1.swap(d2);
//
//    if(d1.empty()){
//        cout << "empty!\n";
//    }
//    else cout << "size:" << d1.size()<< endl;
//
//    d1.resize(5); // 重新指定大小
//
//}
//void printDeque(deque<int> &d4)
//{
//
//    for(deque<int>::iterator it =d4.begin();it!=d4.end();it++)
//    {
//        cout <<*it << " ";
//    }
//    cout << endl;
//}
//void test03()
//{
//    deque<int> d1;
//    d1.push_back(100);
//    d1.push_back(200);
//    d1.push_back(300);
//    d1.push_back(400);
//    d1.push_back(500);
//    printDeque(d1);
//    int val = d1.front(); //拿到被删除的数据
//    d1.pop_front();//删除头元素
//
//    d1.pop_back();//删除最后一个元素
//}
//
//int main()
//{
//    test01();
//    return 0;
//}
