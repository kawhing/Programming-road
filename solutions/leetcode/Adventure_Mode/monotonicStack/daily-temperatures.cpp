class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int temperaturesSize = temperatures.size();
        stack<int> stk;
        vector<int> res(temperaturesSize, 0);
        for(int i = 0; i < temperaturesSize; ++i){
            if(stk.empty()){
                stk.push(i);
            }else{
                int topNum = temperatures[stk.top()];
                while(topNum < temperatures[i]){
                    res[stk.top()] = i - stk.top();
                    stk.pop();
                    if(!stk.empty()){
                        topNum = temperatures[stk.top()];
                    }else{
                        break;
                    }
                }
                stk.push(i);
            }
        }
        return res;
    }
};