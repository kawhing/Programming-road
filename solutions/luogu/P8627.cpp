#include <iostream>
#include <cmath>
using namespace std;

bool isBackup(int n){
    if(n >= 3){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    int number = n;
    while(isBackup(n)){
        number += n / 3;
        n = n / 3 + n % 3;
    }
    cout << number << endl;
    return 0;
}