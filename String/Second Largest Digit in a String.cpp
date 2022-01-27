// Url - https://leetcode.com/problems/second-largest-digit-in-a-string/

class Solution {
public:
    int secondHighest(string s) {
        int sl = -1, l = -1, flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int digit = s[i] - '0';
                if (flag == 0)
                {
                    l = digit;
                    flag = 1;
                }
                else
                {
                    if (digit > l)
                    {
                        int temp = l;
                        l = digit;
                        sl = temp;
                    }
                    else if (digit != l && digit > sl)
                    {
                        sl = digit;
                    }
                }
            }
        }
        
        return sl;
        
    }
};