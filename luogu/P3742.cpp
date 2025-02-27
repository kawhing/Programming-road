#include <iostream>
#include <string>
using namespace std;

void test(){
    int n;
    cin >> n;
    string x, y, z;
    cin >> x >> y;
    
    z = "";
    bool possible = true;
    
    for(int i = 0; i < n; ++i){
        if(x[i] < y[i]){
            // 如果x[i]小于y[i]，无解
            possible = false;
            break;
        } else if(x[i] == y[i]){
            // 如果x[i]等于y[i]，z[i]可以是任何大于等于x[i]的字符
            z += 'z'; // 这里选择'z'
        } else { // x[i] > y[i]
            // 如果x[i]大于y[i]，要使min(x[i],z[i])=y[i]，必须z[i]=y[i]
            z += y[i];
        }
    }
    
    if(possible){
        cout << z << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main(){
    test();
    return 0;
}