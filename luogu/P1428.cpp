#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i = 0; i < n; ++i){
        cin >> data[i];
    }
    vector<int> result(n, 0);
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j)
            if(data[j] < data[i]) ++result[i];
    }
    for(int i = 0; i < n; ++i){
        cout << result[i] << " ";
    }

    return 0;
}