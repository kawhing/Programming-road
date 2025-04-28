#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string str;
    cin >> str;
    stack<char> s;
    for(char c : str){
        if(c == '@') break;
        if(c == '(') s.push(c);
        else if(c == ')'){
            if(s.empty()){
                cout << "NO";
                return 0;
            }
            s.pop();
        }
    }
    if(s.empty()) cout << "YES";
    else cout << "NO";
    return 0;
}