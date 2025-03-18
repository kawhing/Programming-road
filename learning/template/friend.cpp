#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>
class Person{
    // 1. 全局函数配合友元访问类中私有成员
    friend void printPerson(Person<T1, T2> p){
        cout << "Name: " << p.m_Name << " Age: " << p.m_Age << endl;
    }

public:
    Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }
    T1 m_Name;
    T2 m_Age;

};
// 1. 全局函数配合友元访问类中私有成员
// 2. 全局函数在类内声明，类外实现
void test01(){
    Person<string, int> p("Tom", 20);
    printPerson(p);
}

int main(){
    test01();
    return 0;
}