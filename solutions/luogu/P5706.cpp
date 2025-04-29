#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float t;//t ml of water
    int n;//n people
    cin >> t >> n;
    cout << fixed << setprecision(3) << t / n << endl;
    cout << n * 2 << endl;
    return 0;
}