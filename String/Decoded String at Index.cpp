// url - https://leetcode.com/problems/decoded-string-at-index/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int N = s.size();

        // Find size = length of decoded string
        for (int i = 0; i < N; ++i) {
            if (isdigit(s[i]))
                size *= s[i] - '0';
            else
                size++;
        }

        for (int i = N-1; i >=0; --i) {
            k %= size;
            if (k == 0 && isalpha(s[i]))
                return (string) "" + s[i];

            if (isdigit(s[i]))
                size /= s[i] - '0';
            else
                size--;
        }
        return "";
    }
};