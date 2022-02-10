// Url - https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> telButtons {
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };
        
        int digLen = digits.length();
        vector<string> ans;
        
        if(digLen == 0) return ans;
        
        for(int i = 0; i < telButtons[digits[0] - '0' - 2].size(); i++)
        {
            ans.push_back(telButtons[digits[0] - '0' - 2][i]);
        }
        
        if(digLen == 1) return ans;
        
        int i = 1;
        while(i < digLen)
        {
            vector<string> temp;
            for(int j = 0; j < ans.size(); j++)
            {
                for(int k = 0; k < telButtons[digits[i] - '0' - 2].size(); k++)
                {
                    temp.push_back(ans[j] + telButtons[digits[i] - '0' - 2][k]);
                }
            }
            ans = temp;
            i++;
        }
        
        return ans;
    }
};