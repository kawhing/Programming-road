#include <bits/stdc++.h>
using namespace std;
void solve(){
    int num;
    cin >> num;
    vector<int> nums;
    nums.push_back(num);
    while(num != 1){
        if(num % 2 == 0){
            num /= 2;
        }else{
            num = num * 3 + 1;
        }
        nums.push_back(num);
    }
    for(int i = nums.size()-1; i >= 0; --i) cout << nums[i] << " ";
}
int main(){
    solve();
    return 0; 
}