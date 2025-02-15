#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> pretree(n*3-2, vector<int>(n, 0));
    vector<vector<int>> endtree(n*3-2, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        if(i == 0){
            for(int j = 0; j < n; ++j){
                pretree[i][j] = 1;
                endtree[i][j] = 1;
            }
            endtree[0][0] = 0;
        }else{
            for(int j = 0; j < n; ++j){
                pretree[i][j] = endtree[i-1][j] + 1;
                endtree[i][j] = pretree[i][j];
            }
            endtree[i][n-(i+1)%n] = 0;
        }
    } 
    for(int i = n; i < 2*n-1; ++i){
        for(int j = 0; j < n; ++j){
            pretree[i][j] = endtree[i-1][j] + 1;
            endtree[i][j] = pretree[i][j];
        }
        endtree[i][i] = 0;
    }
    for(int i = 2*n-1; i < 3*n-2; ++i){
        for(int j = 0; j < n; ++j){
            pretree[i][j] = endtree[i-1][j] + 1;
            endtree[i][j] = pretree[i][j];
        }
        endtree[i][(i-1)%3] = 0;
    }  
    for(int i = 0; i < n*3-2; ++i){
        for(int j = 0; j < n; ++j){
            cout << pretree[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}