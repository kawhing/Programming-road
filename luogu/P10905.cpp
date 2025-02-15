#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isHuiwen(string s){
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

string isCould(string s){
    if(isHuiwen(s)) return "YES";
    vector<char> array;
    for(int i = s.size() - 1; i >=  0; --i){
        if(s[i] == 'l' || s[i] == 'q' || s[i] == 'b') array.push_back(s[i]);
    }
    s = string(array.begin(), array.end()) + s;
    if(isHuiwen(s)) return "YES";
    else return "NO";
}
int main(){
    int n;
    cin >> n;
    vector<string> v(n);// = {"gmgqlq", "pdlbll", "aaa"};
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < v.size(); ++i) cout << isCould(v[i]) << endl;
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isHuiwen(string s){
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}

string isCould(string s){
    // 如果 S 本身是回文，直接返回 "YES"
    if(isHuiwen(s)) return "YES";
    int n = s.size();
    // 若整个 s 都由允许字符构成，则空串是回文，可以在前面加上 reverse(s)
    bool allAllowed = true;
    for (char c : s) {
        if(c != 'l' && c != 'q' && c != 'b'){
            allAllowed = false;
            break;
        }
    }
    if(allAllowed) return "YES";
    // 枚举分割点 L, 1 <= L < n，
    // 使得 s[0...L-1] 为回文串且 s[L...n-1] 都为允许字符
    for(int L = 1; L < n; ++L){
        if(isHuiwen(s.substr(0, L))){
            bool allowed = true;
            for(int i = L; i < n; ++i){
                if(s[i] != 'l' && s[i] != 'q' && s[i] != 'b'){
                    allowed = false;
                    break;
                }
            }
            if(allowed) return "YES";
        }
    }
    return "NO";
}

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; ++i) 
        cin >> v[i];
    for(int i = 0; i < v.size(); ++i) 
        cout << isCould(v[i]) << endl;
    return 0;
}
*/