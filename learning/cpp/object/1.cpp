#include <iostream>
using namespace std;

class Person{
    public:
        Person(){
            cout << "默认构造函数的调用" << endl;
        }

        Person(int age){
            cout << "Person有参构造函数的调用" << endl;
            m_age = age;
        }
        
        ~Person(){
            cout << "Person析构构造函数的调用" << endl;
        }
        //Person(const Person &p){
        //    cout << "Person的拷贝构造函数的调用" << endl;
        //}
        Person(int age, int height){
            m_age = age;
            m_height = new int(height);
            cout << "Person的有参构造函数的调用" << endl;
        }
        Person(const Person& p){
            cout << "Person 的拷贝函数的调用" << endl;
            m_age = p.m_age;
            //m_height = p.m_height是编译器自己生成的
            m_height = new int(*p.m_height);
        }
        int m_age, *m_height;
};
void test01(){
    Person p1(18, 170);
    cout << "p1的年龄为 : " << p1.m_age << " 身高为 : " << *p1.m_height << endl;
    Person p2(p1);
    cout << "p2的年龄为 : " << p2.m_age  << " 身高为 : " << *p2.m_height << endl;
}
int main(){
    test01();
    return 0;
}