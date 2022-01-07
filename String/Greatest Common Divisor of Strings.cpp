// Url - https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        int str1L = str1.length(), str2L = str2.length();
        if (str1L < str2L)
        {
            return gcdOfStrings(str2, str1);
        }        

        int lenS = str2L, lenL = str1L;
        while(lenS != 0)
        {
            int temp = lenS;
            lenS = lenL % lenS;
            lenL = temp;
        }
        
        string gcd = str1.substr(0, lenL);
        
        int i = str1L - 1, j = str2L - 1, k = lenL - 1;
        while (i > 0 || j > 0)
        {
            if (i && j)
            {
                if (str1[i] != gcd[k] || str2[j] != gcd[k])
                {
                    return "";        
                }
                i--;
                j--;             
            }
            else if (i)
            {
                if (str1[i] != gcd[k])
                {
                    return "";
                }
                i--;
            }
            k--;
            if (k == -1) 
                k = lenL - 1;
             
        }
        return gcd;
    }
};