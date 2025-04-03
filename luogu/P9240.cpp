#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test(){
    long long n = 3;
    cin >> n;
    // vector<vector<int>> array{
    //     {75, 3},
    //     {53, 2},
    //     {59, 2}
    // };
    int max_temp = 0;
    vector<vector<int>> array(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        cin >> array[i][0] >> array[i][1];
        max_temp = array[i][0] > max_temp ? array[i][0]:max_temp;
    }
    vector<int> v;
    for(long long i = 2; i < max_temp; ++i){
        int count = 0;
        for(long long j = 0; j < n; ++j){
            if(array[j][0]/i == array[j][1]) ++count;
            else break;
        }
        if(count == n) v.push_back(i);
    }
    int temp = v.size()-1;
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[temp] << endl;
}

int main(){
    test();
    return 0;
}