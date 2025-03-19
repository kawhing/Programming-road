#include <iostream>
#include <vector>
using namespace std;
// not rearly reslove
void addHigh(vector<int>& array, vector<int>& max){
    for(int i = 0; i < array.size(); ++i){
        ++array[i];
        if(array[i] > max[i]){
            max[i] = array[i];
        }
    }
}

void test(){
    int n;
    cin >> n;
    vector<int> array(n, 0);
    vector<int> max(n, 0);
    int dir = 1;
    int index = 0;
    for(int day = 0; day < 2*(n-1)*n; ++day){
        addHigh(array, max);
        array[index] = 0;
        index += dir;
        if(index == n-1 || index == 0)
            dir = -dir;
        
    }

    for(int i = 0; i < n; ++i){
        cout << max[i] << endl;
    }
    
}

int main(){
    test();
    return 0;
}