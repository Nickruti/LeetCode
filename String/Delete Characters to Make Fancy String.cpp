// url - https://leetcode.com/problems/delete-characters-to-make-fancy-string/
 
class Solution {
public:
    string makeFancyString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 1;
        string ans = "";
        
        ans.push_back(s[0]);
        for(int i = 1; i < s.length(); i++)
        {
            if (s[i-1] == s[i])
            {
                cnt++;
                if (cnt == 3)
                {
                    cnt--;
                    continue;   
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
            else
            {
                ans.push_back(s[i]);
                cnt = 1;
            }
        }
        return ans;
    }
};
