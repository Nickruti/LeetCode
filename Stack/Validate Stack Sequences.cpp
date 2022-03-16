// url - https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int i = 0;

        for(int j = 0; j < popped.size(); j++)
        {
            if(!st.empty() && popped[j] == st.top())
            {
                st.pop();
            }
            else if(i < pushed.size() && popped[j] == pushed[i])
            {
                i++;
            }
            else
            {
                if(i >= pushed.size())
                {
                    return false;
                }
                
                while(i < pushed.size() && pushed[i] != popped[j])
                {
                    st.push(pushed[i]);
                    i++;
                }
                i++;
            }
        }
        
        return st.empty();
    }
};