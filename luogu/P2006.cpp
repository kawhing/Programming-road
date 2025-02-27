#include <iostream>
#include <vector>
using namespace std;

bool isCouldKill(int k, int a , int b, int n){//k 法力值, a 消耗, b 伤害, n boss体力值
    if((k/a)*b >= n) return true;
    return false;
}

void test(){
    int k, m, n;//k 法力值, m 技能数, n boss体力值
    cin >> k >> m >> n;
    vector<vector<int>> skill(m, vector<int>(2));
    vector<int> Kill;
    for(int i = 0; i < m; ++i){
        cin >> skill[i][0] >> skill[i][1];
        if(isCouldKill(k, skill[i][0], skill[i][1], n)) Kill.push_back(i+1);
    }
    if(Kill.size())
        for(int i = 0; i < Kill.size(); ++i){
            if(i > 0) cout << " ";
            cout << Kill[i];
    }else cout << -1 << endl;
}

int main(){
    test();
    return 0;
}