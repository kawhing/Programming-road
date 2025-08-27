#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b;
    cin >> a >> b;
    string aStr = to_string(a), bStr = to_string(b), temp = "";
    for(int i = aStr.size()-1; i >= 0; --i) temp.push_back(aStr[i]);
    a = stoi(temp);
    temp = "";
    for(int i = bStr.size()-1; i >= 0; --i) temp.push_back(bStr[i]);
    b = stoi(temp);
    cout << max(a, b) << endl;
}
int main(){
    solve();
    return 0;
}