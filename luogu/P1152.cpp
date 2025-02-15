#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n = 0;
    vector<int> arr(n);
    bool flag = false;
    for(int i = 0; i < n+1; ++i){
        if(!flag){
            cin >> n;
            arr.resize(n);
            flag = true;
        }else{
            cin >> arr[i-1]; 
        }
    }
    vector<int> result(n-1);
    for(int i = 0; i < n-1; ++i){
        int temp = arr[i+1] - arr[i];
        if(temp > 0) result[i] = temp;
        else result[i] = -1*temp;
    }
    for(int i = 0; i < n-1; ++i){
        if(result[i] < 1 || result[i] > n-1){
            cout << "Not jolly" << endl;
            return 0;
        }
    }
    cout << "Jolly" << endl;
    return 0;
}