#include <iostream>
using namespace std;

void test(){
    int x;
    cin >> x;
    bool characteristic1 = false, characteristic2 = false;
    if(x%2 == 0) characteristic1 = true;
    if(x>4 && x<=12) characteristic2 = true;
    cout << (characteristic1 && characteristic2);
    cout << " ";
    cout << (characteristic1 || characteristic2);
    cout << " ";
    cout << ((characteristic1&&!characteristic2) || (!characteristic1&&characteristic2));
    cout << " "; 
    cout << (!characteristic1 && !characteristic2);

}

int main(){
    test();
    return 0;
}