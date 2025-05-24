#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i) v.push_back(i+1);
    vector<int>::iterator it = find(v.begin(), v.end(), 50);
    if(it == v.end()) cout << "没有找到" << endl;
    else cout << "找到:" << *it << endl;
}
class Person{
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        bool operator==(const Person &p){
            if(this->name == p.name && this->age == p.age) return true;
            else return false;
        }
        string name;
        int age;

};
void test02(){
    vector<Person> v;
    Person p1("张三", 20);
    Person p2("李四", 20);
    Person p3("王二", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    Person p4("李四", 20);
    vector<Person>::iterator it = find(v.begin(), v.end(), p4);
    if(it == v.end()) cout << "没有找到" << endl;
    else cout << "找到: " << "姓名:" << it->name << " 年龄:" << it->age <<endl;
}
int main(){
    test02();
    return 0;
}