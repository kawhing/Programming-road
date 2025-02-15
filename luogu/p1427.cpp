#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<int> data;
    int input;
    while(cin >> input && input != 0)
        data.push_back(input);

    for(int i = data.size()-1; i >= 0; --i){
        cout << data[i] << " ";
    }
    return 0;
}