#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
void test01(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = count(v.begin(), v.end(), 5);
    cout << "5的数量为:" << num << endl;
}
//2.统计自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        bool operator==(const Person &p){
            return this->age == p.age;
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
    Person p4("张二", 20);
    int num = count(v.begin(), v.end(), p4);
    cout << "和" << p4.name << "同岁的的人数:" << num << endl;
}
int main(){
    test02();
    return 0;
}