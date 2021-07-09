// url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/609/week-2-july-8th-july-14th/3808/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        
        int l = 0, size = nums.size();
        
        for (int i = 1; i < size; i++)
        {
            if (arr[i-1] != arr[i])
            {
                arr[++l] = arr[i];
            }
        }
        
        int dp[size+1][l+2];
        
        for (int i = 0; i <= size; i++)
        {
            dp[i][0] = 0;
        }
        
        for (int i = 0; i <= l+1; i++)
        {
            dp[0][i] = 0;
        }
        
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= l+1; j++)
            {
                if (nums[i-1] == arr[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        
        
        return dp[size][l+1];
        
    }
};
