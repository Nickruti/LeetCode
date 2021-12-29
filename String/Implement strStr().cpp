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
