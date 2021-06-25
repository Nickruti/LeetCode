'''
Problem Url - https://leetcode.com/problems/two-sum/

Possible Follow­Up Questions:
• Can you modify the array? Yes, that's fine.
• Do we know something about the range of the numbers in the array? No, they can
be arbitrary integers.
• Are the array elements necessarily positive? No, they can be positive, negative,
or zero.
• Do we know anything about the value of k relative to n or the numbers in the array? No, it can be arbitrary.
• Can we consider pairs of an element and itself? No, the pair should consist of
two different array elements.
• Can the array contain duplicates? Sure, that's a possibility.
• Is the array necessarily in sorted order? No, that's not guaranteed.
• What about integer overflow? For simplicity, don't worry about this.
'''

#Naive Solution - Time = O(n^2) Space = O(1)
'''
Runtime: 40 ms, faster than 95.70% of Python3 online submissions for Two Sum.
Memory Usage: 14.5 MB, less than 16.94% of Python3 online submissions for Two Sum.
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i,j]

#Hashing - Time = O(n) Space = O(n)
'''
Runtime: 48 ms, faster than 64.46% of Python3 online submissions for Two Sum.
Memory Usage: 14.5 MB, less than 16.94% of Python3 online submissions for Two Sum.
'''

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arrDict = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in arrDict.keys():
                return [i, arrDict[diff]]
            arrDict[nums[i]] = i
            
#Sorting and Walking Inward - Time = O(nlogn), Space = O(log n) 
'''
Incomplete Solution 
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums1 = nums.copy()
        nums1.sort()
        left = 0
        right = len(nums)-1
        while left < right:
            num1 = nums1[left]
            num2 = nums1[right]
            sum_ = num1 + num2
            if sum_ == target:
                if num1 != num2 : 
                    return [nums.index(num1), nums.index(num2)]
                else:
                    return [left, right]
            elif sum_ < target:
                left += 1
            else:
                right -= 1
