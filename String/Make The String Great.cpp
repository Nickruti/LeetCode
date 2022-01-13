// url - https://leetcode.com/problems/make-the-string-great/

// Using Stack 

class Solution {
public:
    string makeGood(string s) {
        
        if (s.length() <= 1) return s;
        
        stack<char> st;
        
        int i = 0;
        
        while (i < s.length())
        {
            if (!st.empty() && abs(st.top() - s[i]) == 32)
            {
                st.pop(); 
            }
            else
            {
                st.push(s[i]);
            }
            i++;
        }
        
        string ans = "";
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
    
        return string(ans.rbegin(),ans.rend());
        
    }
};

// Using Just String in form of STack

class Solution {
public:
    string makeGood(string s) {
        
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(ans.length() == 0 || s[i] == ans.back() || toupper(s[i]) != toupper(ans.back()))
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
        
    }
};
