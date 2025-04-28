#include <iostream>
#include <string>  
using namespace std;
//函数调用运算符重载
class Person{
    public:
    string operator()(string str){
        cout << str << endl;
        return str;
    }
};

class Add{
    public:
        int operator()(int num1, int num2){
            return num1 + num2;
        }
};

void test01(){
    Person p;
    p("Hello World!");
};

void test02(){
    Add add;
    cout << add(10, 10) << endl;
}

int main(){
    test01();
    test02();
    return 0;
}