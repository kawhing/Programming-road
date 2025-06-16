#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; ++i) cin >> x[i];
	for(int i = 0; i < n; ++i) cin >> y[i];	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	bool ans = true;
	for(int i = 0; i < n; ++i){
		if(x[i] > y[i]){
			ans = false;
			break;
		}
	}
	if(ans) cout << "DA" << endl;
	else cout << "NE" << endl;
}
int main(){
	solve();
	return 0;
}
