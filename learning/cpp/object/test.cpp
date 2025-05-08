#include <iostream>
#include <vector>
using namespace std;

int noTaken(vector<bool> a, int start) {
    for(int i = start; ; i = (i + 1) % a.size()){
        if(!a[i]) return i;
    }
    return -1;
}

int winNum(vector<int> a, int start){
    int winNum = 0, countNum = 1;
    vector<bool> taken(a.size(), false);
    for(int i = start; ; i = (i + 1) % a.size()){
        if(taken[i % a.size()]) i = noTaken(taken, i);
        else{
            if(countNum == a[i % a.size()]){
                winNum += a[i % a.size()];
                taken[i % a.size()] = true;
                countNum = 1;
            }else{
                ++countNum;
            }
        }
        if(countNum ==  a.size()) break;
    }
    return winNum;
}
int main(){
    vector<int> a = {2, 1, 3};
    cout << winNum(a, 5) << endl;
}