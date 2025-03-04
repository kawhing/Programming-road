#include <iostream>
using namespace std;

void test(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(a > c) swap(a, c);
    if(b > c) swap(b, c);
    cout << a << " " << b << " " << c << endl;
}

int main(){
    test();
    return 0;
}