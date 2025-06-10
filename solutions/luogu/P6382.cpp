#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    string str;
    cin >> str;
    string city, code;
    city = str.substr(0, 3);
    int end;
    for(ll i = str.size()-1; i >= 3; --i){
        if(str[i] >= '0' && str[i] <= '9'){
            end = str[i]-'0';
            break;
        }
    }
    if(city != "MDA"){
        cout << "1 1 1 1 1";
        return;
    }
    cout << ((end == 1) || (end == 9)) << " ";
    cout << ((end == 2) || (end == 8)) << " ";
    cout << ((end == 3) || (end == 7)) << " ";
    cout << ((end == 4) || (end == 6)) << " ";
    cout << ((end == 5) || (end == 0)) << endl;
}
int main(){
    solve();
    return 0;
}