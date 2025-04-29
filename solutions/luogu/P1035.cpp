#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    double result = 0;
    int n = 0;

    while (result <= k) {
        n++;
        result += 1.0 / n;
    }

    cout << n << endl;
    return 0;
}