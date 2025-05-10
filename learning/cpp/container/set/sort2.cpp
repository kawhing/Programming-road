#include <iostream>
#include <set>
using namespace std;
class Person{
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
        }
        string name;
        int age;
};
class Compare{
    public:
        bool operator()(const Person &p1, const Person &p2){
            return p1.age > p2.age;
        }
};
void printSet(set<Person, Compare> &s){
    for(set<Person, Compare>::iterator it = s.begin(); it != s.end(); ++it)
        cout << "姓名: "<< it->name << " 年龄: " << it->age << endl;
}
void test01(){
    set<Person, Compare> s;
    Person p1("刘备", 24);
    Person p2("关羽", 28);
    Person p3("张飞", 25);
    Person p4("赵云", 21);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);    
    printSet(s);
}
int main(){
    test01();
    return 0;
}