//  url - https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> m;
        int n = nums.size();
        
        for(int i = 0; i< n; i++)
        {
            m[nums[i]]++;
        }
        
        int max = INT_MIN, ans;
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second > max)
            {
                max = it->second;
                ans = it->first;
            }
        }
            
        return ans;
    }
};

// Boyer - Moore Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(count == 0)
            {
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};