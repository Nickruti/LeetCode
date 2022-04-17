// URL - https://leetcode.com/problems/baseball-game/

class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> st;
        
        for(int i = 0; i < ops.size(); i++)
        {
            if(ops[i] == "+")
            {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                st.push(num2);
                st.push(num1);
                st.push(num1 + num2);
                ans += num1 + num2;
            }
            else if(ops[i] == "C")
            {
                ans -= st.top();
                st.pop();
            }
            else if(ops[i] == "D")
            {
                st.push(st.top()*2);
                ans += st.top();
            }
            else
            {
                int temp = stoi(ops[i]);
                st.push(temp);
                ans += temp;
            }
        }
        
        return ans;
    }
};