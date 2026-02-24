#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int sum = a + b + c;
    int maxNum = max(a, max(b, c));
    int minNum = min(a, min(b, c));
    int middleNum = sum - minNum - maxNum;
    if(minNum + middleNum <= maxNum){
        cout << "Not triangle" << endl;
        return;
    }
   
    int target = minNum * minNum + middleNum * middleNum - maxNum * maxNum;
    if(target > 0)
        cout << "Acute triangle" << endl;
    else if(target == 0)
        cout << "Right triangle" << endl;
    else if(target < 0)
        cout << "Obtuse triangle" << endl;
    if(minNum == middleNum || middleNum == maxNum)
        cout << "Isosceles triangle" << endl;
    if(a == b && c == b)
        cout << "Equilateral triangle" << endl;
    
}

int main(){
    solve();
    return 0;
}