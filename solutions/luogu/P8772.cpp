#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    long long sum = 0, sumSq = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
        sumSq += (long long)v[i] * v[i];
    }
    long long result = (sum * sum - sumSq) / 2;
    cout << result << endl;
    return 0;
}