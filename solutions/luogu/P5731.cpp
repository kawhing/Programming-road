#include <iostream>
#include <iomanip> // 用于 setw
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> array(n, vector<int>(n));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            array[i][j] = 0;

    int count = 2;
    if(n == 1){
        cout << "  1" << endl;
        return 0;
    }
    array[0][0] = 1;
    int x = 0, y = 0;
    while(count <= n*n){
        // 向右
        while(y+1 < n && array[x][y+1] == 0){
            array[x][++y] = count++;
        }
        // 向下
        while(x+1 < n && array[x+1][y] == 0){
            array[++x][y] = count++;
        }
        // 向左
        while(y-1 >= 0 && array[x][y-1] == 0){
            array[x][--y] = count++;
        }
        // 向上
        while(x-1 >= 0 && array[x-1][y] == 0){
            array[--x][y] = count++;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setw(3) << array[i][j];
        }
        cout << endl;
    }
    return 0;
}