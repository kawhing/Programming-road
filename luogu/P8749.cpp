#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, count = 0;
    cin >> n;
    int rows = n + 1;
    
    // 使用二维 vector 存储三角形
    vector<vector<int>> triangle(rows);
    
    for (int i = 0; i < rows; ++i) {
        triangle[i].resize(i + 1);
        // 每一行首尾均为 1
        triangle[i][0] = triangle[i][i] = 1;
        // 内部的数字为上一行左右两个数字之和
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    for (const auto &row : triangle) {
        for (const auto &num : row) {
            if(num == n){
                cout << count + 1 << endl;
                return 0;
            }
            ++count;
        }
    }
    
    return 0;
}