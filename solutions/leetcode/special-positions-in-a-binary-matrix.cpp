class Solution {
public:
    int colDetect(vector<vector<int>>& mat, int col){
        int row;
        int oneSize = 0;
        for(int i = 0; i < mat[col].size(); ++i){
            if(mat[col][i] == 1){
                ++oneSize;
                row = i;
            }
        }
        if(oneSize != 1){
            return -1;
        }
        return row;
    }
    int rowDetect(vector<vector<int>>& mat,  int row){
        int col;
        int oneSize = 0;
        for(int i = 0; i < mat.size(); ++i){
            if(mat[i][row] == 1){
                ++oneSize;
                col = i;
            }
        }
        if(oneSize != 1){
            return -1;
        }
        return col;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int col = 0, row = 0;
        for(int i = 0; i < mat[0].size(); ++i){
            row = i;
            col = rowDetect(mat, row);
            if(col != -1 && row == colDetect(mat, col)){
                ++ans;
            }
        }
        return ans;
    }
};