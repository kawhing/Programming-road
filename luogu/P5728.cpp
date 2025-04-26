#include <bits/stdc++.h>
using namespace std;

void solove(){
    int a, b, f;
    char c;
    cin >> a >> b >> c >> f;
    if(f == 0){
        for(int i = 0; i < a; ++i){
            if(i == 0 || i == a-1){
                for(int j = 0; j < b; ++j) cout << c;
                cout << endl;
            }else{
                cout << c << ' ' << c;
                for(int j = 2; j < b; ++j){
                    cout << ' ';
                }
                cout << endl;
            }

        }
    }else{
        for(int i = 0; i < a; ++i){
            for(int j = 0; j < b; ++j){
                cout << c;
            }
            cout << endl;
        }
    }
}
int main(){
    solove();
    return 0;
}