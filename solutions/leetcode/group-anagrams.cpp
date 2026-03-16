class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size() < 2){
            vector<vector<string>> tempStr;
            tempStr.push_back(strs);
            return tempStr;
        }  
        map<string, vector<string>> mp;
        for(int i = 0; i < strs.size(); ++i){
            string tempStr = strs[i];
            sort(tempStr.begin(), tempStr.end());
            if(mp.find(tempStr) == mp.end()){
                vector<string> tempV;
                tempV.push_back(strs[i]);
                mp[tempStr] = tempV; 
            }else{
                mp[tempStr].push_back(strs[i]);
            }
        }
        vector<vector<string>> ans;
        for(map<string, vector<string>>::iterator it = mp.begin(); it != mp.end(); ++it){
            ans.push_back(it->second);
        }
        return ans;
    }
};