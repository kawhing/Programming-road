#include <iostream>
using namespace std;

int test(int* classTime){
    int max = 0;
    for(int i = 0; i < 7; ++i){
        if(classTime[i] > classTime[max]){
            max = i;
        }
    }
    return max;
}

int main(){
    int classTime[7];
    for(int i = 0; i < 7; ++i){
        int a, b;
        cin >> a >> b;
        classTime[i] = a + b;
    }
    if(classTime[test(classTime)] > 8){
        cout << test(classTime) + 1 << endl;
        return 0;
    }
    cout << "0" << endl;
    return 0;
}