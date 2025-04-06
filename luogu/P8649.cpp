#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long sum(vector<long long> nums, long long start, long long end){
	long long sum = 0;
	for(long long i = start; i <= end; ++i){
		sum += nums[i];
	}
	return sum;
}
void test(){
	long long n, k, k_spaces = 0;
	cin >> n >> k;
	vector<long long> nums(n);
	for(long long i = 0; i < n; ++i){
		cin >> nums[i];
	}
	for(long long i = 0; i < n; ++i){
		for(long long j = i; j < n; ++j){
			if(sum(nums, i, j) % k == 0){
				++k_spaces;
			}
		}
	}
	cout << k_spaces << endl;
} 
int main(){
	test();
	return 0;
}