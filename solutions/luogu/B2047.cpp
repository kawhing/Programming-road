#include <iostream>
#include <iomanip>
using namespace std;

float ans(float x){
    if(x >= 0 && x < 5) return -1 * x + 2.5;
    else if(x >= 5 && x < 10) return 2 - 1.5 * (x - 3) * (x - 3);
    else if(x >= 10 && x < 20) return x / 2.0 - 1.5;
    return 0; 
}

int main(){
    float x;
    cin >> x;
    cout << fixed << setprecision(3) << ans(x) << endl;
    return 0;
}