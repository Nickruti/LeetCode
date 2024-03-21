// Link to the problem - https://leetcode.com/problems/move-zeroes/description/
// Topics - Array, Two Pointers
// Runtime 8 ms Beats 95.33% of users with C++
// Constraints:
// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

// My Solution ---------------------------
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int p2 = 1;
        int numLen = nums.size() - 1;

        while(p2 <= numLen){
            if(nums[p1] == 0){
                while(p2 <= numLen && nums[p2] == 0){
                    p2++;
                }
                if(p2 <= numLen){
                    nums[p1] = nums[p2];
                    nums[p2] = 0;
                }
            } 
            p1++;
            p2++;
        }
    }
};
