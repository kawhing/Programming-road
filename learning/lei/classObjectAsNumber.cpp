#include<iostream>
#include<string>
using namespace std;

//类对象作为类成员

//手机类
class Phone{
    public:
        Phone(string Name){
            cout << "Phone构造函数调用" << endl;
            m_PhoneName = Name;
        }
        string m_PhoneName;

        ~Phone(){
            cout << "Phone析构函数调用" << endl;
        }
};
//人类
class Person{
    public:
        Person(string Name, string PhoneName):m_Name(Name), m_Phone(PhoneName){
            cout << "Person构造函数调用" << endl;
        }
        
        ~Person(){
            cout << "Person析构函数调用" << endl;
        }
        
        //人名
        string m_Name;
        //手机
        Phone m_Phone;//类对象作为类成员
};
void test01(){
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身, 析构的时候先析构自身，再析构类对象
    Person p("张三", "苹果15Pro");
    cout << p.m_Name << "零元购一台" << p.m_Phone.m_PhoneName << "低于1000USD不违法" << endl;
}

int main(){
    test01();

    return 0;
}