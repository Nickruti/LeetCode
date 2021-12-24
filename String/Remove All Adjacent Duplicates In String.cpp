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

// Just Changed ans = ans + stack.top() --> ans.push_back(st.top()). Solution Accepted.

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> st;
        
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }           
        }
        
        string ans = "";
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};
