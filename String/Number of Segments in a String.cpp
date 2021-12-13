// Url - https://leetcode.com/problems/number-of-segments-in-a-string/

class Solution {
public:
    int countSegments(string s) {
        if (s == "") return 0;
        
        int count = 0, i = 0 ;
       
        for(i = 0; i < s.length(); i++)
        {
            if (i != 0 && s[i] == ' ' && s[i-1] != ' ')
            {
                count++;
            }
        }
        
        if (s[i-1] != ' ')
        {
            count++;
        }
        return count;
    }
};
