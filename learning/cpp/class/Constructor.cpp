#include <iostream>
using namespace std;

class constructor{
    public:
        //构造函数
        constructor(){
            cout << "Constructor无参构造函数的调用" << endl;
        }
        constructor(int a){
            age = a;
            cout << "Constructor有参构造函数的调用" << endl;
        }
        //拷贝构造函数
        constructor(const constructor &p){
            //将传入的属性拷贝到当前对象
            cout << "拷贝构造函数的调用" << endl;
            age = p.age;
        }
        ~constructor(){
            cout << "~Constructor析构函数的调用" << endl;
        }
        int age;
};

//调用
void test01(){
    // //括号法
    //     constructor p1;//默认构造函数调用
    //     constructor p2(10);//默认有参构造函数调用
    //     constructor p3(p2);//拷贝构造函数的调用
    //     cout << "p2的年龄 : " << p2.age << endl;
    //     cout << "p3的年龄 : "  << p3.age << endl;
    //     //如果constructor p1(); 会被认为是函数的声明而不会创建对象

    //显示法
    // // constructor p1;
    // // constructor p2 = constructor(10);//有参构造
    // // constructor p3 = constructor(p2);//拷贝函数
    // constructor(10);
    // cout << "aaaaaa" << endl;
    // //不要用拷贝构造函数 初始化匿名对象 编译器会认为 constructor(p2) === constructor p2; 
    // constructor(p3);

    //隐式转换法
    constructor p4 = 10;//相当于constructor p4 = constructor(10);
}
int main(){
    test01();
}