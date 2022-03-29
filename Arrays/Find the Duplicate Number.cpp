// Url - https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         int n = nums.size() - 1;
        
//         int total = 0;
//         total = accumulate(nums.begin(), nums.end(), 0);

//         int expectedSum = (n * (n + 1))/2;
//         return total - expectedSum;
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};