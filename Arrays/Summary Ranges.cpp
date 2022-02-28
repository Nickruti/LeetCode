// Url - https://leetcode.com/problems/summary-ranges/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        if (nums.size() == 0) return ans;
        
        int rangeInitial = nums[0], n = nums.size() ;
        
        for(int i = 0 ; i < n; i++)
        {
            if(i == n-1 || nums[i + 1] != nums[i] + 1)
            {
                if(nums[i] == rangeInitial)
                {
                    ans.push_back(to_string(rangeInitial));
                }
                else
                {
                    ans.push_back(to_string(rangeInitial) + "->" + to_string(nums[i]));
                }
                if(i != n - 1)
                    rangeInitial = nums[i + 1];
            }
        }
        
        return ans;
    }
};