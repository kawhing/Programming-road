#include <iostream>
using namespace std;
// 继承中的同名成员处理方式
class Base{
    public:
        int m_A;
        Base(){
            m_A = 100;
        }
        void func(){
            cout << "Base func()" << endl;
        }
        void func(int a){
            cout << "Base func(int a)" << endl;
        }
};

class Son : public Base{
    public:
        int m_A;
        Son(){
            m_A = 200;
        }
        void func(){
            cout << "Son func()" << endl;
        }
        //void func(int a){
        //    cout << "Son func(int a)" << endl;
        //}
};
void test01(){
    Son s;
    cout << s.m_A << endl;// 如果子类和父类有同名的成员变量，子类会隐藏父类的成员变量，如果想访问父类的成员变量，需要加作用域
    cout << s.Base::m_A << endl;// 访问父类的成员变量
    s.func();// 如果子类和父类有同名的成员函数，子类会隐藏父类的成员函数，如果想访问父类的成员函数，需要加作用域
    s.Base::func();// 访问父类的成员函数
    //s.func(10);// 如果子类和父类有同名的成员函数，子类会隐藏父类的成员函数，如果想访问父类的成员函数，需要加作用域
    s.Base::func(10);// 访问父类的成员函数
}
int main(){
    test01();
    return 0;
}