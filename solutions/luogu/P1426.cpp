#include <iostream>
using namespace std;

int main(){
    float s, x, v = 7;
    cin >> s >> x;

    float t = 0, len = 0;
    while(len + v < s-x){
        len += v;
        v *= 0.98;
        //++t;
    }
    if(s-x-len){
        t = (s-x-len)/(v *=0.98);
        if((1-t)*v + t*(v*0.98) >= 2*x){
            cout << "n" << endl;
        }else{
            cout << "y" << endl;
        }
    }else{
        if(v*0.98 >= 2*x){

            cout << "n" << endl;
        }else{
            cout << "y" << endl;
        }
    }
    return 0;
}