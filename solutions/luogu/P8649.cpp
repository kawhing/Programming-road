#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n+1), sum(n+1), mp(k, 0);
	for(ll i = 1; i <= n; ++i) cin >> a[i];
	mp[0] = 1;
	ll ans = 0;
	for(ll i = 1; i <= n; ++i){
		sum[i] = (sum[i-1]+a[i]) % k;
		ans += mp[sum[i]];
		mp[sum[i]]++;
	}
	cout << ans << endl;
	return 0;
}