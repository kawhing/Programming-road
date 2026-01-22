#include <bits/stdc++.h>
using namespace std;

void solve(){
    int s, v;
    cin >> s >> v;
    
    int minutes = s / v + ((s % v > 0) ? 1 : 0);
    minutes += 10;
    int hours[] = {8, 7, 6, 5, 4, 3, 2, 1, 0, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7};

    int index = 0;
    int hour = hours[index];
    while(minutes >= 60){
        index++;
        hour = hours[index];
        minutes -= 60;
    }
    if(minutes > 0){
        index++;
        hour = hours[index];
        minutes = 60 - minutes;
    }else
        minutes = 0;
    
    if(hour < 10) cout << "0";
    cout << hour << ":";
    if(minutes < 10) cout << "0";
    cout << minutes << endl;  
}
int main(){
    solve();
    return 0;
}