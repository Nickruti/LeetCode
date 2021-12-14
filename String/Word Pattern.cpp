// Url - https://leetcode.com/problems/word-pattern/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map <char, string> ps;
        stringstream ss(s);
        string word;
        int n;
        
        while (ss >> word)
        {
            n++;
        }
        
        if (pattern.length() != n) return false;
        
        int i = 0;
        stringstream st(s);
        while (st >> word)
        {
            if (ps.count(pattern[i]))
            {
                if (ps[pattern[i]] != word)
                {
                    return false;
                }    
            }     
            else
            {
                for (auto& it : ps) 
                {
                    if (it.second == word) 
                    {
                        return false;
                    }
                }
                ps[pattern[i]] = word;
            }    
            i++;
        }
        
        return true;
    }
};
