#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> p(n), q(n);
    p[0] = 1, q[0] = 2;
    float result = q[0] / p[0];

    for(int i = 1; i < n; i++){
        q[i] = q[i - 1] + p[i - 1];
        p[i] = q[i - 1];
        result += (float)q[i] / p[i];
    }
    cout << fixed << setprecision(4) << result << endl;
    return 0;
}