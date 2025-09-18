#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num){
    for(int i = 2; i <= num; ++i){
        if(num % i == 0 && num != i) return false;
    }
    return true;
}
void solve(){
    int count = 0, num = 2;
    while(count <= 2025){
        if(isPrime(num))
            ++count;
        if(count == 2025){
            cout << num;
            return;
        }
        ++num;
    }
    
}
int main(){
    solve();
    return 0;
}