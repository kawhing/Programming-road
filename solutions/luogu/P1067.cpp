#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i = 0; i <= n; ++i) cin >> nums[i];
    
    bool first = true;
    
    if(nums[0]) {
        if(nums[0] == 1 && n > 0) cout << "x^" << n;
        else if(nums[0] == -1 && n > 0) cout << "-x^" << n;
        else if(n > 0) cout << nums[0] << "x^" << n;
        else cout << nums[0];
        first = false;
    }
    
    for(int i = 1; i <= n; ++i){
        if(i == n){
            if(nums[i] > 0 && !first) cout << "+" << nums[i];
            else if(nums[i] > 0 && first) cout << nums[i];
            else if(nums[i] < 0) cout << nums[i];
        }else{
            if(nums[i]){
                if(nums[i] == 1) cout << (first ? "" : "+");
                else if(nums[i] > 0) cout << (first ? "" : "+") << nums[i];
                else if(nums[i] == -1) cout << "-";
                else if(nums[i] < 0) cout << nums[i];
                if(n-i == 1) cout << "x";
                else cout << "x^" << n-i;
                
                first = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}