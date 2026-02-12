#include <bits/stdc++.h>
using namespace std;

void solve(){
   double m, h, bmi;
    cin >> m >> h;
    bmi = m / (h * h);
    if(bmi < 18.5)
        cout << "Underweight\n";
    else if(bmi >= 18.5 && bmi < 24)
        cout << "Normal\n";
    else{
        cout << bmi << endl;
        cout << "Overweight\n";
    }
}
int main(){
    solve();
    return 0;
}