'''
problem url - https://leetcode.com/problems/container-with-most-water/
Difficulty - Medium
'''

#Naive Solution - Time Limit exceeded
class Solution:
    def maxArea(self, height: List[int]) -> int:
        lenH = len(height)
        maxH = 0
        for i in range(0,lenH-1):
            cnt = 1
            for j in range(i+1, lenH):
                soln = min(height[i],height[j])*cnt
                if maxH < soln:
                    maxH = soln   
                cnt += 1
        return maxH
                
     
