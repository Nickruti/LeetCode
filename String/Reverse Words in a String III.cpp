// Url - https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        string ans, temp;
        
        stringstream iss(s);
        while (iss >> temp)
        {
            reverse(temp.begin(), temp.end());
            ans.append(temp);
            ans.append(" ");
        }
        ans.pop_back();
        
        return ans;
    }
};
