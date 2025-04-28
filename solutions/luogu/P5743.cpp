#include <iostream>
using namespace std;

int main(){
    int n, num = 1;
    cin >> n;//第n天
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = n-1; i >= 1; --i){
        num = (num+1)*2;
    }
    cout << num << endl;
    return 0;
}