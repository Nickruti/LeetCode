// Url - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans;

        int tempSum = 0;
        while(left < right)
        {
            tempSum = numbers[left] + numbers[right];
            if(tempSum == target)
            {
                ans.push_back(left + 1);
                ans.push_back(right + 1);
                left++;
                right--;
            }
            else if(tempSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        
        return ans;
    }
};
