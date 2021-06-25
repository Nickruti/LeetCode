class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        # Brute force method
        # T: O(N^2)
        # S: O(N)
        
        if len(nums) == 1:
            return nums[0]
        
        res = []
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)+1):
                res.append(sum(nums[i:j]))
        return max(res)
        
    def maxSubArray(self, nums: List[int]) -> int:
        # DP
        # T: O(N)
        # S: O(N)
        
        dp = [0] * len(nums)
        dp[0] = nums[0]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i] + dp[i-1], nums[i])
        
        return max(dp)
        
