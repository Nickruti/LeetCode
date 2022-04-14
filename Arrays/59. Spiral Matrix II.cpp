// Url - https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int gR = 0, gC = n - 1, num = 1;
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        while(num < n*n)
        {
            for(int i = gR; i < gC; i++)
            {
                ans[gR][i] = num;
                num++;
            }
            for(int i = gR; i < gC; i++)
            {
                ans[i][gC] = num;
                num++;
            }
            for(int i = gC; i > gR; i--)
            {
                ans[gC][i] = num;
                num++;
            }
            for(int i = gC; i > gR; i--)
            {
                ans[i][gR] = num;
                num++;
            }
            gR++;
            gC--;
        } 
        
        if(n % 2 == 1)
        {
            ans[gR][gC] = num;
        }
        
    
        return ans;
    }
};