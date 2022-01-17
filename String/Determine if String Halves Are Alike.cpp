// Url - https://leetcode.com/problems/determine-if-string-halves-are-alike/

class Solution {
public:
    bool halvesAreAlike(string s) {
        
        string vowels = "aeiouAEIOU";
        int slen = s.length(), cnt = 0;
        
        for (int i = 0; i < slen/2; i++)
        {
            if (vowels.find(s[i]) != string::npos)
            cnt++;
        }

        for (int i = slen/2; i < slen; i++)
        {
            if (vowels.find(s[i]) != string::npos)
            cnt--;
        }
        
        return (cnt == 0);
    }
};