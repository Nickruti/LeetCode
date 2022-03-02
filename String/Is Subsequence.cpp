// Url - https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.length(), tlen = t.length();
        int i = 0, j = 0;
        
        if(slen > tlen) return false;
        if(slen == 0) return true;
        
        while(j < tlen)
        {
            if(t[j] == s[i])
            {
                if(i == slen - 1)
                    return true;
                i++;
            }
            j++;
        }
        return false;
    }
};