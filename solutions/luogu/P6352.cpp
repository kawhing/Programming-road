#include <bits/stdc++.h>
using namespace std;
void solve(){
	vector<int> nums(3);
	for(int i = 0; i < 3; ++i) cin >> nums[i];
	sort(nums.begin(), nums.end());
	int diff = 0, diff1 = nums[1]-nums[0], diff2 = nums[2]-nums[1];
	
	int ans;
	if(diff1 != diff2){
		diff = min(diff1, diff2);
		if(diff1 > diff2) ans = nums[0]+diff;
		else ans = nums[1]+diff; 
	}else{
		if(nums[3]+diff <= 100) ans = diff1+nums[2];
		else if(nums[0]-diff >= -100) ans = nums[0]-diff1;
	}
	cout << ans << endl;
}
int main(){
	solve();
	return 0;
}

