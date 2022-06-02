// Url - https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int nrows = matrix.size();
        int ncols = matrix[0].size();
        
        vector<vector<int>> ansMatrix(ncols, vector(nrows, INT_MIN));
        
        for(int i = 0; i < nrows; i++)
        {
            for(int j = 0; j < ncols; j++)
            {
                ansMatrix[j][i] = matrix[i][j];
            }
        }
        
        return ansMatrix;
    }
};