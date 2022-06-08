// Url - https://leetcode.com/problems/remove-palindromic-subsequences/

class Solution {
public:
    
    int removePalindromeSub(string s) {
        if (s == "") return 0;
        
        for(int i = 0, j = s.length() - 1; i < s.length(); i++, j--)
        {
            if(s[i] != s[j]) 
                return 2;
        }
        return 1;
    }
};