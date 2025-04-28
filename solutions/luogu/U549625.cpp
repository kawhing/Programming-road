#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void test(){
	ll n;
	cin >> n;
	vector<ll> nums(n), result(n);
	for(ll i = 0; i < n; ++i)
		cin >> nums[i];
	
	vector<ll> endingAtLeft(n);
	ll currentSum = 0; 
	for(ll i = 0; i < n; ++i){
		currentSum = max(nums[i]+currentSum, nums[i]);
		endingAtLeft[i] = currentSum;
	}
	
	vector<ll> startingAtRight(n);
	currentSum = 0;
	for(ll i = n-1; i >= 0; --i){
		currentSum = max(nums[i]+currentSum, nums[i]);
		startingAtRight[i] = currentSum;
	}
	for(ll i = 0; i < n; ++i){
		ll left = 0, right = 0;
		if(i > 0)
			left = max(0LL, endingAtLeft[i-1]);
		if(i < n-1)
			right = max(0LL, startingAtRight[i+1]);
		result[i] = nums[i] + left + right;
	}
	cout << result[0];
	for(ll i = 1; i < n; ++i)
		cout <<  " " << result[i];
} 
int main(){
	test();
	return 0;
}