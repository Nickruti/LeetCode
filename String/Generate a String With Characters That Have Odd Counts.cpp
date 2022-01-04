// Url - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/submissions/

class Solution {
public:
    string generateTheString(int n) {
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans.push_back('k');
        }
        
        if (n % 2 == 0)
        {
            ans[n-1] = 's';
        }
        
        return ans;
    }
};
