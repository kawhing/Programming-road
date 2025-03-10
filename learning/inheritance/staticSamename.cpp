#include <iostream>
using namespace std;
// 继承中的静态同名成员处理方式
class Base{
    public:
        static int m_A;
        static void func(){
            cout << "Base func()" << endl;
        }
};
int Base::m_A = 100;
class Son : public Base{
    public:
        static int m_A;
        static void func(){
            cout << "Son func()" << endl;
        }
};
int Son::m_A = 200;

void test01(){
    Son s;
    cout << "通过对象访问" << endl;
    cout << s.m_A << endl;// 如果子类和父类有同名的成员变量，子类会隐藏父类的成员变量，如果想访问父类的成员变量，需要加作用域
    cout << s.Base::m_A << endl;// 访问父类的成员变量 
    cout << "通过类名访问" << endl;
    cout << Son::m_A << endl;// 访问子类的成员变量
    cout << Base::m_A << endl;
    cout << Son::Base::m_A << endl;// 访问父类的成员变量

    s.func();
    s.Base::func();
    Son::func();
    Son::Base::func();

}

int main(){
    test01();
    return 0;
}