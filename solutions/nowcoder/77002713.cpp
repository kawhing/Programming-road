#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
/*小紫的劣势博弈 
https://ac.nowcoder.com/acm/contest/103948/B
有一个由n个整数构成的数组 {a1,a2,…,an}和一个整数 x=0小红和小紫轮流操作，每次操作方拿走数组中的一个元素，并从数组中移除。
记被拿走的元素为数组中的第i个元素 ai，若是小红拿走的，则会让x加上ai；若是小紫拿走的，则会让 x 减去 ai。
小红希望最终 x 尽可能小，小紫希望最终x尽可能大。
小红先手操作，请问双方都采用最优策略时，最终x的值是多少？
*/
//通过20 得分100
void test(){
    ll n, x = 0;
    cin >> n;
    vector<int> nums(n);
    for(ll i = 0; i < n; ++i){
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    for(ll i = 0; i < n; ++i){
        if(i % 2 == 0){
            x += nums[i];
        }else{
            x -= nums[i];
        }
    }
    cout << x << endl;
}
int main(){
    test();
    return 0;
}