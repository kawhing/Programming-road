#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void test(vector<bool> &arr, string arr01, int arr02){
    for(int i = 1; i <= arr02; ++i){
        float factor;
        stringstream(arr01) >> factor;
        arr[(int)(i * factor)] = !arr[(int)(i * factor)];
    }
}

int returnResult(vector<bool> &arr){;
    int result = 0;
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i]) return i+1;
    }
    return 0;
}
int main(){
    
    int n = 0;
    cin >> n;//n : 小明操作的次数
    int size = 0;//路灯的数量,尽管是无限,但是初始灯是关闭的,也就是说操作的最大编号的灯相当于是最后一盏灯
    vector<string> arr01(n);
    vector<int> arr02(n);
    for(int i = 0; i < n; ++i){
        string temp;
        cin >> arr01[i] >> arr02[i];
        float factor;
        stringstream(arr01[i]) >> factor;
        if((int)(factor*arr02[i]) > size) size = (int)(factor*arr02[i]);
    }

    vector<bool> arr(size+1, false);
    
    for(int i = 0; i < n; ++i){
        test(arr, arr01[i], arr02[i]);
    }
    cout << returnResult(arr) << endl;
    return 0;
}