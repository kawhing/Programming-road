#include <iostream>
#include <string>
#include <vector>
using namespace std;
//小杨的H字矩阵

int main(){
    int n;
    cin >> n;
    vector<vector<char>> H(n, vector<char>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == 0 || j == n - 1){
                H[i][j] = '|';
            }else if( i == n / 2){
                H[i][j] = '-';
            }else{
                H[i][j] = 'a';
            }
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << H[i][j];
        }
        cout << endl;
    }
    return 0;
}