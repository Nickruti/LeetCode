// Url - https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void combinations(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int i)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        
        while(i < candidates.size() )
        {
            if (target - candidates[i] >= 0)
            {
                temp.push_back(candidates[i]);
            
                combinations(candidates, target - candidates[i], ans, temp, i);

                temp.pop_back();
            }
            ++i;
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        combinations(candidates, target, ans, temp, 0);
        return ans;
    }
};