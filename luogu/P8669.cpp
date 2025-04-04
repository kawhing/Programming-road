#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 超出我的实力了，只能写到这里了
class numsArray{
public:
    numsArray(long long n, long long k){
        this->numsSize = n;
        this->selectNum = k;
        this->nums.resize(n);
    }
    void get_maxNum(){
        for(long long i = 0; i < this->numsSize; ++i){
            cin >> this->nums[i];
            if(this->nums[i] >= 0){
                ++positiveNum;
                positiveNums.push_back(this->nums[i]);
            }else{ 
                ++negativeNum;
                negativeNums.push_back(nums[i]);
            }
            if(this->nums[i] > maxNum) maxNum = this->nums[i];
        }
        sort(positiveNums.begin(), positiveNums.end());
        sort(negativeNums.begin(), negativeNums.end());
    }

    long long numsSize = 0, positiveNum = 0, negativeNum = 0, maxNum = 0, selectNum = 0;
    vector<long long> nums;
    vector<long long> positiveNums, negativeNums;
};
void test(){
    long long n, k;
    cin >> n >> k;
    numsArray test(n, k);
    test.get_maxNum();
    if(test.numsSize = 1){
        cout << test.nums[0];
        return;
    }else if(test.numsSize == 2 && test.selectNum == 1){
        cout << test.maxNum << endl;
        return;
    }else if(test.selectNum%2 == 0){
        if(test.positiveNum > test.selectNum){

        }
    }else if(test.selectNum%2 == 1){

    }
}
int main(){
    test();
    return 0;
}