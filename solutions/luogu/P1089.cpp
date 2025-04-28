#include <iostream>
using namespace std;


int main(){
    int budget[12];
    for(int i = 0; i < 12; ++i){
        cin >> budget[i];
    }
    int money = 0, save = 0;
    for(int i = 0; i < 12; ++i){
        money += 300 - budget[i];
        if(money / 100){
            save += money / 100 * 100;
            money %= 100;
        }
        if(money < 0){
            cout << "-" << i+1 << endl;
            return 0;
        }
    }
    cout << money + save * 1.2 << endl;

    return 0;
}