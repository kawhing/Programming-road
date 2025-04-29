#include <iostream>
#include <string>
using namespace std;

int getNum(string str){
    int num = 1;
    for(int i = 0; i < str.size(); ++i){
        num *= str[i] - 'A' + 1;
    }
    return num % 47;    
}
int main(){
    string star, team;
    cin >> star;
    cin >>team;
    if(getNum(star) == getNum(team)) cout << "GO" << endl;
    else cout << "STAY" << endl;

    return 0;
}