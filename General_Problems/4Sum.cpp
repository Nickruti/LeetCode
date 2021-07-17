// url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/610/week-3-july-15th-july-21st/3816/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set <vector<int>> ansArr;
        vector<vector<int>> ans;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int k = j + 1;
                int l = n - 1;
                while(k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        ansArr.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        copy(ansArr.begin(), ansArr.end(), back_inserter(ans));
        return ans;
    }
};
