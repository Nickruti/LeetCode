// Url - https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int oddPointer = 0;
        int evenPointer = nums.size() - 1;
        
        while(oddPointer < evenPointer)
        {
            while(nums[oddPointer]%2 != 1 && oddPointer < evenPointer)
            {
                oddPointer++;
            }
            while(nums[evenPointer]%2 != 0 && oddPointer < evenPointer)
            {
                evenPointer--;
            }
            int temp = nums[oddPointer];
            nums[oddPointer] = nums[evenPointer];
            nums[evenPointer] = temp;
        }
        
        return nums;
    }
};