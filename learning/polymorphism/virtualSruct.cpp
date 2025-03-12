#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak() = 0;
};

class Cat : public Animal{
    public:
    Cat(string name){
        m_Name = new string(name);
    }
    void speak(){
        cout << "小猫在说话" << endl;
    }
    ~Cat(){
        if (m_Name != NULL){
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};

void test01(){
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal;
}

int main(){
    test01();
    return 0;
}