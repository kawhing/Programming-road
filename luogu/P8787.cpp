#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
//未通过
void test(){
    long long n = 6;
    //cin >> n;
    vector<long long> array = {2, 1, 4, 2, 6, 7};//(n);
    //for(long long i = 0; i < n; ++i)
    //    cin >> array[i];
    long long index = 0, count = 0;
    while(index < n){
        long long temp_height = array[index];
        if(temp_height == 1){
            ++index;
            continue;
        }
        long long temp_index = index;
        while(temp_index < n && array[temp_index] == temp_height){
            ++temp_index;
        }
        if(temp_index == index){
            array[index++] = 1;
        }else{
            ++count;
            for(long long i = index; i < temp_index; ++i){
                array[i] = int(sqrt(int(array[i]/2)+1));
                if(array[i] == 1) index = i;
            }
        }
    }
    cout << count << endl;
}
int main(){
    test();
    return 0;
}