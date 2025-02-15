#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> score(3);//语文，数学，英语
    int count = 0;
    for(int i = 0; i < 3; i++){
        cin >> score[i];
        if(score[i] < 60){
            count++;
        }
    }
    if(count == 1) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}