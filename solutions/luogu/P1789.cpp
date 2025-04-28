#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        arr[a-1][b-1] = 1;
    }
    
    if(k) {
        for(int i = 0; i < k; ++i){
            int a, b;
            cin >> a >> b;
            arr[a-1][b-1] = 2;
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 1){
                for(int k = 0; k < n; ++k){
                    if(arr[j][k] != 2 && arr[j][k] != 1){
                        arr[j][k] = 3;
                    }
                }
                for(int k = 0; k < n; ++k)
                    if(arr[k][j] != 2 && arr[k][j] != 1){
                        arr[k][j] = 3;
                    }
                for(int m = ((i - 1) < 0 ? 0 : i - 1); m <= ((i + 1 >= n) ? n - 1 : i + 1); ++m){
                    for(int l = ((j - 1) < 0 ? 0 : j - 1); l <= ((j + 1 >= n) ? n - 1 : j + 1); ++l){
                        if(arr[m][l] != 1 && arr[m][l] != 2){
                            arr[m][l] = 3;
                        }
                    }
                }
            }else if(arr[i][j] == 2){
                for(int m = ((i - 2) < 0 ? 0 : i - 2); m <= ((i+2 >= n) ? n-1 : i+2); ++m){
                    for(int l = ((j - 2) < 0 ? 0 : j - 2); l <= ((j+2 >= n) ? n-1 : j+2); ++l){
                        if(arr[m][l] != 1 && arr[m][l] != 2){
                            arr[m][l] = 3;
                        }
                    }
                }
            }
        }
    }

    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[i][j] == 0) ++count;
            //cout << arr[i][j] << " ";
        }
        //cout << endl;
    }
    cout << count << endl;
    return 0;
}