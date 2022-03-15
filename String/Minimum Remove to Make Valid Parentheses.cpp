// Url - https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int cnt = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] != ')')
            {
                ans += s[i];
                if(s[i] == '(')
                {
                    cnt++;
                }
            }
            else
            {
                if(cnt > 0)
                {
                    cnt--;
                    ans += s[i];
                }
                else
                {
                    continue;
                }
            }
        }
        
        string finalAns = "";
        cnt = 0;
        
        for(int i = ans.length() - 1; i >= 0; i--)
        {
            if(ans[i] != '(')
            {
                finalAns += ans[i];
                if(ans[i] == ')')
                {
                    cnt++;
                }
            }
            else
            {
                if(cnt > 0)
                {
                    cnt--;
                    finalAns += ans[i];
                }
                else
                {
                    continue;
                }
            }
        }
        
        reverse(finalAns.begin(), finalAns.end());
        return finalAns;
    }
};