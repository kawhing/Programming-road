#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solove(){
    ll n, fullSum = 0, getSum = 0, lossSum = 0;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        fullSum += a[i];
    }
    for(ll i = 0; i < n; ++i){
        cin >> b[i];
        getSum += b[i];
        lossSum += a[i]-b[i];
    }
    cout << fixed << setprecision(6) << (fullSum*3-getSum*2)*1.0/lossSum << endl; 
}
int main(){
    solove();
    return 0;
}