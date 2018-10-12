////
//// Created by bruce on 18-6-7.
////
//#include<iostream>
//#include<vector>
//using namespace std;
//void printVector(vector<int> &v)
//{
//    for(vector<int>::iterator it = v.begin();it!= v.end();it++)
//    {
//        cout << *it<< " ";
//    }
//    cout << endl;
//}
//void test01()
//{
//    vector<int> v1; //默认构造
//    int arr[] = {10,20,30,40};
//    vector<int> v2(arr,arr+sizeof(arr)/sizeof(int));
//    vector<int> v3(v2.begin(),v2.end());
//    vector<int> v4(v3);
//    printVector(v2);
//    printVector(v3);
//    printVector(v4);
//}
//
//void test02()
//{
//    int arr[] = {10,20,30,40};
//    vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
//    //成员方法
//    vector<int> v2;
//    v2.assign(v1.begin(),v1.end());
//    //重载
//    vector<int> v3;
//    v3 = v2;
//
//    printVector(v1);
//    printVector(v2);
//
//    cout << " swap" << endl;
//
//    int arr1[] = {100,200,300,400,500};
//    vector<int> v4(arr1,arr1+sizeof(arr1)/sizeof(int));
//    v4.swap(v1);
//    //这个swap的原理不过就是交换指针而已
//    //果然,因为这个两个数组的长度不一样,如果是真真交换数据的话,那么应该会出现错误.
//
//    printVector(v1);
//    printVector(v2);
//    printVector(v4);
//}
//
//void test03()
//{
//    int arr[] = {10,20,30,40};
//    vector<int> v1(arr,arr+sizeof(arr)/sizeof(int));
//    cout << "size: "<<v1.size() << endl;
//
//    if(v1.empty()){
//        cout << "empty\n";
//    }
//    else cout << "not empty\n";
//    v1.reserve(20);
//    cout << "capacity" << v1.capacity() << endl;
//    v1.resize(10);
//    cout << "--------" << endl;
//    cout << "size:" << v1.size()<< endl;
//    cout << "capacity:" << v1.capacity() << endl;
//
//    //收缩空间
//    vector<int>(v1).swap(v1);
//
//    cout << "shou--------" <<  endl;
//    cout << "size:" <<v1.size()<<endl;
//    cout << "capacity:" << v1.capacity() << endl;
//
//    vector<int> v;
//    int* p = NULL;
//    int count = 0;// 统计 vector 容量增长几次?
//    for (int i = 0; i < 200000;i++){
//        v.push_back(i);
//        if (p != &v[0]){
//            p = &v[0];
//            cout << "capacity:" << v.capacity()<< " ";
//            count++;
//        }
//    }
//    cout << "count:" << count << endl; //打印出 30
//
//    vector<int> v2;
//    v.reserve(100000);
//    for (int i = 0; i < 100000;i++){
//        v.push_back(i);
//        if (p != &v2[0]){
//            p = &v2[0];
//            count++;
//        }
//    }
//    cout << "count:" << count << endl; //打印出 30
//}
//
//
//void test04()
//{
//    int arr[] = {10,20,30,40};
//    vector<int> v4(arr,arr+sizeof(arr)/sizeof(int));
//
//    for(int i =0 ;i<v4.size();i++)
//    {
//        cout << v4[i] << " ";
//    }
//    cout << endl;
//
//    v4.at(0) = 0;
//    for(int i =0;i<v4.size();i++)
//        cout << v4.at(i) << " ";
//
//}
//int main()
//{
////    test01();
////    test02();
//    test03();
////    test04();
//    return 0;
//}
