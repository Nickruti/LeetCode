// url - https://leetcode.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        char tmp;
        int slen = s.size();
        for (int i = 0; i < slen/2; i++)
        {
            tmp = s[i];
            s[i] = s[slen - i - 1];
            s[slen - i - 1] = tmp;
        }

    }
};

