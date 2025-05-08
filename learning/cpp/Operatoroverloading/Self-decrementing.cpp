#include <iostream>
using namespace std;

class myInterger{
    friend ostream& operator<<(ostream& cout, const myInterger& interger);
    private:
        int m_Num;
    public:
        myInterger(){
            m_Num = 0;
        }
        //重载前置自减运算符
        myInterger& operator--(){
            --m_Num;
            return *this;
        }
        //重载后置自减运算符
        myInterger operator--(int){
            myInterger temp = *this;
            m_Num--;
            return temp;
        }
};

ostream& operator<<(ostream& cout, const myInterger& interger){
    cout << interger.m_Num;
    return cout;
}
void test(){
    myInterger interger;
    cout << --interger << endl;
    cout << interger << endl;
}

int main(){
    test();
    return 0;
}