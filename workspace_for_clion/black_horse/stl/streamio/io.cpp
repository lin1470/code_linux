//
// Created by bruce on 18-5-30.
//
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

void test01()
{
    char ch;
//    while((ch=cin.get())!=EOF)
//    {
//        cout << ch << endl;
//    }
    char ch2;
//    cin.get(ch2);//读取一个字符
    char buf[256]= {0};
//    cin.get(buf,256);//从缓冲区读一个字符串
    cin.getline(buf,256); // 读取一行数据,会读取换行符
    cout << buf;
}

void test02()
{
    char ch;
    cin.get(ch);//从缓冲区要数据，阻塞
    cout << ch << endl;
    cin.ignore(10,'\n');//忽略当前字符,,忽略当前n个字符，直到遇到'\n'
    cin.get(ch);
    cout << ch<< endl;
}
void test03()
{
    cout << "input array or string:"<< endl;
    char ch;
    ch = cin.peek();//偷窥一下缓冲去，返回第一个字符
    if(ch>='0'&&ch<='9')
    {
        int number;
        cin >> number;
        cout <<"is a number:"<< number << endl;
    }
    else{
        char buf[256] = {0};
        cin >>buf;
        cout << "input a string:" << buf << endl;
    }
}
//cin.putback cin.get
void test04()
{
    cout << "input a string or number:\n";
    char ch;
    cin.get(ch);//取走一个字符
    if(ch>='0'&&ch<='9'){
        cin.putback((ch));
        int number;
        cin >> number;
        cout << "is a number" << number<< endl;
    }
    else{
        cin.putback(ch);
        char buf[256] = {0};
        cin >> buf;
        cout <<"is a string"<< buf << endl;
    }
}

void test05()
{
    cout << "hello world" << endl;
    //cout.flush();
    cout.put('h').put('e').put('l')<< endl;
    cout.write("hello zhansi!",strlen("hello zhaosi!"));

}

void test06()
{
    //成员方法的方式
    int number = 10;
    cout << number << endl;
    cout.unsetf(ios::dec);//卸载当前默认10进制
    cout.setf(ios::oct);
    cout.setf(ios::showbase);//八进制
    cout << number<<endl;
    cout.unsetf(ios::oct);
    cout.setf(ios::hex);//十六进制
    cout<<number<<endl;

    cout.width(10);
    cout.fill('*');
    cout.setf(ios::right);
    cout<<number<<endl;

    int number2 = 10;
    cout<<hex
        <<setiosflags(ios::showbase)
        <<setw(10)
        <<setfill('*')
            <<setiosflags(ios::left)
        <<number2
        <<endl;


}
int main()
{
//    test01();
//    test02();
//    test03();
//    test04();
    test06();
    return 0;
}
