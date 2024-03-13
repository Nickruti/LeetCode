// Link to the problem: https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int last = nums.size();
        int first = 0;  
        int mid;             
        if(nums[0] == target || target < nums[0]){
            return 0;
        } else if(nums[last- 1] == target){
            return last - 1;
        } else if (target > nums[last - 1]) {
            return last;
        }

        while( first <= last) {
            mid = (first + last)/2;
            if(nums[mid] == target){
                return mid;
            }

            if(target < nums[mid]){
                last = mid -1;
            } else {
                first = mid + 1;
            }
        }
        return first;
    }
};
