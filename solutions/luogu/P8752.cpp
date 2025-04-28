#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool test(int n){
    string str = to_string(n);
    if(str.length() < 4) return false; // 检查字符串长度是否小于4
    if((str[3] - '0') - (str[1] - '0') == 1 && str[0] == str[2]) return true; // 明确字符减法的意图
    return false;
}

int main(){
    vector<int> arr(5);
    for(int i = 0; i < 5; ++i){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 0; i < 5; ++i){
        if(test(arr[i])) ++count;
    }
    cout << count << endl;
    return 0;
}