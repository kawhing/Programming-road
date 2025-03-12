#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak() = 0;
        virtual ~Animal() = 0;// 虚析构函数，解决父类指针释放子类对象时不调用子类析构函数的问题
};
Animal::~Animal(){}// 纯虚析构函数，需要在类外实现
class Cat : public Animal{
    public:
    Cat(string name){
        m_Name = new string(name);
    }
    void speak(){
        cout << *m_Name << "小猫在说话" << endl;
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
    // 父类指针在析构时，不会调用子类的析构函数，所以子类中的堆区数据需要手动释放
}

int main(){
    test01();
    return 0;
}