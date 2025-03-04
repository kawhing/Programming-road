#include <iostream>
#include <vector>
using namespace std;

int search_Bin(vector<int> arr, int key){
    int low = 0, high = arr.size() - 1;
    while(low <= high){
        int mid = (low + high + 2) / 2 - 1;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return 0;
}

int searchBinByReturn(vector<int> arr, int key, int low, int high){
    if(low > high) return 0;
    
}
int main(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int key = 5, low = 0, high = v.size() - 1;
    //if(search_Bin(v, key) > 0) cout << "Found in " << search_Bin(v, key) << endl;
    //else cout << "Not Found" << endl;

}