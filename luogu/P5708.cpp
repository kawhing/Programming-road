#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void test(){
    float a, b, c;
    cin >> a >> b >> c;
    float p = (a+b+c)/2;
    cout << fixed << setprecision(1) << sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
    test();
    return 0;
}