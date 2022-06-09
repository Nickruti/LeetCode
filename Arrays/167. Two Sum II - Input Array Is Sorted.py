# Url - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1
        
        ans = []
        
        while left < right:
            if (numbers[left] + numbers[right]) == target:
                ans.append(left + 1)
                ans.append(right + 1)
                left += 1 
                right -= 1
            elif (numbers[left] + numbers[right]) < target:
                left += 1
            else:
                right -= 1
                
        return ans
                