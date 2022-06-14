// Url - https://leetcode.com/problems/triangle/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Initialize dp[][] to number of rows in triangle
        int nrows = triangle.size();
        
        vector<vector<int>> dp(nrows);
        
        int row = 1, ans = 0;
        
        // Initialize sub-vector at each row with 0
        // 0
        // 0 0
        // 0 0 0...
        
        for(int i = 0; i < nrows; i++)
        {
            dp[i] = vector<int>(triangle[i].size(), 0);
        }
        
        dp[0] = triangle[0];
        
        // Calculate the dp[][]
        for(row = 1; row < nrows; row++)
        {
            for(int col = 0; col < triangle[row].size(); col++)
            {
                // Calculation for first column on each row
                if(col == 0)
                {
                    dp[row][col] = dp[row - 1][col] + triangle[row][col];
                }
                // Calculation for last column on each row 
                else if(col == triangle[row].size() - 1)
                {
                    dp[row][col] = dp[row - 1][col - 1] + triangle[row][col];
                }
                // Calculation for all other middle columns
                else
                {
                    dp[row][col] = min(dp[row - 1][col - 1],dp[row - 1][col]) + triangle[row][col];
                } 
            }  
        }
        
        // Finding the min from last row of dp[][]
        ans = dp[row-1][0];
        for(int i = 1; i < dp[row-1].size(); i++)
        {
            if(ans > dp[row-1][i])
            {
                ans = dp[row-1][i];
            }
        }
        
        return ans;
    }
};