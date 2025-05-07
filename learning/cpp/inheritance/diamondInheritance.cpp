#include <iostream>
using namespace std;
//菱形继承
class Animal{
    public:
        int age;
};

//虚继承, 通过virtual关键字解决菱形继承问题
class Sheep : virtual public Animal{
};

class Camel : virtual public Animal{
};

class Alpaca : public Sheep, public Camel{
};

void test(){
    Alpaca alpaca;
    alpaca.Sheep::age = 18;
    alpaca.Camel::age = 28;
    cout << "Sheep age: " << alpaca.Sheep::age << endl;
    cout << "Camel age: " << alpaca.Camel::age << endl;
    cout << "Alpaca age: " << alpaca.age << endl;
}

int main(){
    test();
    return 0;
}