#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int result = 0;
    for(int i = 0; i < n; ++i){
        result += i + 1;
    }
    cout << result << endl;
    return 0;
}