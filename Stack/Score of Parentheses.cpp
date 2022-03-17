// Url - https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        
        st.push(0);
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(') 
            {
                st.push(0);
            }
            else
            {  
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                
                if(temp1 == 0)
                {
                    temp1 = 1 + temp2;
                }
                else
                {
                    temp1 = (temp1 << 1) + temp2;
                }
                st.push(temp1);
            }
        }
        
        return st.top();
    }
};

