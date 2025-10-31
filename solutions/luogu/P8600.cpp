#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    for(int i = 0; i < n; ++i){
        int minNum = nums[i], maxNum = nums[i];
        for(int j = i; j < n; ++j){
            minNum =min(minNum, nums[j]);
            maxNum = max(maxNum, nums[j]);
            if(maxNum - minNum == j - i) ans++;
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}