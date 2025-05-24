#include <iostream>
#include <string>
using namespace std;

// 字符串的查找和替换
//查找
void test01(){
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    cout << "pos = " << pos << endl;
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}
// 替换
void test02(){
    string str1 = "abcdefg";
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}

int main(){
    test02();
    return 0;
}