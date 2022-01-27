// Url - https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int s1len = s1.length(), s2len = s2.length();
        
        if (s1len != s2len) return false;
        if (s1 == s2) return true;
        
        char s1char, s2char;
        int flag = 0;
        
        for (int i = 0; i < s1len; i++)
        {
            if (s1[i] != s2[i])
            {
                if (flag == 0)
                {
                    s1char = s1[i];
                    s2char = s2[i];
                    flag = 1;
                }
                else
                {
                    if (s1char == s2[i] && s2char == s1[i] && flag == 1) 
                    {
                        flag = 2;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (flag == 2)
        {
            return true;
        }
        return false;
    }
};