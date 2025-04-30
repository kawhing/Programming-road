#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll sum = 0, m = 0, allSum = 0;
    for(ll i = 1; i <= n; ++i){
        allSum += i;
        if(i  % k == 0){
            ++m;
            sum += i;
        }
    }
    cout << fixed << setprecision(1) << sum*1.0/m << " " << (allSum-sum)*1.0/(n-m) << endl;
}
int main(){
    solve();
    return  0;
}
