// url - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

// Time Limit Exceeded, bUT a Solution
class Solution {
public:
    string removeDuplicates(string s) {
        
        if (s.length() == 1) return s;
        
        stack<char> stack;
        
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!stack.empty() && stack.top() == s[i])
            {
                stack.pop();
            }
            else
            {
                stack.push(s[i]);
            }           
        }
        
        string ans = "";
        while (!stack.empty())
        {
            ans = ans + stack.top();
            stack.pop();
        }
        
        return ans;
    }
};
