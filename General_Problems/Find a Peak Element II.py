# url - https://leetcode.com/problems/find-a-peak-element-ii/

# O(nlogn)
class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        
        maxM = 0
        row = 0
        l = 0
        r = len(mat[0])-1
        
        while (l < r):
            mid = (l + r)//2
           
            for i in range(len(mat)):
                if maxM < mat[i][mid]:
                    maxM = mat[i][mid]
                    row = i
                    
            if maxM > mat[row][mid+1]:
                if mid and maxM > mat[row][mid-1]:
                    return row, mid
                r = mid
            else:
                l = mid + 1
                 
        for i in range(len(mat)):
                if maxM < mat[i][l]:
                    maxM = mat[i][l]
                    row = i
            
        return row, l
                
