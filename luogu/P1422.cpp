#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float sum = 0, num;
    cin >> num;
    if(num <= 150) sum = num * 0.4464;
    else if(num <= 400) sum = 150 * 0.4464 + (num-150)*0.4663;
    else sum = 150 * 0.4464 + (400-150)*0.4663 + (num-400)*0.5663;
    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}