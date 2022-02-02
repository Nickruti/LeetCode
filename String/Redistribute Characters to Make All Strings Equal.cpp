// Url - https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> countsOfAlphabets;
        int wordsLen = words.size();
        
        for(int i = 0; i < wordsLen; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                countsOfAlphabets[words[i][j]]++;
            }
        }
        
        for(auto it:countsOfAlphabets)
        {
            if (it.second % wordsLen != 0)
            {
                return false;
            }
        }
        return true;
    }
};