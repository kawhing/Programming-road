#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    ifstream ofs;
    ofs.open("test.txt", ios::in);
    if(!ofs.is_open()){
        cout <<  "无法正确打开文件" << endl;
        return -1;
    }
    // 读取文件
    // 方法1
    cout << "方法1" << endl;
    char c;
    while(ofs >> c){
        cout << c;
    }
    cout << endl;
    // 方法2
    ofs.close();
    ofs.open("test.txt", ios::in);
    cout << "方法2" << endl;
    char buffer[1024];
    while(ofs.getline(buffer, sizeof(buffer))){
        cout << buffer << endl;
    }
    // 方法3
    ofs.close();
    ofs.open("test.txt", ios::in);
    cout << "方法3" << endl;
    string str;
    while(getline(ofs, str)){
        cout << str << endl;
    }
    // 方法4
    ofs.close();
    ofs.open("test.txt", ios::in);
    cout << "方法4" << endl;
    char c2;
    while((c2 = ofs.get()) != EOF){
        cout << c2;
    }
    ofs.close();
    return 0;
}