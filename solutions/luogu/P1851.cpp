#include <iostream>
using namespace std;

int yueshu(int x){
    int sum = 0;
    for(int i = 1; i < x; ++i){
        if(x % i == 0) sum += i;
    }
    return sum;
}
int main(){
    int s;
    cin >> s;
    while(yueshu(s+1) == yueshu(yueshu(s+1)) && s+1 != yueshu(s+1)){
        ++s;
    }
    cout << s << " " << yueshu(s) << endl;
    return 0;
}