#include <iostream>
#include <vector>
using namespace std;

bool isShiYI(long long num){
    for(int i = 1; i < num; ++i){
        long long sum = 0;
        for(long long j = 1; j < num; ++j){
            sum += j;
            if(sum == num && j-i >= 1) return true;
            else if(sum > num || (sum == num && j == i)) continue; 
        }
    }
    return false;
}

void test(){
    long long n;
    cin >> n;
    vector<long long> nums(n);
    for(long long i = 0; i < n; ++i)
        cin >> nums[i];
    long long sum = n;
    for(long long i = 0; i < n; ++i){
        if(isShiYI(nums[i])) --sum;
    }
    cout << sum << endl;
}

int main(){
    test();
    //cout << isShiYI(8);
    return 0;
}