// URL - https://leetcode.com/problems/longest-palindrome/

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map <char, int> un;
        for (int i = 0; i < s.length(); i++)
        {
            un[s[i]]++;
        }
        
        int pcnt = 0, longestOdd = 0;
        for(auto i: un)
        {
            
            if (i.second % 2 == 0)
            {
                pcnt += i.second;
            }
            else
            {
                pcnt += (i.second - 1);
                if (longestOdd < i.second)
                {
                    longestOdd = i.second;
                }
            }
        }
        if (longestOdd) pcnt++;
        return pcnt;
        
    }
};