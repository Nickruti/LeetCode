// Url - https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3) return 0;
        int prevDiff = nums[1] - nums[0];
        int cnt = 0, diff = 0, indexCnt = 0;
        
        for(int i = 1; i < nums.size() - 1; i++)
        {
            diff = nums[i+1] - nums[i];
            
            if(diff == prevDiff)
            {
                ++indexCnt;
            }
            else
            {
                prevDiff = diff;
                indexCnt = 0;
            }
            cnt += indexCnt;
        }
        return cnt;
    }
};