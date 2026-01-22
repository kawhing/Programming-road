#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int hour = 0, minute = 0;
    if(d >= b){
        hour += c - a;
        minute += d - b;
    }else{
        hour += c - a - 1;
        minute = 60 - b + d;
    }
    cout << hour << " " << minute << endl;
}

int main(){
    solve();
    return 0;
}