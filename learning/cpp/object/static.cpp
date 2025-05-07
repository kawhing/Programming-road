#include <iostream>
using namespace std;

class Person{
    public:
        // 静态成员函数
        static void func(){
            cout << "static func调用" << endl;
        }
};

void test01(){
    //Person p;
    //p.func(); // 通过对象访问
    Person::func(); // 通过类名访问
}

int main(){
    test01();
    return 0;
}