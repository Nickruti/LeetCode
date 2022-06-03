// Url - https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        
        if(rows == 0 || cols == 0) return;
        
        dp.resize(rows + 1);
        for(int i = 0; i <= rows; i++)
        {
            dp[i].resize(cols + 1);
        }
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                dp[row + 1][col + 1] = dp[row + 1][col] + dp[row][col + 1] + matrix[row][col] - dp[row][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */