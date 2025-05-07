#include <iostream>
using namespace std;

// 类模板与继承
template<class T>
class Base{
    T m;
};

class Son : public Base<int>{// Base后加上<int>表示继承Base类模板的int类型，否则会报错

};

void test01(){
    Son s1;
}
//如果想灵活指定父类中T类型，子类也需要变为类模板
template <class T1, class T2>
class Son2 : public Base<char>{
    public:
        Son2(){
            cout << "T1的类型为: " << typeid(T1).name() << endl;
            cout << "T2的类型为: " << typeid(T2).name() << endl;
        }
        T1 obj;
};

void test02(){
    Son2<int, char> s2;// Son2后加上<int, char>表示继承Base类模板的char类型，否则会报错
}

int main(){
    test02();
    return 0;
}