#include <iostream>
using namespace std;

class Constructor{
    public:
        Constructor(){
            cout << "Constructor默认构造函数的调用" << endl;
        }

        Constructor(int age){
            cout << "Constructor有参构造函数的调用" << endl;
            m_age = age;
        }


        Constructor(const Constructor &p){
            cout << "Constructor拷贝构造函数的调用" << endl;
            m_age = p.m_age;

        }

        ~Constructor(){
            cout << "Constructor析构函数的调用" << endl;
        }
        int m_age;
};

void test01(){
    //1.使用一个已经创建好的对象来初始化一个新对象
    Constructor p1(20);
    Constructor p2(p1);
    cout << "p2的年龄 : " << p2.m_age << endl;
}
int main(){
    test01();
    return 0;
}