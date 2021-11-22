// url - https://leetcode.com/problems/rotate-string/

class Solution {
public:
    bool rotateString(string s, string goal) {
        int slen = s.length(), glen = goal.length();
        
        for (int i = 0; i < slen; i++)
        {
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s == goal) return true;
        }
        
        return false;
    }
};
