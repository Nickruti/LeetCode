// url - https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        
        int ans = -1;
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[0])
            {
                // cout << haystack[i] << "\n";
                ans = i;
                int temp = i, j = 0;
                for (j = 0; j < needle.length(); j++)
                {
                    if (haystack[temp] != needle[j])
                    {
                        ans = -1;
                        break;
                    }
                    temp++;
                }
                if (j == needle.length())
                {
                    return ans;
                }
            }
        }
       return ans; 
    }
};

// Url - https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        
        int n = needle.length();
        
        int lps[n];
        lps[0] = 0;
        int len = 0;
        
        int i = 1;
        while(i < n)
        {
            if (needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }   
                else
                {
                    lps[i] = 0;
                    i++;
                }       
            }
            
        }
        
        int j = 0;
        i = 0;
        
        while (i < haystack.length())
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            if (j == n)
            {
                return (i - j);
            }
            else if (haystack[i] != needle[j])
            {
                if (j > 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return -1;
    }
};
