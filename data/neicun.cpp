#include <iostream>
using namespace std;

int& test(){
    static int a = 20;
    return a;
}
int main(){
    const int &ref = 10;
    cout << ref << endl;
    return 0;
}