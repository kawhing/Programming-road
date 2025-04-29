#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n, time = 0, max_flower = 0;
    cin >> n;
    map<ll, ll> mp;
    for(ll i = 1; i <= n; ++i){
        ll temp;
        cin >> temp;
        max_flower = max(max_flower, temp);
        mp[temp]++;
    }
    time += 10*max_flower;
    for(auto& p : mp){
        time += 5;
    }
    cout << time+n << endl;
}
int main(){
    solve();
    return 0;
}