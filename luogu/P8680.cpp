#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool test(string str){
    for(int i = 0; i < str.size(); ++i){
        if((str[i] == '0' && i != 0) || str[i] == '2' || str[i] == '1' || str[i] == '9') return true;
    }
    return false;
}

int main(){
    int n, count = 0;
    cin >> n;
    for(int i = 0; i <= n; ++i){
        string temp = to_string(i);
        if(test(temp)) count += i;
    }
    cout << count << endl;
    return 0;
}