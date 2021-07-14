# url - 

## Naive Solution O(n/2)

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        if (len(nums) == 1):
            return 0
        
        if (len(nums) == 2):
            if nums[0] > nums[1]:
                return 0
            else:
                return 1
        
        for i in range (1, len(nums)-1):
                
            if nums[i-1] < nums[i] and nums[i] > nums[i+1]:
                return i
                   
            else:
                if nums[i-1] > nums[i+1]:
                    return i-1
                else:
                    i+=1
                    
        return i  
      
# Optimised Solution using Binary Search
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        def binarySearch(l, r):
            if l == r:
                return l
            
            mid = (l + r)//2
            
            if nums[mid] > nums[mid+1]:
                return binarySearch(l, mid)
            return binarySearch(mid+1, r)
        
        return binarySearch(0, len(nums)-1)
        

                
        
