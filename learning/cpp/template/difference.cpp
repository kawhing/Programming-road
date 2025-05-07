#include <iostream>
using namespace std;

//1. 普通函数调用可以发生自动类型转换（隐式类型转换）
//2. 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
//3. 如果利用显示指定类型的方式，可以发生隐式类型转换

//函数模板
template <typename T>
T myAdd02(T a, T b){
    return a+b;
}

//普通函数
int myAdd01(int a, int b){  
    return a+b;
}

void test01(){
    int a = 10, b = 20;
    char c = 'c';
    cout << myAdd01(a, c) << endl;// 普通函数
    //cout << myAdd02(a, c)// 不会发生隐式类型转换
    cout << myAdd02<int>(a, c) << endl;// 函数模板指定类型
}

int main(){
    test01();
    return 0;
}