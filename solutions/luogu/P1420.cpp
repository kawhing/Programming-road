#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, ans = 0;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    for(int i = 0; i < n-1; ++i){
        int temp = 1;
        for(int j = i+1; j < n; ++j){
            if(nums[j]-nums[j-1] == 1) ++ temp;
            else break;
        }
        ans = max(temp, ans);
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}