#include <bits/stdc++.h>
using namespace std;

bool isLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}
void solve(){
    int year = 2024, day = 0;
    do{
        day += 365;
        if(isLeapYear(year)) day++;
        year++;
        day %= 7;
    }while(year < 10000 && day % 7 != 0);
    cout << year+1 << endl;
}
int main(){
    solve();
    return 0;
}