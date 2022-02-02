// url - https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pLen = p.length(), sLen = s.length();
        vector<int> indexes;
        
        if (sLen < pLen) return indexes;
        
        int j;
        vector<int> pVec (26, 0);
        
        for(int i = 0; i < pLen; i++)
        {
            pVec[p[i] - 'a']++;
        }
        
        vector<int> tempVec (26, 0);
        for(int i = 0; i < s.length(); i++)
        {
            if (i == 0)
            {
                j = 0;
                 while(j < pLen)
                {   
                    tempVec[s[j] - 'a']++;
                    j++;
                }
            }
            else
            {
                j = i + pLen - 1;
                tempVec[s[i-1] - 'a']--;
                if (j < s.length())
                {
                    tempVec[s[j] - 'a']++;
                }
            }

            int flag = 0;
            for(int k = 0; k < 26; k++)
            {
                if (pVec[k] != tempVec[k])
                {
                    flag = 1;
                    break;
                }

            }

            if (flag == 0)
            {
                indexes.push_back(i);
            }
        }
        return indexes;
    }
};