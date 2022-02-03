// Url - https://leetcode.com/problems/unique-substrings-in-wraparound-string/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int ans = 1, preValue, subLen = 1;
        vector<int> visited(26, 0);
        
        preValue = p[0] - 'a';
        visited[preValue] = 1;
        
        for (int i = 1; i < p.length(); i++)
        {
            if(((p[i] - 'a') - preValue == 1) || (preValue - (p[i] - 'a') == 25))
            {
                subLen++;
            }
            else
            {
                subLen = 1;
            }
            
            if(subLen > visited[p[i] - 'a'])
            {
                ans += subLen - visited[p[i] - 'a'];
                visited[p[i] - 'a'] = subLen;
            }
            preValue = p[i] - 'a';
        }
        
        return ans;
    }
};