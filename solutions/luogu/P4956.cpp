#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool compare(vector<int> &a, vector<int> b){
    if(a[0] > b[0]) return true;
    else if(a[0] == b[0] && a[1] < b[1]) return true;
    return false;
}
void solve(){
    int n, x, k;
    cin >> n;
    vector<vector<int>> ans;
    for(x = 1; x <= 100;++x){
        for(k = 1; ; ++k){
            int sum = 0;
            for(int i = 0; i < 7; ++i) sum += x + i * k;
            sum *= 52;
            if(sum == n){
                ans.push_back({x, k});
            }else if(sum > n){
                break;
            }
        }
    }
    sort(ans.begin(), ans.end(), compare);
    cout << ans[0][0] << endl << ans[0][1];
    
}
int main(){
    solve();
    return 0;
}