#include <iostream>
#include <vector>
#include <string>
using namespace std;


string changeToP(int n, int p){
    vector<char> v;
    while(n / p){
        v.push_back(n % p + '0');
        n /= p;
    }
    v.push_back(n % p + '0');
    for(int i = 0; i < v.size() / 2; ++i){
        swap(v[i], v[v.size() - i - 1]);
    }
    if(p > 10){
        for(int i = 0; i < v.size(); ++i){
            if(v[i] - '0' >= 10) v[i] += 'A' - '0' - 10;
        }
    }
    return string(v.begin(), v.end());
}

int main(){
    int p;
    cin >> p;
    for(int i = 1; i < p; ++i){
        for(int j = 1; j <= i; ++j){
            if(j == i) cout << changeToP(i, p) << "*" << changeToP(j, p) << "=" << changeToP(i * j, p);
            else cout << changeToP(i, p) << "*" << changeToP(j, p) << "=" << changeToP(i * j, p) << " ";
        }
        cout << endl;
    }
    
    return 0;
}