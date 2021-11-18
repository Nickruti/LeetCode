// url - https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int dpA[coins.size()+1][amount+1];
        
        memset(dpA, 0, sizeof(dpA));
        
        for (int i = 1; i <= amount; i++)
        {
            dpA[0][i] = 10000;
        }
        
        for (int i = 1; i <= coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if ((j - coins[i-1]) < 0)
                {
                    dpA[i][j] = dpA[i-1][j];
                }
                else
                {
                    // cout << j - coins[i] << "\n";
                    dpA[i][j] = min(dpA[i-1][j], dpA[i][j-coins[i-1]]+1);
                }
                
            }
        }
        
        return dpA[coins.size()][amount] >= 10000 ? -1 : dpA[coins.size()][amount];
        
    }
};
