#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// 日志统计
//时间复杂度较高，只能通过部分测试案例
void test(){
    long long n, d, k;
    cin >> n >> d >> k;
    //n = 7, d = 10, k = 2;  
    vector<vector<long long>> array(n, vector<long long>(2));
    // array = {
    //     {0, 1},
    //     {0, 10},
    //     {10, 10},
    //     {10, 1},
    //     {9, 1},
    //     {100, 3},
    //     {100, 3}
    // };
    for(long long i = 0; i < n; ++i)
        for(long long j = 0; j < 2; ++j)
            cin >> array[i][j];
    vector<vector<long long>> tip;
    vector<long long> hot;
    for(long long i = 0; i < n; ++i){
        
        long long temp_k = 1;
        for(long long j = i+1; j < n; ++j){
            if(array[j][1] == array[i][1]){
                if(abs(array[j][0]-array[i][0]) < d){// limit time not out time d
                    ++temp_k;
                }
            }
        }
        if(temp_k >= k) hot.push_back(array[i][1]);
    }
    sort(hot.begin(), hot.end());
    long long hotSize = hot.size();
    for(long long i = 0; i < hot.size(); ++i){
        if(i != 0 && hot[i] == hot[i-1]) continue;
        cout << hot[i] << endl;
    }
    
}
int main(){
    test();
    return 0;
}