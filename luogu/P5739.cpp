#include <iostream>
using namespace std;
// try to do not use "for" or "while"

int jiecheng(int n){
    if(n == 1) return 1;
    return n * jiecheng(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << jiecheng(n);
    return 0;
}