#include <iostream>
#include <vector>
#include <string>
using namespace std;

void tongji(int n, vector<int> &nums){
    string s = to_string(n);
    for(int i = 0; i < 10; ++i)
        ++nums[s[i]-'0'];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> nums(10, 0);
    for(int i = m; i <= n; ++i)
        tongji(i, nums);    
    for(int i = 0; i < 10; ++i)
        cout << nums[i] << " ";
    return 0;
}