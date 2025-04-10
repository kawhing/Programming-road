#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//这个dfs算法时间复杂度高，得分76
ll n, c, result = 0;
vector<ll> nums, num;
vector<bool> used;
void dfs(vector<ll>& num){
	if(num.size() == 2){
		if(num[0]-num[1] == c) ++result;
		return;
	}
	for(ll i = 0; i < n; ++i){
		if(used[i]) continue;
		used[i] = true;
		num.push_back(nums[i]);
		dfs(num);
		used[i] = false;
		num.pop_back();
	}
}
int main(){
	cin >> n >> c;
	nums.resize(n);
	used.resize(n);
	for(ll i = 0; i < n; ++i){
		cin >> nums[i];
		used[i] = false;
	}
	dfs(num);
	cout << result << endl;
	return 0;
}