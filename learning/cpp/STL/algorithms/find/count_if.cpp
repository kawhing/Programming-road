#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//
class GreaterTwenty{
    public:
        bool operator()(int val){
            return val > 2;
        }
};
void test01(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num = count_if(v.begin(), v.end(), GreaterTwenty());
    cout << "大于2的个数" << num << endl;
}
//自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        string name;
        int age;
};
class Greater20{
    public:
        bool operator()(const Person &p){
            return p.age > 20;
        }
};
void test02(){
    vector<Person> v;
    Person p1("张三", 20);
    Person p2("李四", 40);
    Person p3("王二", 60);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    //统计大于二十岁的人数
    int num = count_if(v.begin(), v.end(), Greater20());
    cout << "大于20岁的个数:" << num << endl;
}
int main(){
    test02();
    return 0;
}