#include <iostream>
#include <string>
using namespace std;

bool test(string s){
    for(int i = s.size()-1; i >= 0; --i){
        if(!(((s.size()-i)%2 == 1 && s[i] % 2 == 1) || ((s.size()-i)%2 == 0 && s[i]%2 == 0))) return false;
    }
    return true;
}
int main(){
    int n, count = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        string s = to_string(i);
        if(test(s)) ++count;
    }
    cout << count << endl;
    return 0;
}