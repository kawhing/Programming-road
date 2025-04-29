#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n > 1){
        cout << n << " ";
        n /= 2;
    }
    cout << n << endl;
    return 0;
}