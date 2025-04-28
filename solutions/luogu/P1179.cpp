#include <iostream>
using namespace std;

int main(){
    int count = 0;
    int L, R;
    cin >> L >> R;
    for(int i = L; i <= R; ++i){
        string temp = to_string(i);
        for(int j = 0; j < temp.size(); ++j){
            if(temp[j] == '2') ++count;
        }
    }
    cout << count << endl;
    return 0;
}