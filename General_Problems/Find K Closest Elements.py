# url - https://leetcode.com/explore/featured/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3800/

# My Code---------------- O(2nlogn)

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        
        if x <= arr[0]:
            return arr[0:k]
        
        ans = {}
        
        for i in range(len(arr)):
            ans[i] = abs(arr[i] - x)
            
        ans = dict(sorted(ans.items(), key=lambda item: item[1]))
        ans = dict(list(ans.items())[0: k]) 
        
        finalAns = []
        for i in ans.keys():
            finalAns.append(arr[i])
        
        finalAns.sort()
        return finalAns[:k]
      
# Optimized Code - O(logn) --------------------------

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # Initialize binary search bounds
        left = 0
        right = len(arr) - k
        
        # Binary search against the criteria described
        while left < right:
            mid = (left + right) // 2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else:
                right = mid

        return arr[left:left + k]
