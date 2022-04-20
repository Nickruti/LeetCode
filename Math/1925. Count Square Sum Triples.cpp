// URl - https://leetcode.com/problems/count-square-sum-triples/

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        vector<bool> squares(n * n + 1, 0);
        
        for(int i = 1; i <= n; i++)
        {
            squares[i * i] = true;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; i * i + j * j <= n * n; j++)
            {
                ans += squares[i * i + j * j] * 2;
            }
        }
        
        return ans;
    }
};