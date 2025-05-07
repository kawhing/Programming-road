#include <iostream>
using namespace std;

class myInterger{
    friend ostream& operator<<(ostream& cout, const myInterger& interger);
    public:
        myInterger(){
            m_Num = 0;
        }
    private:
        int m_Num;
    //重载前置自增运算符,返回引用是为了一直对一个数据递增
    public:
    myInterger& operator++(){
        ++m_Num;
        return *this;
    }
    //重载后置自增运算符
    myInterger operator++(int){//不能返回引用,因为返回的是临时变量
        myInterger temp = *this;
        m_Num++;
        return temp;
    }
};

ostream& operator<<(ostream& cout, const myInterger& interger){
    cout << interger.m_Num;
    return cout;
}

void test01(){
    myInterger interger;
    cout << interger++ << endl;
    cout << interger << endl;
}

int main(){
    test01();
    return 0;
}