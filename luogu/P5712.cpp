#include <iostream>
using namespace std;

void test(){
    int x;//the number of ware ate apples 
    cin >> x;
    cout << "Today, I ate " << x << " apple";
    if(x>1) cout << "s.";
    else cout << ".";
}

int main(){
    test();
    return 0;
}