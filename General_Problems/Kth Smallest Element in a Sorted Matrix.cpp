// url - https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/608/week-1-july-1st-july-7th/3805/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix[0].size();
       
        vector<int> arr;
        
        // r = matrix[r/n][r%n];
        // c = matrix[k/n][(k%n)-1];
        // cout << r << "\n";
        // cout << c;
        
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr.push_back(matrix[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        return arr[k-1];
    }
};
