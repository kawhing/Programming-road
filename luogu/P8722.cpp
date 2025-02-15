#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_alpha(char c){
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool is_digit(char c){
    return c >= '0' && c <= '9';
}

int main(){
    vector<string> month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string s, s1 = "", s2 = "";
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(is_alpha(s[i])) s1 += s[i];
        else if(is_digit(s[i])) s2 += s[i];
    }

    for(int i = 0; i < month.size(); ++i){
        if(s1 == month[i]){
            int num = stoi(s2);
            cout << i + 1 << " " << num << endl;
            break;
        }
    }
    return 0;
}