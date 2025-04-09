#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int n, k;
ll result = 0;
vector<ll> nums;
vector<bool> selected;
bool suNum(ll num) {
    if(num < 2) return false;
    for(int i = 2; i*i <= num; ++i){
        if(num % i == 0) return false;
    }
    return true;
}
void dfs(ll index, ll selectNum, ll sum) {
    if(selectNum == k){
    	if(suNum(sum)) ++result;
    	return;
	}
	if(n+sum < k+index) return;
	
	if(index < n){
		selected[index] = true;
		dfs(index+1, selectNum+1, sum+nums[index]);
		selected[index] = false;//回溯 
		dfs(index+1, selectNum, sum);
	}
}

int main() {
	cin >> n >> k;
	nums.resize(n);
	selected.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> nums[i];
		selected[i] = false;
	}
	dfs(0, 0, 0);
	cout << result << endl;
    return 0;
}