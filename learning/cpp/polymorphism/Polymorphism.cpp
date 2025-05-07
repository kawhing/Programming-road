#include <iostream>
using namespace std;

class Animal{
    public:
        virtual void speak(){
            cout << "动物在说话" << endl;
        }
};

class Cat : public Animal{
    public:
        void speak(){
            cout << "猫在说话" << endl;
        }
};

class Dog : public Animal{
    public:
        void speak(){
            cout << "狗在说话" << endl;
        }
}; 
//地址早绑定，在编译阶段就确定函数地址
//如果想要调用猫说话的函数，那么这个函数就不能提前绑定，
void doSpeak(Animal &animal){
    animal.speak();
}

void test02(){
    cout << "sizeof Animal = " << sizeof(Animal) << endl;
}
void test(){
    Cat cat;
    Dog dog;
    doSpeak(cat);
    doSpeak(dog);
}
int main(){
    test();
    test02();
    return 0;
}