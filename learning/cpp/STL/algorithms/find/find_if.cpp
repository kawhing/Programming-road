#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class GreaterFive{
    public:
        bool operator()(int val){
            return val > 5;
        }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i) v.push_back(i+1);
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if(it == v.end()) cout << "没有找到" << endl;
    else cout << "找到大于5的数字为:" << *it << endl;
}
//2.查找自定义数据类型
class Person{
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        string name;
        int age;
};
class GreaterTwenty{
    public:
        bool operator()(Person &p){
            return p.age > 20;
        }
};
void test02(){
    vector<Person> v;
    Person p1("张三", 20);
    Person p2("李四", 30);
    Person p3("王二", 20);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterTwenty());
    if(it == v.end()) cout << "没有找到" << endl;
    else cout << "找到大于20的人为:" << it->name << " 年龄:" << it->age << endl;
}
int main(){
    test02();
    return 0;
}