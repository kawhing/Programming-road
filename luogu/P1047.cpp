#include <iostream>
using namespace std;
void  chonghe(int *test, int m, int *Chonghe){
    for(int i = 0; i < m-1; ++i){
        for(int j = i+1; j < m; ++j){
            if(test[i][0] > test[j][0] && test[i][0] < test[j][1]){
                chonghe[i] = true;
            }
            if(test[i][1] > test[j][0] && test[i][1] < test[j][1]){
                chonghe[i] = true;
            }
            if(test[j][0] > test[i][0] && test[j][0] < test[i][1]){
                chonghe[i] = true;
            }
            if(test[j][1] > test[i][0] && test[j][1] < test[i][1]){
                chonghe[i] = true;
            }
        }
    }
}
void ischonghe
int main(){
    int l, m, trees;//l:路长 m:区域的数量 trees:树的数量
    cin >> l >> m;
    bool isChonghe[m+1];
    int test[m][2];
    chonghe(test, m, isChonghe);
    trees = l+1;
    for(int i = 0; i < m; ++i){
        int start, end;
        cin >> test[i][0] >> test[i][1];
    }

    return 0;
}