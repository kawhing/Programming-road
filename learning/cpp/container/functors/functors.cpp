#include <iostream>
using namespace std;
//函数对象(仿函数)
class MyAdd{
    public:
        int operator()(int v1, int v2){
            return v1 + v2;
        }
};
//1.函数对象再使用时，可以想普通函数那样调用，可以有参数，可以有返回值
void test01(){
    MyAdd myAdd;
    cout << myAdd(10, 20);
}
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint{
    public:
        void operator()(string test){
            cout << test << endl;
        }
};
void test02(){
    MyPrint myPrint;
    myPrint("Hello World!");
}
int main(){
    test02();
}