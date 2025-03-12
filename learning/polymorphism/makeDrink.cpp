#include <iostream>
using namespace std;

class AbstractDrinking{
    public:
        virtual void Boil() = 0;// 煮水
        virtual void Brew() = 0;// 冲泡
        virtual void PourInCup() = 0;// 倒入杯中
        virtual void PutSomething() = 0;// 加入辅料
        void makeDrink(){// 制作饮品
            Boil();
            Brew();
            PourInCup();
            PutSomething();
        }
};

class Coffee: public AbstractDrinking{
    public:
        void Boil(){
            cout << "煮农夫山泉" << endl;
        }
        void Brew(){
            cout << "冲泡咖啡" << endl;
        }
        void PourInCup(){
            cout << "倒入杯中" << endl;
        }
        void PutSomething(){
            cout << "加入糖和牛奶" << endl;
        }
};

class Tea : public AbstractDrinking{
    public:
        void Boil(){
            cout << "煮农夫山泉" << endl;
        }
        void Brew(){
            cout << "冲泡茶叶" << endl;
        }
        void PourInCup(){
            cout << "倒入杯中" << endl;
        }
        void PutSomething(){
            cout << "加入枸杞" << endl;
        }
};

void doWork(AbstractDrinking *abs){
    abs->makeDrink();
    delete abs;
}

void test01(){  
    doWork(new Coffee);
    cout << "----------------" << endl;
    doWork(new Tea);
}

int main(){
    test01();
    return 0;
}