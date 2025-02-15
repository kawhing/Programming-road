#include <iostream>
#include <string>
using namespace std;

bool is_digit(char c){
    return c >= '0' && c <= '9';
}   

bool is_alpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(){
    string s, t = "";
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(is_alpha(s[i])){
            if(i < s.size()-1 && is_digit(s[i+1])){
                for(int l = 0; l < s[i+1]-'0'; ++l){
                    t += s[i];
                }
            }else{
                t += s[i];
            }
        }
    }
    cout << t << endl;
    return 0;
}