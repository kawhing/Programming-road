#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;
	cin >> n;
	int ans = 1;
	char temp;
	cin >> temp;
	for(int i = 1; i < n; ++i){
		char c;
		cin >> c;
		if(c != temp){
			++ans;
			temp = c;
		} 

	}
	cout << ans+1 << endl;
}
int main(){
	solve();
	return 0;
}
