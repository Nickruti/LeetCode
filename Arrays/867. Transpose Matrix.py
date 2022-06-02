# Url - https://leetcode.com/problems/transpose-matrix/

class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        nrows = len(matrix)
        ncols = len(matrix[0])
        
        ansMatrix = [[None] * nrows for _ in range(ncols)]
        
        for i in range (0, nrows):
            for j in range(0, ncols):
                ansMatrix[j][i] = matrix[i][j]
                
        return ansMatrix
        