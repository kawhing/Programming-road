#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int num = n*n;
    for(int i = 1; i <= num; ++i){
        if(i < 10) cout << 0 << i;
        else cout << i;
        if(i%n == 0) cout << endl;
    }
    cout << endl;

    int count = 1;
    for(int i = 1; i <= n; ++i){
        int x = n - i;
        for(int j = 0; j < x; ++j) cout << "  ";
        for(int j = 0; j < i; ++j) {
            if(count < 10) cout << 0 << count++;
            else cout << count++;
        }
        cout << endl;
    }
    return 0;
}