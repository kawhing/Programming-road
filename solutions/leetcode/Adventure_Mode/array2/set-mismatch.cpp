class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> numTimes;
        int leakNum = -1, repeatNum = -1;
        for(int i : nums){
            if(numTimes.find(i) != numTimes.end()){
                numTimes[i]++;
                if(numTimes[i] == 2){
                    repeatNum = i;
                }
            }else{
                numTimes[i] = 1;
            }
        }
        for(int i = 1; i <= nums.size(); ++i){
            if(numTimes.find(i) == numTimes.end()){
                leakNum = i;
            }
        }
        return {repeatNum, leakNum};
    }
};