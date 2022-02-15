// Url - https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp = {{"()"}};
        
        for(int l = 1; l < n; l++)
        {
            set<string> temp;
            for(int i = 0; i < dp[l-1].size(); i++)
            {
                temp.insert("(" + dp[l-1][i] + ")");
                temp.insert("()" + dp[l-1][i]);
                temp.insert(dp[l-1][i] + "()");
            }

            for(int k = 1; k < (l + 1)/2; k++)
            {
                for(int i = 0; i < dp[l-k-1].size(); i++)
                {  
                    for(int j = 0; j < dp[k].size(); j++)
                    {
                        temp.insert(dp[l-k-1][i] + dp[k][j]);
                        temp.insert(dp[k][j] + dp[l-k-1][i]);
                        
                    }
                }
            }
              
            vector<string> q(temp.begin(), temp.end());
            dp.push_back(q);  
        }
        
        
        return dp[n-1];
    }
};

// Constructor Solution
class Solution {
public:
    vector<vector<string>> dp = {{"()"}};
    
    Solution()
    {
        for(int l = 1; l < 9; l++)
        {
            set<string> temp;
            for(int i = 0; i < dp[l-1].size(); i++)
            {
                temp.insert("(" + dp[l-1][i] + ")");
                temp.insert("()" + dp[l-1][i]);
                temp.insert(dp[l-1][i] + "()");
            }

            for(int k = 1; k < (l + 1)/2; k++)
            {
                for(int i = 0; i < dp[l-k-1].size(); i++)
                {  
                    for(int j = 0; j < dp[k].size(); j++)
                    {
                        temp.insert(dp[l-k-1][i] + dp[k][j]);
                        temp.insert(dp[k][j] + dp[l-k-1][i]);
                        
                    }
                }
            }
              
            vector<string> q(temp.begin(), temp.end());
            dp.push_back(q);  
        }
    }
    
    vector<string> generateParenthesis(int n) {
        return dp[n-1];
    }
};