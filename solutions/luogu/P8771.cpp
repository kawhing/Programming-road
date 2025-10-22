#include <bits/stdc++.h>
using namespace std;

void problemA(){
    int ans = 0;
    string s = "2022";
    int pow9 = 1;
    for(int i = 0; i < s.size(); ++i){
        if(i != 0)
            pow9 *= 9;
        ans += (s[s.size()-i-1]-'0') * pow9;
                
    }
    cout << ans;
}

bool isDate(string s){
    if(s.size() == 3){
        if(s[0] == '1' || s[0] == '3' || s[0] == '5' || s[0] == '7' || s[0] == '8'){
            if((s[1]-'0')*10 + (s[2]-'0') >= 1 && (s[1]-'0')*10 + (s[2]-'0') <= 31) return true;
        }else if(s[0] == '2'){
            if((s[1]-'0')*10 + (s[2]-'0') >= 1 && (s[1]-'0')*10 + (s[2]-'0') <= 28) return true;
        }else if(s[0] == '4' || s[0] == '6' || s[0] == '9'){
            if((s[1]-'0')*10 + (s[2]-'0') >= 1 && (s[1]-'0')*10 + (s[2]-'0') <= 30) return true;
        }
    }else if(s.size() == 4){
        if(s[0] == '1'){
            if(s[1] == '0' || s[1] == '2'){
                if((s[2]-'0')*10 + (s[3]-'0') <= 31 && (s[2]-'0')*10 + (s[3]-'0') >= 1) return true;
            }else if(s[1] == '1'){
                if((s[2]-'0')*10 + (s[3]-'0') <= 30 && (s[2]-'0')*10 + (s[3]-'0') >= 1) return true;
            }
        }       
    }
    return false;
}
void problemB(){
    int ans = 0;
    for(int i = 1; i <= 1231; ++i){
        string s = to_string(i);
        if(!isDate(s)) continue;
        bool isValid = false;
        if(s.size() == 3){
            s = "0" + s;
        }
        if(s.size() == 4){
            if((s[1] - s[0] == 1 && s[2] - s[1] == 1) || s[2] - s[1] == 1 && s[3] - s[2] == 1)
                isValid = true;
        }
        if(isValid)
            ++ans;
    }
    cout << ans << endl;
}

void solve(){
    char c;
    cin >> c;
    if(c == 'A') problemA();
    else if(c == 'B') problemB();
}

int main(){
    solve();
    return 0;
}