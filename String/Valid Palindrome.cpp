// url - https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string concated = "";

        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]) || isdigit(s[i]))
            {
                concated += tolower(s[i]);
            }
        }

        int clen = concated.length();
        for(int i = 0; i < clen; i++)
        {
            if(concated[i] != concated[clen-i-1])
                return false;
        }
        
        return true;
    }
};
