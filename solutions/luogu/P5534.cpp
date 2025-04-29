#include <iostream>
using namespace std;

void test(){
    long long a1, a2, n;
    cin >> a1 >> a2 >> n;
    cout << n*a1 + n*(n-1)*(a2-a1)/2;
}

int main(){
    test();
    return 0;
}