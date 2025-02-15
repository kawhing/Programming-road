#include <iostream>
using namespace std;

int main(){
    int count;
    float s, bu = 2;
    cin >> s;
    if(s <= 2){
        cout << 1 << endl;
        return 0;
    }
    s -= bu;
    for(count = 1; s > 0; ++count){
        bu *= 0.98;
        s -= bu;
        
    }
    cout << count << endl;
    return 0;
}