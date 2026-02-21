/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(numRows * sizeof(int*));
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    for(int i = 0; i < numRows; ++i){
        result[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;
        for(int j = 0; j <= i; ++j){
            if(j == 0 || j == i) result[i][j] = 1;
            else result[i][j] = result[i-1][j] + result[i-1][j-1];
        }
    }
    *returnSize = numRows;
    
    return result;

}