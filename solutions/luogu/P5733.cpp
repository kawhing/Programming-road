#include <bits/stdc++.h>
using namespace std;
void solve(){
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] += 'A' - 'a';
        }
    }
    cout << str << endl;
}
int main(){
    solve();
    return 0;
}