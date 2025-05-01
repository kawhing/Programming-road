#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(string name, ll age, ll score){
    score += score*0.2;
    if(score > 600) score = 600;
    cout << name << " " << age+1 << " " << score << endl;
}
int main(){
    ll n;
    cin >> n;
    while(n--){
        string name;
        ll age, score;
        cin >> name >> age >> score;
        solve(name, age, score);
    }
    return 0;
}