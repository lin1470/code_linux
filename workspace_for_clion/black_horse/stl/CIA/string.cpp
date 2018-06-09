////
//// Created by bruce on 18-5-31.
////
//#include<iostream>
//#include<string>
//using namespace std;
//
//void test04()
//{
//    string s = "abcd";
//    string s2 = "11111";
//    s+="abcd";
//    s+=s2;
//    cout <<s<<endl;
//
//    string s3 = "2222";
//    s2.append(s3);
//    cout <<s2<<endl;
//    string s4 = s2+s3;
//    cout << s4<<endl;
//}
//
////查找操作
//void test05()
//{
//    string s = "abcdefghjklfg";
//    //查找第一次出现的位置
//    int pos = s.find("fg");
//    cout << "pos:" << pos<<endl;
//
//    //查找最后一次出现位置
//    pos = s.rfind("fg");
//    cout << "pos:"<<pos << endl;
//}
//void test06()
//{
//    string s = "abcdefg";
//    s.replace(0,2,"111");
//    cout << s << endl;
//}
//void test07()
//{
//    string s1= "abcd";
//    string s2 = "abce";
//    if(s1.compare(s2)==0){
//        cout << "字符串相等!"<< endl;
//    }
//    else cout << "不相等!" << endl;
//}
//
////子串操作
//void test08()
//{
//    string s1 = "abcdefg";
//    string mysubstr = s1.substr(0,2);
//    cout << mysubstr << endl;
//}
//
////插入和删除
//void test09()
//{
//    string s = "abcdefg";
//    s.insert(3,"1111");
//    cout << s << endl;
//    //删除
//    s.erase(0,2);
//    cout << s << endl;
//}
////int main()
////{
//////    test04();
//////    test05();
//////    test06();
//////    test07();
//////    test08();
////    test09();
////    return 0;
////
////}