// Url - https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    vector<int> dp = vector<int>(1001, 0);
    Solution()
    {
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i < 1001; i++)
        {
            int temp = isPrime(i);
            if(temp)
            {
                dp[i] = dp[i/temp] + temp;
            }
            else
            {
                dp[i] = i;
            }
        }
    }
    
    int isPrime(int nums)
    {
        for(int i = 2; i*i <= nums; i++)
        {
            if(nums % i == 0)
            {
                return i;
            }
        }
        return 0;
    }
    int minSteps(int n) {
        return dp[n];
    }
};

