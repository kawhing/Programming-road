#include <iostream>
using namespace std;

void test(){
    int year;
    cin >> year;
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)//if is leap year
        cout << "1";
    else 
        cout << "0";
}

int main(){
    test();    
    return 0;
}