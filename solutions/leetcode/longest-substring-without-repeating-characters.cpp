class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1) return s.size();
        int i = 0, j = 1;
        int ans = 1;
        vector<int> beingNum;
        beingNum.push_back(s[i]);
        while(i < j && j < s.size()){
            auto it = find(beingNum.begin(), beingNum.end(), s[j]);
            if(it != beingNum.end()){
                if(it - beingNum.begin() == 0){
                    
                    beingNum.push_back(s[j]);
                    beingNum.erase(beingNum.begin());
                    i++;
                    j++;
                }else{      
                    ans = max((int)beingNum.size(), ans);   
                    i += it - beingNum.begin() + 1;
                    beingNum.erase(beingNum.begin(), it + 1);
                    beingNum.push_back(s[j]);
                    j++;
                }
            }else{
                beingNum.push_back(s[j]);
                j++;
            }
            
        }
        
        return max(ans, (int)beingNum.size());
        
    }
};