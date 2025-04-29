#include <iostream>
#include <iomanip>
using namespace std;

void test(){
    double x;
    cin >> x;
    printf("%.6f\n",x);
    cout << fixed << setprecision(5) << x << endl;
    printf("%.6e\n",x);
    printf("%.6g",x);
}

int main(){
    test();
    return 0;
}