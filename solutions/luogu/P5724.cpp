#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int n;
	cin >> n;
	vector<int> nums;
	while(n--){
		int i;
		cin >> i;
		nums.push_back(i);
	}
	sort(nums.begin(), nums.end());
	cout << nums.back()-nums[0] << endl;
}
int main(){
	solve();
	return 0;
}
