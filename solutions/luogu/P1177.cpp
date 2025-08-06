#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    cout << nums[0];
    for(int i = 1; i < n; ++i)
        cout << " " << nums[i];
}
int main(){
    solve();
    return 0;
}