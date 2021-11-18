// url - https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int size = coins.size(),i = 0, j = 0;
        
        int dp[coins.size()][amount+1];
        
        for (i = 0; i < size; i++)
        {
            dp[i][0] = 1;
        }
        
        for (i = 1; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
            }  
        }
        
        for (i = 1; i < size; i++)
        {
            for(j = 1; j <= amount; j++)
            {
                if (coins[i] > j)
                {
                    dp[i][j] = dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]];
                }
                
            }
        }
        
        return dp[size-1][amount];
        
    }
};
