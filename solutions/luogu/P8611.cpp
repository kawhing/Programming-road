#include <iostream>
#include <vector>
using namespace std;

bool is_AllOut(vector<int> ants, int n){
    int outNum = 0;
    for(int i = 0; i < n; ++i){
        if(ants[i] < -100 || ants[i] > 100) ++outNum;
    }
    if(outNum == n) return true;
    return false;
}

void test(){
    int n;// the number of ants
    int coldsNum = 1;// the number of ant colds
    cin >> n;
   // the Length of the pole is 100 (location -100 to 100)
    vector<int> ants(n, 0);// the position of the ants
    vector<int> colds(n, 0);// colds of the ants
    colds[0] = 1;
    for(int i = 0; i < n; ++i)
        cin >> ants[i];
    while(true){// If all ants are out of the pole, the loop ends, but if one ant is still on the pole, the out of the pole is still move
        for(int i = 0; i < n-1; ++i){ // Determine the direction of the ants
            if((ants[i] > 0 && ants[i+1] < 0) || (ants[i] < 0 && ants[i+1] > 0)){ // If the ants meet, they change direction
                ants[i] = ants[i]*-1;
                ants[i+1] = ants[i+1]*(-1);
                if(colds[i] == 1 && colds[i+1] == 0){
                    colds[i+1] = 1;
                    ++coldsNum;
                }else if(colds[i] == 0 && colds[i+1] == 1){
                    colds[i] = 1;
                    ++coldsNum;
                }
                if(coldsNum == n){
                    cout << coldsNum << endl;
                    return;
                }
            }
        }
        for(int i = 0; i < n; ++i){// Move the ants
            if(ants[i] > 0) ++ants[i];
            else --ants[i];// According to the question, there is no case of 0
        }
        if(is_AllOut(ants, n)) {
            cout << coldsNum << endl;
            return;
        }
    }
}

int main(){
    test();
    return 0;
}