#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    float n, count = 1, result = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        result += count * (1.0 / i);
        count *= -1;
    }
    
    cout << fixed << setprecision(4) << result << endl;
    return 0;
}