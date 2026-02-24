#include <bits/stdc++.h>
using namespace std;

string str;
string rightISBN(int nums[]){
    string right = str;
    int sum = 0;
    for(int i = 0; i < 9; ++i)
        sum += (nums[i] - '0') * (i + 1);
    if(sum % 11 == 10)
        right[12] = 'X';
    else
        right[12] = sum % 11 + '0';
    return right;
}

void solve(){
    cin >> str;
    int nums[9] = {str[0], str[2], str[3], str[4], str[6], str[7], str[8], str[9], str[10]};
    string right = rightISBN(nums);

    if(str == right)
        cout << "Right" << endl;
    else
        cout << right << endl;
}

int main(){
    solve();
    return 0;
}