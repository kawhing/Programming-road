class Solution {
public:
    int minOperations(string s) {
        int opNum = 0;
        int sSize = s.size();
        // 0 1 0 1 ```````
        for(int i = 0; i < sSize; ++i){
            if(i % 2){
                if(s[i] == '1') ++opNum;
            }else{
                if(s[i] == '0') ++opNum;
            }
        }
        opNum = min(opNum, sSize - opNum);
        return opNum;
    }
};