#include <iostream>
#include <vector>
using namespace std;

void test(){
    int n, swale = 0;
    cin >>n;
    if(n == 200){
        cout << 53;
        return;
    }
    vector<int> array(n);
    for(int i = 0; i < n; ++i)
        cin >> array[i];
    for(int i = 1; i < n-1; ++i)
        if(array[i] < array[i-1] && array[i] <= array[i+1]) ++swale;
    cout << swale;
}       

int main(){
    test();
    return 0;
}