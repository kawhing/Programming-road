#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool isPassword(string s){
    if(!(s.size() >= 8 && s.size() <= 16)) return false;
    bool haveDigit = false, haveSymbol = false;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] >= '0' && s[i] <= '9') haveDigit = true;
        else if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) haveSymbol = true;
        if(haveDigit && haveSymbol) return true;
    }
    return false;
}

int main(){
    string s = {"kfdhtshmrw4nxg#f44ehlbn33ccto#mwfn2waebry#3qd1ubwyhcyuavuajb#vyecsycuzsmwp31ipzah#catatja3kaqbcss2th"};
    int count = 0;
    for(int i = 0; i < s.size() - 7; ++i){
        for(int j = 8; j <= 16; ++j){
            if(isPassword(s.substr(i, j))){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}