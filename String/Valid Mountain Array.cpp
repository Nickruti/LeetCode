// Url - https://leetcode.com/problems/valid-mountain-array/

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        
        int flag = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i-1] > arr[i] && flag == 0)
            {
                if ( i == 1)
                {
                    return false;
                }
                flag = 1;   
            }
            else if (arr[i-1] < arr[i] && flag == 1)
                return false;
            else if (arr[i-1] == arr[i])
                return false;
        }
        return flag;
    }
};