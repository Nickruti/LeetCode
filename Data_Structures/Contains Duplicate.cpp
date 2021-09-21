/*
url - https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int> (nums.begin(), nums.end()).size();  
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map <int, int> m;
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]))
            {
                return true;
            }
            m[nums[i]] = i;
        }
        
        return false;
    }
    
};
