class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area = 0, heightsSize = heights.size() + 2;
        heights.resize(heightsSize);
        heights[heightsSize - 1] = 0;
        for(int i = heightsSize - 2; i > 0; --i){
            heights[i] = heights[i - 1];
        }
        heights[0] = 0;
        stack<int> stk;
        stk.push(0);
        for(int i = 1; i < heightsSize; ++i){
            while(heights[stk.top()] > heights[i]){
                int j = stk.top();
                stk.pop();
                area = max(area, heights[j] * (i - stk.top() - 1));
            }
            stk.push(i);
        }
        return area;
    }
};