// url - https://leetcode.com/problems/reverse-integer/

// using intermediate string - less efficient

class Solution {
public:
    int reverse(int x) {
        
        string s = to_string(x), ans;
        for (int i = s.length()-1; i >= 0; i--)
        {
            ans += s[i];
        }
        
        if (x < 0)
        {
            ans ='-' + ans;
        }
        
        return stol(ans) > INT_MAX or stol(ans) < INT_MIN ? 0 : stoi(ans);
    }
};

// using maths

