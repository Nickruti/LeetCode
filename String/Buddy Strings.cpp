// Url - https://leetcode.com/problems/buddy-strings/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) return false;
        
        int positiveEnergy = 0, pos = -99, flag = 0;
        unordered_map<char, int> v;
        
        for (int i = 0; i < s.length(); i++)
        {
            // cout << "s : " << s[i] << " goal : " << goal[i] << "\n";
            if (s[i] != goal[i])
            {
                if (flag == 0)
                {
                    pos = i;
                    //  cout << "positiveEnergy : " << positiveEnergy << "\n";
                    flag = 1;
                }
                else if (flag == 1)
                {
                    if (s[pos] == goal[i] && goal[pos] == s[i]) 
                    {
                        positiveEnergy = 1;
                        pos = -2;
                    }                  
                    else 
                        return false;
                    flag = 2;
                }
                else 
                    return false; 
            }
            else
            {
                v[s[i]]++;
            }
        }
        
        if (flag == 0)
        {
            for (auto it:v)
            {
                if (it.second >= 2) return true;
            }
        }
        
        
        if (positiveEnergy == 1 && pos == -2)
            return true;
        return false;
        
    }
};
