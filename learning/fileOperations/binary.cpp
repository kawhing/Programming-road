#include <iostream>
#include <fstream>
using namespace std;

class Person{
    public:
        char m_Name[64];
        int m_Age;
};

void test01(){
    ifstream ofs;
    // ofs.open("person.txt", ios::out | ios::binary);
    // Person p = {"张三", 18};
    // ofs.write((const char *)&p, sizeof(Person));
    // ofs.close();
    ofs.open("person.txt", ios::in | ios::binary);
    if(!ofs.is_open()){
        cout << "打开文件失败" << endl;
        return;
    }
    Person p;
    ofs.read((char*)&p, sizeof(Person));
    cout << "姓名: " << p.m_Name << " 年龄: " << p.m_Age << endl;

}

int main(){
    test01();
    return 0;
}