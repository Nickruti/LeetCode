// url - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/607/week-5-june-29th-june-30th/3796/

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int b = 0, f = 0;
        int n = nums.size();
        int maxcnt = 0;
        
        while (f!=n)
        {
            
            if (!nums[f])
            {
                if(k)
                {
                    k--;
                }
                else
                {
                    while (nums[b])
                    {
                        b++;
                    }
                    b++;
                }
                
            }
            f++;
            // cout << f << "\t" << b << "\n";
            maxcnt = max(maxcnt, f - b);
            // cout << maxcnt << "\t" << f - b << "\n";
            
        }
        return maxcnt;
    }
};

