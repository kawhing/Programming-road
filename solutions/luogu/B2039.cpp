#include <iostream>
using namespace std;

void test(){
    long long x, y;
    cin >> x >> y;
    if(x == y) cout << '=';
    else if(x > y) cout << '>';
    else cout << '<';
}

int main(){
    test();
    return 0;
}