#include <iostream>
#include <vector>
using namespace std;

void StraightInsertSort(vector<int> &arr){
    for (int i = 1; i < arr.size(); ++i) {
        int temp = arr[i];
        for(int j = i; j >= 0 && arr[j-1] > temp; --j){
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }

}
int main(){
    vector<int> arr;
    arr = {1, 4, 2, 3, 5};
    StraightInsertSort(arr);
    for(int i = 0; i < arr.size(); ++i){
        cout << arr[i] << " ";
    }
    return 0;
}