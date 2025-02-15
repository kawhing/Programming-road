#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int n){
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n % i == 0) return false;
    }
    return true;
}
int getMin(int n){
    int sum = 2*n + 2;
    for(int i = 3; i < sum; i+=2){
        if(isPrime(i) && isPrime(sum-i)) return i;
    }
    return 0;
}

int test(int sum, int n){
    return sum-n;
}

int main(){
    int N;
    cin >> N;
    cout << "4=2+2" << endl;
    for(int i = 2; i <= (N-2)/2; ++i){
        cout << 2*i+2 << "=" << getMin(i) << "+" << test(2*i+2, getMin(i)) << endl;
    }
    return 0;
}