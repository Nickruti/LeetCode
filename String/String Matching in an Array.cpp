class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> s;
        
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if (words[i].find(words[j]) != string::npos)
                {
                    s.insert(words[j]);
                }
                else if (words[j].find(words[i]) != string::npos)
                {
                    s.insert(words[i]);
                }
            }
        }
        
        vector<string> ans;
        ans.assign(s.begin(), s.end());
        return ans;
    }
};