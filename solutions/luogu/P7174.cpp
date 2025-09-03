#include <bits/stdc++.h>
using namespace std;

void solve(){
    string num;
    cin >> num;
    bool zf = false;
    for(char c : num){
        if(c == '0') zf = true;
    }
    if(!zf){
        cout << -1 << endl;
        return;
    }
    int sum = 0;
    for(char c : num) sum += c-'0';
    if(sum % 3 == 0){
        sort(num.rbegin(), num.rend());
        cout << num << endl;
    }else{
        cout << -1 << endl;
    }
}
int main(){
    solve();
    return 0;
}