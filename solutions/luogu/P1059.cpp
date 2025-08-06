#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n), ans;
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; ++i){
        int count = 0;
        for(int j = 1+i; j < n; ++j){
            if(nums[j] != nums[i]) break;
            ++count;
        }
        ans.push_back(nums[i]);
        i += count;
    }
    cout << ans.size() << endl;
    cout << ans[0];
    for(int i = 1; i < ans.size(); ++i)
        cout << " " << ans[i];
}
int main(){
    solve();
    return 0;
}