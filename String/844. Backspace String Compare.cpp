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

// Second method - Space - O(1), Time - O(M+N) 

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int i = s.length() - 1, j = t.length() - 1;
        int sS = 0, sT = 0;
        
        while (i >= 0 || j >= 0)
        {
            while(i >= 0)
            {
                if(s[i] == '#')
                {
                    sS++;
                    i--;
                }
                else if(sS > 0)
                {
                    sS--;
                    i--;
                }
                else break;
            }
            while( j >= 0)
            {
                if(t[j] == '#')
                {
                    sT++;
                    j--;
                }
                else if(sT > 0)
                {
                    sT--;
                    j--;
                }
                else break;
            }
            
            if((i >= 0) && (j >= 0) && (s[i] != t[j]))
            {
                return false;
            }   
            if ((i >= 0) != (j >= 0))
            {
                return false;
            }    
            i--;
            j--;
        }
        return true;           
    }
};
