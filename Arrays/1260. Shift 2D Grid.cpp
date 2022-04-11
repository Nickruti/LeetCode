// URL - https://leetcode.com/problems/shift-2d-grid/

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int gSize = grid.size();
        int gArrSize = grid[0].size();
        
        vector<vector<int>> ans(gSize, vector<int>(gArrSize, 0));
        
        for(int i = 0; i < gSize*gArrSize; i++)
        {
           int temp= (i + k) % (gSize * gArrSize);
           ans[temp/gArrSize][temp%gArrSize] = grid[i/gArrSize][i%gArrSize];
        }
        
        return ans;
    }
};