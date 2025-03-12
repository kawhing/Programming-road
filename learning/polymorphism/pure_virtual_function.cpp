#include <iostream>
using namespace std;

class Base{
    public:
        // 纯虚函数
        // 有了纯虚函数，这个类也称为抽象类
        virtual void func() = 0;
        //抽象类特点：
        // 无法实例化对象
        // 抽象类的子类必须要重写父类中的纯虚函数，否则也属于抽象类 
};

class Son : public Base{
    public:
        virtual void func(){
            cout << "Hello World" << endl;
        }

};

void test01(){
    //Base b;// 抽象类无法实例化对象
    //new Base;// 抽象类无法实例化对象
    Base *base = new Son;// 抽象类指针可以指向子类对象
    base->func();// 子类对象调用父类的纯虚函数
}

int main(){
    test01();
    return 0;
}