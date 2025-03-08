#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Quetiosn number D (R format) the 15th lanqiao Cup 
void test(){
    long long n;
    double d;
    cin >> n >> d;
    cout << fixed << setprecision(0) << d*pow(2, n) << endl;
}

int main(){
    test();
    return 0;
}