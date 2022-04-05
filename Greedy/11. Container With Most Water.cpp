// Url - https://leetcode.com/problems/container-with-most-water/

// Time Limit Exceeded - Brute Force
// for(int i = 0; i < n - 1; i++)
// {
//     for(int j = n - 1; j > i; j--)
//     {
//         int area = min(height[i], height[j]) * (j-i);
//         if(ans < area)
//         {
//             ans = area;
//         }
//     }
// }

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int ans = INT_MIN;
        int start = 0, end = height.size() - 1;
        
        while(start < end)
        {
            int area = min(height[start], height[end]) * (end-start);
            if(ans < area)
            {
                ans = area;
            }
            if(height[end] < height[start])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};