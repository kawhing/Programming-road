#include <iostream>
using namespace std;

class Person{
    public:
        Person(){
            cout << "Person默认构造函数的调用" <<endl;
        }
        ~Person(){
            cout << "Person析构函数的调用" << endl;
        }

        Person(const Person &p){
            cout << "Person拷贝构造函数的调用" << endl;
            m_age = p.m_age;
        }

        Person(int age){
            m_age = age;
             cout << "Person有参构造函数的调用" << endl;
        }
        int m_age;
        
};

void test01(){
    //1. 使用一个创建好的对象初始化一个新对象
    Person p1(20);
    Person p2(p1);
    cout << "p2的年龄为 : " << p2.m_age << endl;
}

void dowork(Person p){
    
}
void test02(){

    Person p;
    dowork(p);

}

Person dowork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}
void test03(){
    Person p = dowork2();
    cout << (int*)&p << endl;
}
int main(){
    // test01();
    test03();
    return 0;
}