// Url - https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int up = 0, down = m - 1, midC = 0;
        
        while(up <= down)
        {
            midC = up + ((down - up)/2); 
            
            if (matrix[midC][n-1] == target) return true;
            
            if (matrix[midC][n-1] > target)
            {
                if(matrix[midC][0] <= target)
                    break;
                down = midC - 1;
            }
            
            else if (matrix[midC][n-1] < target)
            {
                up = midC + 1;
            }
        }
        
        int left = 0, right = n - 1, midR = 0;
        
        while(left <= right)
        {
            midR = left + ((right - left)/2);
            
            if (matrix[midC][midR] == target) return true;
            
            if (matrix[midC][midR] > target)
            {
                right = midR - 1;
            }
            else if (matrix[midC][midR] < target)
            {
                left = midR + 1;
            }
        }
         return false;
    }
};