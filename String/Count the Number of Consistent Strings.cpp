// Url - https://leetcode.com/problems/count-the-number-of-consistent-strings/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int cnt = words.size();
        int isPresent[26] = {0};
        
        for (int i = 0; i < allowed.size(); i++)
        {
            isPresent[allowed[i] - 'a'] = 1;
        }
        
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                if (!isPresent[words[i][j] - 'a'])
                {
                    cnt--;
                    break;
                }
            }
        }
        
        return cnt;
    }
};

// Second Solution

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = words.size();
        
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].length(); j++)
            {
                if (allowed.find(words[i][j]) == string::npos)
                {
                    cnt--;
                    break;
                }
            }
        }
        
        return cnt;
    }
};