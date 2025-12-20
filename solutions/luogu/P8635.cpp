#include <bits/stdc++.h>
using namespace std;

int check(int a, int b, int c, int d){
    return a * a + b * b + c * c + d * d;
}
void solve(){
    int n;
    cin >> n;
    for(int i = 0;; ++i){
        if(check(i, i, i, i) > n) break;
        for(int j = 0;; ++j){
            if(check(i, i, i, j) > n) break;
            for(int k = 0;; ++k){
                if(check(i, i, j, k) > n) break;
                int s = sqrt(n-check(i, j, k, 0));
                if(check(i, j, k, s) == n){
                    cout << i << " " << j << " " << k << " " << s;
                    return;
                } 
            }
        }
    }
}
int main(){
    solve();
    return 0;
}