/*
url - https://leetcode.com/problems/longest-common-prefix/ 
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0, j = 0;
        string ans = strs[0];
        
        for(i = 1; i < strs.size(); i++)
        {
            int minL = min(ans.length(), strs[i].length());
            ans.erase(minL);
            for (j = 0; j < minL; j++)
            {
                if (ans[j] != strs[i][j])
                {
                    ans.erase(j);
                    break;
                }
            }
        }
        return ans;
    }
};
