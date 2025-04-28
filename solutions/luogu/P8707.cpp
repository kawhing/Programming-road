#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n+1, vector<int>(m+1, 0));
    matrix[1][1] = 1;
    int route = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if ((i == 1 && j == 1) || (i % 2 == 0 && j % 2 == 0)) {
                continue;
            }
            if(i > 1) matrix[i][j] += matrix[i-1][j];
            if(j > 1) matrix[i][j] += matrix[i][j-1];
        }
    }  
    cout << matrix[n][m] << endl;
    return 0;
}