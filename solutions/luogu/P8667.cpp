#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//[蓝桥杯 2018 省 B] 递增三元组 
//使用了AI辅助，但是已经理解算法的思路
void solve(){
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);
    
    for(int i = 0; i < n; ++i) cin >> A[i];
    for(int i = 0; i < n; ++i) cin >> B[i];
    for(int i = 0; i < n; ++i) cin >> C[i];
    
    // 对三个数组排序
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    
    long long result = 0;
    
    // 对于每个B[j]，计算符合条件的三元组数量
    for(int j = 0; j < n; ++j){
        // 计算A中小于B[j]的元素个数
        long long countA = upper_bound(A.begin(), A.end(), B[j]-1) - A.begin();
        
        // 计算C中大于B[j]的元素个数
        long long countC = C.end() - lower_bound(C.begin(), C.end(), B[j]+1);
        
        // 将两个计数相乘，累加到结果中
        result += countA * countC;
    }
    
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}