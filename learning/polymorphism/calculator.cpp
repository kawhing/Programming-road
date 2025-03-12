#include <iostream>
using namespace std;

//普通写法
class Calculator{
    public:
        int getResult(char oper){
            if(oper == '+') return num1+num2;
            else if(oper == '-') return num1-num2;
            else if(oper == '*') return num1*num2;
            else if(oper == '/') return num1/num2;
            else return -1;
        }
        int num1, num2;
};

void test01(){
    Calculator calculator;
    calculator.num1 = 10;
    calculator.num2 = 10;
    cout << calculator.getResult('+') << endl;
    cout << calculator.getResult('-') << endl;
    cout << calculator.getResult('*') << endl;
    cout << calculator.getResult('/') << endl;
}

// 多态写法

class AbstractCalculator{
    public:
        virtual int getResult(){
            return 0;
        }
        int num1, num2;
};

class AddCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return num1 + num2;
        }
};

class SubCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return num1 - num2;
        }
};

class MultiCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return num1 * num2;
        }
};

class DivCalculator : public AbstractCalculator{
    public:
        int getResult(){
            return num1 / num2;
        }
};

void test02(){
    //多态使用条件
    //父类指针或者引用指向子类对象
    AbstractCalculator *abc = new AddCalculator;
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;

    abc = new SubCalculator;
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;

    abc = new MultiCalculator;
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;

    abc = new DivCalculator;
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->getResult() << endl;
    delete abc;
}

int main(){
    test02();
    return 0;
}