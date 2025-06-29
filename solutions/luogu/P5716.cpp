#include <bits/stdc++.h>
using namespace std;

bool isRun(int year){
    return (year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0);
}
void solve(){
    int year,  month;
    cin >> year >> month;
    if(isRun(year)){
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            cout << 31 << endl;
        }else if(month == 2){
            cout << 29 << endl;
        }else{
            cout << 30 << endl;
        }
    }else{
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
            cout << 31 << endl;
        }else if(month == 2){
            cout << 28 << endl;
        }else{
            cout << 30 << endl;
        }
    }
}
int main(){
    solve();
    return 0;
}