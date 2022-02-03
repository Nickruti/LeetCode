// Url - https://leetcode.com/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        
        int i = s.length() - 1;
        string ans = "";
        stack<char> st;

        while(i >= 0)
        {
            if (s[i] == ']' || !st.empty())
            {
                while(s[i] != '[')
                {
                    st.push(s[i]);
                    i--;
                }
                i--;
                
                string digit = "";
                while( i >= 0 && (s[i] - '0') <= 9)
                {
                    digit += s[i];
                    i--;
                }

                reverse(digit.begin(), digit.end());
                string currDecodedStr = "";
                
                while (st.top() != ']')
                {
                    currDecodedStr += st.top();
                    st.pop();
                }
                st.pop();
                
                if(!st.empty())
                {
                    string temp = "";
                    for(int j = 0; j < (stoi(digit)); j++)
                    {
                        temp = currDecodedStr + temp;  
                    }
                    reverse(temp.begin(), temp.end());
                    
                    for(int j = 0; j < temp.length(); j++)
                    {
                        st.push(temp[j]);  
                    }
                }
                else
                {
                   for(int j = 0; j < (stoi(digit)); j++)
                    {
                        ans = currDecodedStr + ans;  
                    } 
                }
            }
            else
            {
                ans = s[i] + ans;
                i--;
            }
            
        }
        return ans;
    }
};