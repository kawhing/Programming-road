#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cout << max(n-i, i-1) * 2 << endl;
    }
}
int main(){
    solve();
    return 0;
}