#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> weather(N);
    for(int i = 0; i < N; ++i) cin >> weather[i];
    if(N == 1) {
        cout << "0" << endl;
        return 0;
    }else if(N == 2){
        if(weather[0] < weather[1]){
            cout << "2" <<endl;
            return 0;
        }
    }   
    int result = 0;
    for(int i = 0; i < N-1; ++i){
        if(weather[i] < weather[i+1]){
            int temp = 2;
            for(int j = i+1; j < N-1; ++j){
                if(weather[j] < weather[j+1]) ++temp;
                else break;
            }
            if(result < temp) result = temp;
        }
    }
    cout << result << endl;
    return 0;
}