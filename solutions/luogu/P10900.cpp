#include <iostream>
#include <vector>
using namespace std;

//由claude 3.7 sonnet优化

// 判断一个数是否具有诗意（可以表示为至少两个连续正整数的和）
bool isShiYi(long long num) {
    // 特殊情况：1不能表示为至少两个正整数的和
    if (num == 1) return false;
    
    // 判断是否是2的幂：如果不是2的幂，则具有诗意
    // 使用位运算：如果n是2的幂，那么n & (n-1) = 0
    return (num & (num - 1)) != 0;
}

void test() {
    long long n;
    cin >> n;
    
    vector<long long> nums(n);
    for(long long i = 0; i < n; ++i)
        cin >> nums[i];
    
    long long deleteCount = 0;
    for(long long i = 0; i < n; ++i) {
        if(!isShiYi(nums[i])) {
            deleteCount++; // 计数需要删除的数字
        }
    }
    
    cout << deleteCount << endl;
}

int main() {
    test();
    return 0;
}