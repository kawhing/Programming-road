#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> class_num(n);
    vector<int> unhappy(n, 0);
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        class_num[i] = a+b-8;
    }
    unhappy[0] = class_num[0] > 0 ? class_num[0] : 0;
    int result = unhappy[0];
    for(int i = 1; i < n; ++i){
        unhappy[i] = (unhappy[i-1] < 0 ? 0 : unhappy[i-1]) + class_num[i];
        result += unhappy[i];
    }
    
    cout << result << endl;
    return 0;
}