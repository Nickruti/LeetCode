// url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3803/

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size(), n = mat[0].size();
        
        if (m * n != r * c)
        {
            return mat;
        }
        
        vector<vector<int>> newmat(r, vector<int>(c));
        int rcnt = 0, ccnt = 0;
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                newmat[rcnt][ccnt] = mat[i][j];
                if (ccnt != c - 1)
                {
                    ccnt++;
                }
                else if (ccnt == c - 1)
                {
                    ccnt = 0;
                    rcnt++;
                }
            }
        }
        
        return newmat;
        
        
    }
};
