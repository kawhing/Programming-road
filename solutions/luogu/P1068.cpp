#include <bits/stdc++.h>
using namespace std;

struct Contestant{
    int k, s;
};

bool compare(Contestant v1, Contestant v2){
    if(v1.s == v2.s) return v1.k < v2.k;
    return v1.s > v2.s;
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector<Contestant> contestants(n);
    for(int i = 0; i < n; ++i)
        cin >> contestants[i].k >> contestants[i].s;
    sort(contestants.begin(), contestants.end(), compare);
    int index = floor(m * 1.5);
    int score = contestants[index-1].s;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (contestants[i].s >= score) count++;
        else break;
    }
    cout << score << " " << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << contestants[i].k << " " << contestants[i].s << endl;
    }
}
int main(){
    solve();
    return 0;
}