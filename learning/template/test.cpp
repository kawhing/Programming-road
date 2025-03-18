#include <iostream>
using namespace std;

template <typename T>
void test(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int a = 1, b = 2;
    test(a, b);// 自动推导类型
    cout << "a = "<< a << " b = " << b << endl;
    test<int>(a, b);// 显示指定类型
    cout << "a = "<< a << " b = " << b << endl;
    return 0;
}