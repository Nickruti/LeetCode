// url - https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> ind;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                ind.push_back(i);
            }
        }
        
        int n = ind.size();
        for (int i = 0; i < n/2; i++)
        {
            char tmp = s[ind[i]];
            s[ind[i]] = s[ind[n - i - 1]];
            s[ind[n - i - 1]] = tmp;
        }
        
        return s;
        
    }
};
