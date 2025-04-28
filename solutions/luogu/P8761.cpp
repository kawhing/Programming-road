#include <iostream>
#include <string>
using namespace std;

bool is_litter_alpha(char c){
    return c >= 'a' && c <= 'z';
}
int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(is_litter_alpha(s[i])) s[i] = s[i] - 'a' + 'A';
    }
    cout << s << endl;
    return 0;
}