/*
url - https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int> (nums.begin(), nums.end()).size();  
    }
};
