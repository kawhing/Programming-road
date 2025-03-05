#include <iostream>
using namespace std;

int main(){
    long long n;
    int cords = 0;
    cin >> n;
    while(n != 1){
        if(n % 2 == 1) n = n*3 + 1;
        else n /= 2;
        ++cords;
    }
    cout << cords << endl;
    return 0;
}