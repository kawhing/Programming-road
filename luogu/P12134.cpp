#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//不能完美通过
ll n, m, l_min = LLONG_MAX;
vector<ll> a, chose;
void dfs(ll l, vector<bool> &used){;
	if(chose.size() == m){
		for(ll i = 0; i < chose.size()-1; ++i){
			l += abs(chose[i+1]*chose[i+1]-chose[i]*chose[i]);
		}
		l_min = min(l, l_min);
		return;
	}
	for(ll i = 0; i < n; ++i){
		if(used[i]) continue;
		used[i] = true;
		chose.push_back(a[i]);
		dfs(l, used);
		chose.pop_back();
		used[i] = false;
	}
}
int main(){
	cin >> n >> m;
	a.resize(n);
	for(ll i = 0; i < n; ++i) cin >> a[i];
	vector<bool> used(n, false);
	dfs(0, used);
	cout << l_min << endl;
	return 0;
}
