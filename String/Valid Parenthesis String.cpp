// Url - https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        int cntStar = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*' || s[i] == '(')
            {
                cntStar++;
            }
            else
            {
                if (cntStar <= 0)
                {
                    return false;
                    
                }
                cntStar--;     
            }
        }
        
        if (cntStar == 0) return true;
        cntStar = 0;
        
        for(int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == '*' || s[i] == ')')
            {
                cntStar++;
            }
            else
            {
                if (cntStar <= 0)
                {
                    return false;
                    
                }
                cntStar--;     
            }
        }
        return true;
    }
};