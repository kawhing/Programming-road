class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows) return s;

        vector<string> rows(min(numRows, int(s.size())));         
        int curRow = 0;
        bool goingDown = false;
        for(int i = 0; i < s.size(); ++i){
            rows[curRow] += s[i]; 
            if(curRow == 0 || curRow == numRows - 1){
                goingDown = !goingDown;
            }
            if(goingDown) curRow++;
            else curRow--;
        }
        string ans = "";
        for(int i = 0; i < rows.size(); ++i){
            ans += rows[i];
        }
        return ans;
    }
};