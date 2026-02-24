#include <iostream>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    int sum = 0;

    for (int i = 0; i < n; ++i) {
        if (x != 6 && x != 7) {
            sum += 250;
        }
        x++;
        if (x > 7) {
            x = 1;
        }
    }

    cout << sum << endl;
    return 0;
}