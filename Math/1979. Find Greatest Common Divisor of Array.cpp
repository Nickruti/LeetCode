// Url - https://leetcode.com/problems/find-greatest-common-divisor-of-array/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxNum)
                maxNum = nums[i];
            if(nums[i] < minNum)
                minNum = nums[i];
        }
        
        if(minNum == maxNum)
            return maxNum;
        
        for(int i = minNum; i > 0; i--)
        {
            if(maxNum % i == 0 && minNum % i == 0)
            {
                return i;
            }
        }
        
        return minNum;
        
        // return __gcd(*min_element(begin(nums), end(nums)), *max_element(begin(nums), end(nums)));
    }
};