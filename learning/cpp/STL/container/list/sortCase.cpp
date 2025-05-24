#include <iostream>
#include <list>
#include <string>
using namespace std;
class Person{
    public:
        Person(string name, int age, int height){
            this->name = name;
            this->age = age;
            this->height = height;
        }
        string name;
        int age, height;
};
void printList(const list<Person> l){
    for(list<Person>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << it->name  << " " << it->age << "岁 " << it->height << "cm" << endl;
}
//指定自定义数据类型排序规则
bool Compare(Person p1, Person p2){
    if(p1.age == p2.age){
        return p1.height < p2.height;
    }
    return p1.age < p2.age;
}

void test01(){
    list<Person> l;
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    l.push_back(p6);
    printList(l);
    cout << "-------------------------------------------" << endl;
    cout << "排序后:" << endl;
    l.sort(Compare);
    printList(l);
}
int main(){
    test01();
    return 0;
}