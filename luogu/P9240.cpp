#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findMax(vector<vector<int>> v){
    int max = 0;
    for(int i = 1; i < v.size(); ++i){
        if(v[i][0] >= v[max][0]){
            max = i;
        }
    }
    return v[max][0];
}
int findMin(vector<vector<int>> v){
    int min = 0;
    for(int i = 1; i < v.size(); ++i){
        if(v[i][0] <= v[min][0]){
            min = i;
        }
    }
    return v[min][0];
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for(int i = 0; i < n; ++i){
        cin >> v[i][0] >> v[i][1];
        v[i][0] = v[i][0] / v[i][1];
    }
    int max = findMax(v);
    int min = findMin(v);
    cout << min << " " << max << endl;
    return 0;
}