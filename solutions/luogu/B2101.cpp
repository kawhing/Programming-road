#include <iostream>
#include <vector>
using namespace std;

void test(){
    int m, n, result = 0;
    cin >> m >> n;
    if(m == 1 && n == 1){
        cin >> m;
        cout << m << endl;
        return;
    }else if(m == 1 && n != 1){
        vector<int> array(n);
        for(int i = 0; i < n; ++i){
            cin >> array[i];
            result += array[i];
        }
        cout << result << endl;           
        return;
    }else if(n == 1 && m != 1){
        vector<int> array(m);
        for(int i = 0; i < m; ++i){
            cin >> array[i];
            result += array[i];
        }
        cout << result << endl;
        return;
    }
    result = 0;
    vector<vector<int>> array(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> array[i][j];
        }
    }
    for(int i = 0; i < n; ++i)
        result += array[0][i] + array[m-1][i];
    for(int i = 1; i < m-1; ++i)
        result += array[i][0] + array[i][n-1];
    cout << result << endl;
}

int main(){
    test();
    return 0;
}