#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string to_Ten(int m, string num){
    int numSize = num.size();
    string count;
    for(int i = 0; i < numSize; ++i){
        if(num[i] != '0'){
            if(i == 0) count += string(1, num[i]) + "*" + to_string(m) + "^" + to_string(numSize-i-1);
            else{
                count += "+" + string(1, num[i]) + "*" + to_string(m) + "^" + to_string(numSize-i-1);
            }
        }
    }
    return count;
}

int main(){
    int m;
    string n;
    cin >> m >> n;
    cout << to_Ten(m, n) << endl;
    return 0;   
}