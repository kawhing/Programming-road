#include <bits/stdc++.h>
using namespace std;

void solve(){
    string line = "", temp;
    // 读取输入直到遇到'E'
    while(cin >> temp) {
        bool foundEnd = false;
        for(char c : temp) {
            if(c == 'E') {
                foundEnd = true;
                break;
            }
            line += c;
        }
        if(foundEnd) break;
    }
    if(line.size() == 0){
        cout << "0:0" << endl << endl << "0:0";
        return;
    }
    int score_w = 0, score_l = 0;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == 'W') ++score_w;
        else ++score_l;
        if(max(score_w, score_l) >= 11 && abs(score_w - score_l) >= 2){
            cout << score_w << ":" << score_l << endl;
            score_l = score_w = 0;
        }
    }
    cout << score_w << ":" << score_l << endl;
    cout << endl;

    score_w = 0, score_l = 0;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == 'W') ++score_w;
        else ++score_l;
        if(max(score_w, score_l) >= 21 && abs(score_w - score_l) >= 2){
            cout << score_w << ":" << score_l << endl;
            score_l = score_w = 0;
        }
    }
    cout << score_w << ":" << score_l << endl;
}
int main(){
    solve();
    return 0;
}