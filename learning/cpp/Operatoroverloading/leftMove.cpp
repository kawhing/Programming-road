#include <iostream>
using namespace std;

class Person{
    friend ostream &operator<<(ostream &out, Person &p);
    public: 
        Person(int a, int b){
            m_A = a;
            m_B = b;
        }
    private:
        int m_A, m_B;
        // 利用成员函数实现重载左移运算符
        //void operator<<(Person &p){} p << cout 所以一般不用成员函数重载左移运算符

};

ostream &operator<<(ostream &out, Person &p){
    out << "m_A = " << p.m_A << " m_B = " << p.m_B ;
    return out;
}

void test01(){
    Person p(10, 10);
    cout << p << "Hello World" << endl;
}

int main(){
    test01();
    return 0;
}