#include <iostream>
#include <vector>
using namespace std;

vector<int> test(int num){
    vector<int> result(3);
    result[0] = num / 100;
    result[1] = (num / 10) % 1000;
    result[2] = num % 1000; 
    return result;
}
int main(){
    int K;
    bool flag = false;
    cin >> K;
    for(int i = 10000; i <= 30000; ++i){
        vector<int> result = test(i);
        if(result.size()){
            if(result[0] % K == 0 && result[1] % K == 0 && result[2] % K == 0){
                cout << i << endl;
                flag = true;
            }
                
        }
    }              
    if(!flag) cout << "No" << endl;
    return 0;
}