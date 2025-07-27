#include <bits/stdc++.h>
using namespace std;

struct Combination{
    bool face;  // 0表示朝内，1表示朝外
    string job;
};
struct Order{
    int index, num;  // index：0表示向左，1表示向右
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<Combination> nums(n);
    vector<Order> order(m);
    int index = 0;  // 初始位置为第一个小人
    
    for(int i = 0; i < n; ++i) cin >> nums[i].face >> nums[i].job;
    
    for(int i = 0; i < m; ++i){
        cin >> order[i].index >> order[i].num;
        int steps = order[i].num % n;  // 实际需要移动的步数
        
        if(order[i].index == 0){  // 向左
            if(nums[index].face == 0){  // 当前所在的职业面朝里 
                index = (index - steps + n) % n;  // 确保结果为正
            }else{  // 当前所在的职业面朝外
                index = (index + steps) % n;
            }
        }else{  // 向右
            if(nums[index].face == 0){  // 当前所在的职业面朝里
                index = (index + steps) % n;
            }else{  // 当前所在的职业面朝外
                index = (index - steps + n) % n;  // 确保结果为正
            }
        }
    }
    
    cout << nums[index].job << endl;
}

int main(){
    solve();
    return 0;
}