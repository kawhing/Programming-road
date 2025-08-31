#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c){//是否元音
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
void solve(){
    string str, ans = "";
    getline(cin, str);
    int strSize = str.size();
    for(int i = 0; i < strSize; ++i){
        if(!isVowel(str[i])){
            ans.push_back(str[i]);
        }else{
            ans.push_back(str[i]);
            i += 2;
        }

    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}