#include <iostream>
using namespace std;

float walk(int n){
    return n / 1.2; ;
}
float bike(int n){
    return 27 + 23 + n / 3.0;
}
int main(){
    int n;
    cin >> n;
    if(walk(n) < bike(n)) cout << "Walk" << endl;
    else if(walk(n) == bike(n)) cout << "All" << endl;
    else cout << "Bike" << endl;
    return 0;
}