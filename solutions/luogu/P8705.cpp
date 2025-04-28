#include <iostream>
using namespace std;

void questionA(){
    int stamina = 10000, loss = 600, add = 300, time = 0;
    while(stamina > 0){
        stamina -= loss;
        ++time;
        if(time <= 0){
            cout << time*60 << endl;
            return;
        }
        ++time;
        stamina += add;
    }
    cout << time*60 << endl;
}

void questionB(){
    int year = 1921, month = 7, day = 23;
}

void questionC(){

}

void questionD(){

}

void questionE(){

}

void test(){
    char c;
    cin >> c;
    if(c == 'A') questionA();
    else if(c == 'B') questionB();
    else if(c == 'C') questionC();
    else if(c == 'D') questionD();
    else if(c == 'E') questionE();
    else return;
}

int main(){
    test();
    return 0;
}