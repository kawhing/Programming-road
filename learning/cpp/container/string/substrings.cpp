#include <iostream>
#include <string>
using namespace std;
// string求子串
void test01(){
    string str = "abcdef";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl; 
}
//实用操作
void test02(){
    string email = "kawhing@users.noreply.github.com";
    //从邮件地址中获取用户名信息
    int pos = email.find("@");
    string userName = email.substr(0, pos);
    cout << "用户名 = " <<  userName << endl;
}
int main(){
    test02();
    return 0;
}