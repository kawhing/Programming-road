#include <iostream>
#include <string>
using namespace std;

string swap(int n){
    string str = to_string(n);
    for(int i = 0; i < str.size()/2; ++i){
        int temp = str[i];
        str[i] = str[str.size()-i-1];
        str[str.size()-i-1] = temp;
    }
    return str;    
}
void rollback(int n){
    int temp = n;
    if(n < 0){
        temp = -1*temp;
        cout <<  -1*stoi(swap(temp)) << endl;
    }else{
        cout << stoi(swap(temp)) << endl;
    } 
}
int main(){
    int numN;
    cin >> numN;
    rollback(numN);
    return 0;
}