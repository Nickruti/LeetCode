// url - https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = 0, lenS = s.length(), lenT = t.length();
        
        while (i < lenS)
        {
            if (s[i] == '#')
            {
                if ((i - 1) != -1)
                {
                    s.erase(i - 1, 2);
                    lenS = lenS - 2;
                    i -= 2;
                }
                else
                {
                    s.erase(i, 1);
                    lenS = lenS - 1;
                    i -= 1;
                }    
            }
            i++;
        }
        
        i = 0;
        while (i < lenT)
        {
            if (t[i] == '#')
            {
                if ((i - 1) != -1)
                {
                    t.erase(i - 1, 2);
                    lenT = lenT - 2;
                    i -= 2;
                }
                else
                {
                    t.erase(i, 1);
                    lenT = lenT - 1;
                    i -= 1;
                }
                
            }
            i++;
        }
        
        return s == t;
                 
    }
};
