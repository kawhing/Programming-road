#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    vector<ll> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    for(ll i = 2; i*i < max(nums[0], nums[2]); ++i){
        if(nums[0] % i == 0 && nums[2] % i == 0){
            nums[0] /= i;
            nums[2] /= i;
            break;
        }
    }
    cout << nums[0] << "/" << nums[2];
}
int main(){
    solve();
    return 0;
}