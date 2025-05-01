#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, sum = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i)
        sum += i+1;
    cout << sum << endl;
}
int main(){
    solve();
    return 0;
}