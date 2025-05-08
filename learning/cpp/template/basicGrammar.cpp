#include <iostream>
#include <string>
using namespace std;

template <class nameType, class ageType>
class Person{
    public:
        Person(nameType name, ageType age){
            this->m_Name = name;
            this->m_Age = age;
        }
        void showPerson(){
            cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
        }
        nameType m_Name;
        ageType m_Age;
};

void test01(){
    Person<string, int> p1("Tom", 10);
    p1.showPerson();
}

int main(){
    test01();
    return 0;
}