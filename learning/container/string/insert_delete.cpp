#include <iostream>
#include <string>
using namespace std;
// 字符串的插入和删除
void test01(){
    string str = "hello";
    //插入
    str.insert(1, "111");
    cout << "str = " << str << endl;
    //删除
    str.erase(1, 3);
    cout << "str = " << str << endl;
}

int main(){
    test01();
    return 0;
}