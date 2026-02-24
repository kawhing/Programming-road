#include <bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> nums(3);
	vector<char> ch(3);
	cin >> nums[0] >> nums[1] >> nums[2];
	cin >> ch[0] >> ch[1] >> ch[2];
	sort(nums.begin(), nums.end());
	for(int i = 0; i < 3; ++i){
		cout << nums[ch[i]-'A'] << " ";
	}
}
int main(){
	solve();
	return 0;
}
