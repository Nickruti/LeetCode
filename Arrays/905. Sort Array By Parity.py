# url - https://leetcode.com/problems/sort-array-by-parity/

class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        oddPointer = 0
        evenPointer = len(nums) - 1
        
        while oddPointer < evenPointer:
            if nums[oddPointer] % 2 > nums[evenPointer] % 2:
                nums[oddPointer], nums[evenPointer] = nums[evenPointer], nums[oddPointer]
                
            if nums[oddPointer] % 2 == 0:
                oddPointer += 1
            if nums[evenPointer] % 2 == 1:
                evenPointer -= 1  
                            
        return nums       