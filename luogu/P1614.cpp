#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    
    int min_sum = INT_MAX;
    for(int i = 0; i <= n - m; ++i){
        int current_sum = 0;
        for(int j = 0; j < m; ++j){
            current_sum += arr[i + j];
        }
        if(current_sum < min_sum)
            min_sum = current_sum;
    }
    
    cout << min_sum << endl;
    return 0;
}