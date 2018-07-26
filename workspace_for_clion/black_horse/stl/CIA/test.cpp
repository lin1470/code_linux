#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//find 算法
void test01(){
    int arr[] = {5,2,8,9,1,3};
    vector<int> v(arr, arr + sizeof(arr) / sizeof(int));
/*
template<class _InIt,class _Ty> inline
_InIt find(_InIt _First, _InIt _Last, const _Ty& _Val)
{
// find first matching _Val
_DEBUG_RANGE(_First, _Last);
return (_Rechecked(_First,
_Find(_Unchecked(_First), _Unchecked(_Last), _Val)));
}
*/
//这里注意 find 返回值 如果没有找到 返回 v.end()
    vector<int>::iterator it = find(v.begin(),v.end(),1);
//可以这样判断是否找到元素
    if (it == v.end()){
        cout << "没有找到!" << endl;
    }
    else{
        cout << *it << endl;
    }
}
//find 查找对象
class sutdent{
public:
    sutdent(int age, int salary) :age(age), salary(salary){}
    int age;
    int salary;
    bool operator==(const sutdent& stu){
        if (this->age == stu.age && this->salary == stu.salary){
            return true;
        }
        else{
            return false;
        }
    }
};
void test02(){
//对象查找
    重载==操作符
    sutdent s1(1, 2), s2(3, 4), s3(5, 6);
    vector<sutdent> vs;
    vs.push_back(s1);vs.push_back(s2);
    vs.push_back(s3);
    vector<sutdent>::iterator its = find(vs.begin(), vs.end(), s2);
    if (its == vs.end()){
        cout << "s2 没有找到!" << endl;
    }
    else{
        cout << "s2 找到!" << endl;
    }
}
int main(){
//test01();
    test02();
    system("pause");
    return EXIT_SUCCESS;
}